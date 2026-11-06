
#define BLYNK_TEMPLATE_ID   "TMPL3pQ61r8Ex"
#define BLYNK_TEMPLATE_NAME "ConveyorTech"
#define BLYNK_AUTH_TOKEN    "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace these placeholders with your own credentials locally
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// --- Pin Allocations ---
const int PIN_ENA = 25;
const int PIN_IN1 = 26;
const int PIN_IN2 = 27;

const int PIN_MCSA_CURRENT = 34;
const int PIN_MCSA_VOLTAGE = 32;
const int PIN_MFL_HALL     = 35;

// Calibration & Scaling
const float ADC_REF_VOLTAGE         = 3.3;
const float ADC_RESOLUTION          = 4095.0;
const float HALL_DIVIDER_RATIO      = 30.0 / 20.0;
const float SENSITIVITY_V_PER_GAUSS = 0.003125;

BlynkTimer timer;

void runMotor() {
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_ENA, HIGH);
}

// MCSA computation (25 ms sampling window)
void pushMCSA() {
  if (!Blynk.connected()) return;

  unsigned long start = millis();
  unsigned long samples = 0;
  float sumSqCurrent = 0.0;
  float sumVoltage = 0.0;
  float maxCurrent = 0.0;

  while (millis() - start < 25) {
    int rawCurrent = analogRead(PIN_MCSA_CURRENT);
    int rawVoltage = analogRead(PIN_MCSA_VOLTAGE);

    float vCurrent = (rawCurrent / ADC_RESOLUTION) * ADC_REF_VOLTAGE;
    float vSupply  = (rawVoltage / ADC_RESOLUTION) * ADC_REF_VOLTAGE;

    float instCurrent = abs((vCurrent - 1.65) / 0.033);

    if (instCurrent > maxCurrent)
      maxCurrent = instCurrent;

    sumSqCurrent += instCurrent * instCurrent;
    sumVoltage += vSupply;
    samples++;
  }

  if (samples == 0) return;

  float currentRms = sqrt(sumSqCurrent / samples);
  float busVoltage = (sumVoltage / samples) * (100.0 / ADC_REF_VOLTAGE);

  Blynk.virtualWrite(V0, currentRms);
  Blynk.virtualWrite(V1, maxCurrent);
  Blynk.virtualWrite(V5, busVoltage);
}

// MFL computation (15 ms sampling window)
void pushMFL() {
  if (!Blynk.connected()) return;

  unsigned long start = millis();
  int minRaw = 4095;
  int maxRaw = 0;
  int samples = 0;

  while (millis() - start < 15) {
    int val = analogRead(PIN_MFL_HALL);

    if (val < minRaw) minRaw = val;
    if (val > maxRaw) maxRaw = val;

    samples++;
  }

  if (samples == 0) return;

  float vMin = (minRaw / ADC_RESOLUTION) * ADC_REF_VOLTAGE * HALL_DIVIDER_RATIO;
  float vMax = (maxRaw / ADC_RESOLUTION) * ADC_REF_VOLTAGE * HALL_DIVIDER_RATIO;

  float mflAmplitude = (vMax - vMin) / 2.0;
  float mflMetric = mflAmplitude / SENSITIVITY_V_PER_GAUSS;

  if (mflMetric > 500.0)
    mflMetric = 500.0;

  Blynk.virtualWrite(V2, mflAmplitude);
  Blynk.virtualWrite(V3, mflMetric);
}

void checkWiFiAndBlynk() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect();
    WiFi.reconnect();
  }
  else if (!Blynk.connected()) {
    Blynk.connect();
  }
}

void setup() {
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);

  runMotor();

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  // Disable modem sleep to reduce network latency
  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Blynk.config(BLYNK_AUTH_TOKEN, "blynk.cloud", 80);

  // Interleaved sampling timers
  timer.setInterval(200L, pushMCSA);
  timer.setInterval(250L, pushMFL);
  timer.setInterval(5000L, checkWiFiAndBlynk);
}

void loop() {
  runMotor();

  if (Blynk.connected()) {
    Blynk.run();
  }

  timer.run();
}
