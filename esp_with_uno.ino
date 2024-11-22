#define BLYNK_TEMPLATE_ID "TMPL6ptz2rrNK"
#define BLYNK_TEMPLATE_NAME "led on off"
#define BLYNK_AUTH_TOKEN "3oHK44YHtqFhSWI7UrIWc1xAVVW0dZHu"
#define BLYNK_Print Serial
#define ledPin 2
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your network credentials
const char* ssid = "Web Hunters"; // Your Wi-Fi SSID
const char* pass = "@password690@"; // Your Wi-Fi password

void setup() {
    Serial.begin(9600); // Start serial communication for debugging
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
    pinMode(ledPin, OUTPUT);
}

void loop() {
    Blynk.run();
}

BLYNK_WRITE(V0) {
    int pinValue = param.asInt(); // Get value from button widget
    Serial.println(pinValue);
    if (pinValue == 1) {
      digitalWrite(ledPin, HIGH); // Turn LED ON or OFF based on button state
    } else {
      digitalWrite(ledPin, LOW);
    }
}