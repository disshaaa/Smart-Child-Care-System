# Smart Child Care System

An IoT-based **Smart Child Care System** designed to monitor ammonia gas levels in diapers using an **MQ-135 gas sensor** connected to an **ESP32**. The system sends **real-time alerts via Telegram** to notify caregivers when ammonia levels exceed a safe threshold, helping ensure the comfort and health of infants.

---

## Features
- **Real-time monitoring** of ammonia-based gases.
- **Instant alerts** via Telegram Bot API.
- **Low-power ESP32** microcontroller for portability.
- Easy-to-build, low-cost, and scalable design.

---

## Hardware Requirements
- **ESP32 Development Board**
- **MQ-135 Gas Sensor**
- Jumper Wires
- Breadboard
- Power Source (5V via USB or regulated power supply)

---

## Software Requirements
- **Arduino IDE** (with ESP32 board support)
- **Telegram Bot** and Chat ID
- Internet connection (Wi-Fi)

---

## Circuit Diagram
1. Connect **VCC** of MQ-135 to **3.3V** pin of ESP32.
2. Connect **GND** of MQ-135 to **GND** of ESP32.
3. Connect **AO (Analog Out)** of MQ-135 to **GPIO34 (Analog Pin)** of ESP32.

---

## Getting Started

### 1. Create a Telegram Bot
1. Open **Telegram** and search for `BotFather`.
2. Type `/start` and then `/newbot`.
3. Give your bot a name and username (must end with `_bot`).
4. Copy the **Bot Token** you receive — you will use it in the code.

---

### 2. Get Your Telegram Chat ID
1. Open **Telegram** and search for `userinfobot` (or any similar bot like `RawDataBot`).
2. Start the bot and type `/start`.
3. The bot will reply with your **Chat ID**.
4. Paste this **Chat ID** into your Arduino code in the `chat_id` variable.

---

### 3. Install Required Libraries in Arduino IDE
Go to **Sketch → Include Library → Manage Libraries** and install:
- **WiFi**
- **WiFiClientSecure**
- **UniversalTelegramBot**
- **ArduinoJson**

---

### 4. Update the Code
In your Arduino sketch:
```cpp
#define WIFI_SSID "YourWiFiName"
#define WIFI_PASSWORD "YourWiFiPassword"
#define BOT_TOKEN "YourBotToken"
#define CHAT_ID "YourChatID"
```

---

### 5. Upload to ESP32
- Connect ESP32 to your PC.
- Select the correct Board and Port in Arduino IDE.
- Upload the code.
- Open the Serial Monitor to check connection logs.

---

## How It Works
- The MQ-135 sensor continuously monitors air quality.
- When ammonia concentration exceeds a set threshold, ESP32 sends a Telegram message to the caregiver.
- Alerts are received instantly on any device with Telegram.

---

## Example Alert

🚨 Smart Child Care System: Ammonia gas detected at unsafe levels. Please check the diaper.

---

## Future Enhancements
- Add temperature and humidity monitoring.
- Mobile app dashboard for live data.
- Low-battery notifications.

---

## License

This project is licensed under the MIT License. You are free to use and modify it for personal and educational purposes.

