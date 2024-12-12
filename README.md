# Water-Level-Automation
This project automates water level management using an ultrasonic sensor and a relay module. The relay automatically turns the water pump ON or OFF based on water level readings. Alerts are displayed in the serial monitor for low and full water levels.
# 🚰 Water Level Automation Using Ultrasonic Sensor and Relay

## 📜 Project Description

This project automates the water pump operation using an ultrasonic sensor and a relay. The pump turns **OFF** when the water reaches a high level and **ON** when the water level drops below a set threshold. The system also provides alerts through the serial monitor for low and full water levels.
# 🚰 Water Level Automation Using Ultrasonic Sensor and Relay


## 🛠️ Components Required

1. **Arduino Uno**  
2. **Ultrasonic Sensor (HC-SR04)**  
3. **Relay Module**  
4. **Jumper Wires**  
5. **Breadboard**  
6. **Water Pump (Optional for Full Setup)**  

---

## 📐 Circuit Diagram

1. **Ultrasonic Sensor Connections:**
    - **Trigger Pin:** Digital Pin 7  
    - **Echo Pin:** Digital Pin 6  
    - **VCC:** 5V  
    - **GND:** GND  

2. **Relay Module Connections:**
    - **Control Pin:** Digital Pin 8  
    - **VCC:** 5V  
    - **GND:** GND  

---

## 💻 Code

```cpp
/* 
 * Project: Water Level Automation using Ultrasonic Sensor and Relay
 * Author: Pravin Sinh Rana
 * Contact: 9313057803
 * Instagram: @S.T.C_CREATIVE_CLUB
 *
 * Description:
 * This code automates the water pump using an ultrasonic sensor and a relay.
 * The relay turns OFF when water reaches a high level and ON when water level drops.
 * Additionally, it shows alerts for low and full water levels.
 */

// Pin Definitions
const int triggerPin = 7; // Ultrasonic Sensor Trigger Pin
const int echoPin = 6;    // Ultrasonic Sensor Echo Pin
const int relayPin = 8;   // Relay Control Pin

// Threshold Distances (in cm) for Relay Control
const int highLevelThreshold = 7;  // High Level (Tank Full)
const int lowLevelThreshold = 20;  // Low Level (Tank Empty)

// Variables
long duration; // Stores the time taken by ultrasonic waves
int distance;  // Stores the calculated distance

void setup() {
  // Branding Serial Monitor
  Serial.begin(9600);
  Serial.println("*************");
  Serial.println("*  Welcome to STC Creative Club  *");
  Serial.println("*  Water Level Automation Project *");
  Serial.println("*      By: Pravin Sinh Rana       *");
  Serial.println("*      Contact: 9313057803        *");
  Serial.println("*  Instagram: @S.T.C_CREATIVE_CLUB *");
  Serial.println("*************");

  // Pin Modes
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relay initially OFF
}

void loop() {
  // Generate Ultrasonic Pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure Echo Time
  duration = pulseIn(echoPin, HIGH);

  // Calculate Distance (in cm)
  distance = duration * 0.034 / 2;

  // Print Distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Relay Control Logic with Alerts
  if (distance <= highLevelThreshold) {
    digitalWrite(relayPin, HIGH); // Turn OFF Relay
    Serial.println("Tank Full - Relay OFF");
    Serial.println("⚠️ High Level Alert: Paani Bhar Gaya!");
  } 
  else if (distance >= lowLevelThreshold) {
    digitalWrite(relayPin, LOW); // Turn ON Relay
    Serial.println("Tank Empty - Relay ON");
    Serial.println("⚠️ Low Level Alert: Paani Khatam Ho Gaya!");
  } 
  else {
    Serial.println("Water Level Normal");
  }

  delay(1000); // Delay for stability
}



📊 Sample Serial Monitor Output
    
*************
*  Welcome to STC Creative Club  *
*  Water Level Automation Project *
*      By: Pravin Sinh Rana       *
*      Contact: 9313057803        *
*  Instagram: @S.T.C_CREATIVE_CLUB *
*************
Distance: 6 cm
Tank Full - Relay OFF
⚠️ High Level Alert: Paani Bhar Gaya!




Yeh raha aapke project ke liye well-arranged README.md file jisme alag-alag sections clear aur structured hain. Isko aap seedha apne repository mein paste kar sakte hain.

📄 README.md for Water Level Automation Project
markdown
Copy code
# 🚰 Water Level Automation Using Ultrasonic Sensor and Relay

## 📜 Project Description

This project automates the operation of a water pump using an **ultrasonic sensor** and a **relay module**. The system monitors the water level in a tank and controls the relay to turn the pump **ON** or **OFF** based on the water level. Additionally, alerts are displayed on the **serial monitor** when the water level is too low or when the tank is full.

---

## 🛠️ Components Required

1. **Arduino Uno**  
2. **Ultrasonic Sensor (HC-SR04)**  
3. **Relay Module**  
4. **Jumper Wires**  
5. **Breadboard**  
6. **Water Pump (Optional for Full Setup)**  

---

## 📐 Circuit Diagram

1. **Ultrasonic Sensor Connections:**
    - **Trigger Pin:** Digital Pin 7  
    - **Echo Pin:** Digital Pin 6  
    - **VCC:** 5V  
    - **GND:** GND  

2. **Relay Module Connections:**
    - **Control Pin:** Digital Pin 8  
    - **VCC:** 5V  
    - **GND:** GND  

---

## 💻 Code

```cpp
/* 
 * Project: Water Level Automation using Ultrasonic Sensor and Relay
 * Author: Pravin Sinh Rana
 * Contact: 9313057803
 * Instagram: @S.T.C_CREATIVE_CLUB
 *
 * Description:
 * This code automates the water pump using an ultrasonic sensor and a relay.
 * The relay turns OFF when water reaches a high level and ON when water level drops.
 * Additionally, it shows alerts for low and full water levels.
 */

