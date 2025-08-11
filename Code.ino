#include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

//#include <WiFi.h>
//#include <HTTPClient.h>

#define MQ135_PIN 34       // Analog input pin
#define THRESHOLD 100      // Adjust based on your testing
#define DURATION 30000     // Half minute in milliseconds

const char* ssid = "your_wifi"; // put wifi name here
const char* password = "password"; // password here

String BOT_TOKEN = "bot token"; // Bot token here from telegram
String CHAT_ID_1 = "000000"; // See for chat id's from telegram
String CHAT_ID_2 = "000000"; // ''

unsigned long startTime = 0;
bool gasDetected = false;
bool messageSent = false;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected!");
  Serial.println("💩 Poop Detection System Started");
}

void loop() {
  int gasValue = analogRead(MQ135_PIN);
  Serial.print("Gas Reading: ");
  Serial.println(gasValue);

  if (gasValue > THRESHOLD) {
    if (!gasDetected) {
      gasDetected = true;
      startTime = millis();
      Serial.println("⚠️ Gas spike started...");
    } else {
      if (millis() - startTime >= DURATION && !messageSent) {
        Serial.println("💩 Poop CONFIRMED! SMELL PERSISTED > 30 SECONDS!");
        sendTelegramMessage("💩 Poop detected in the diaper! Smell lasted over a half minute.");
        messageSent = true;
        delay(30000);  // Prevent repeated messages for 30s
        gasDetected = false;
      }
    }
  } else {
    if (gasDetected) {
      Serial.println("🚫 False alarm — likely just fart!");
    }
    gasDetected = false;
    messageSent = false;
  }

  delay(1000);  // 1 second delay between readings
}

void sendTelegramMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Send to Chat ID 1
    String url1 = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage?chat_id=" + CHAT_ID_1 + "&text=" + message;
    http.begin(url1);
    int httpCode1 = http.GET();
    http.end();

    // Send to Chat ID 2
    String url2 = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage?chat_id=" + CHAT_ID_2 + "&text=" + message;
    http.begin(url2);
    int httpCode2 = http.GET();
    http.end();

    if (httpCode1 > 0 && httpCode2 > 0) {
      Serial.println("✅ Telegram messages sent to both users!");
    } else {
      Serial.println("❌ Failed to send to one or both chat IDs.");
    }
  } else {
    Serial.println("❌ WiFi not connected!");
  }
}