// Pin Definitions
const int triggerPin = 7; // Ultrasonic Sensor Trigger Pin
const int echoPin = 6;    // Ultrasonic Sensor Echo Pin
const int relayPin = 8;   // Relay Control Pin

// Threshold Distances (in cm) for Relay Control
const int highLevelThreshold = 7;  // High Level (Tank Full)
const int lowLevelThreshold = 20;  // Low Level (Tank Empty)

// Variables
long duration; // Stores the time taken by ultrasonic waves
int distance;  // Stores the calculated distance

void setup() {
  // Branding Serial Monitor
  Serial.begin(9600);
  Serial.println("*************");
  Serial.println("*  Welcome to STC Creative Club  *");
  Serial.println("*  Water Level Automation Project *");
  Serial.println("*      By: Pravin Sinh Rana       *");
  Serial.println("*      Contact: 9313057803        *");
  Serial.println("*  Instagram: @S.T.C_CREATIVE_CLUB *");
  Serial.println("*************");

  // Pin Modes
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relay initially OFF
}

void loop() {
  // Generate Ultrasonic Pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure Echo Time
  duration = pulseIn(echoPin, HIGH);

  // Calculate Distance (in cm)
  distance = duration * 0.034 / 2;

  // Print Distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Relay Control Logic with Alerts
  if (distance <= highLevelThreshold) {
    digitalWrite(relayPin, HIGH); // Turn OFF Relay
    Serial.println("Tank Full - Relay OFF");
    Serial.println("⚠️ High Level Alert: Paani Bhar Gaya!");
  } 
  else if (distance >= lowLevelThreshold) {
    digitalWrite(relayPin, LOW); // Turn ON Relay
    Serial.println("Tank Empty - Relay ON");
    Serial.println("⚠️ Low Level Alert: Paani Khatam Ho Gaya!");
  } 
  else {
    Serial.println("Water Level Normal");
  }

  delay(1000); // Delay for stability
}
📊 Sample Serial Monitor Output
markdown
Copy code
*************
*  Welcome to STC Creative Club  *
*  Water Level Automation Project *
*      By: Pravin Sinh Rana       *
*      Contact: 9313057803        *
*  Instagram: @S.T.C_CREATIVE_CLUB *
*************
Distance: 6 cm
Tank Full - Relay OFF
⚠️ High Level Alert: Paani Bhar Gaya!



🔧 How to Upload Code to Arduino
Connect your Arduino Uno to the computer using a USB cable.
Open the Arduino IDE and paste the above code.
Select the correct Board (Arduino Uno) and Port in the Tools menu.
Click the Upload button to flash the code to the Arduino.



        
