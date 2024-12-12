# Water-Level-Automation
This project automates water level management using an ultrasonic sensor and a relay module. The relay automatically turns the water pump ON or OFF based on water level readings. Alerts are displayed in the serial monitor for low and full water levels.
# 🚰 Water Level Automation Using Ultrasonic Sensor and Relay

## 📜 Project Description

This project automates the water pump operation using an ultrasonic sensor and a relay. The pump turns **OFF** when the water reaches a high level and **ON** when the water level drops below a set threshold. The system also provides alerts through the serial monitor for low and full water levels.

## 🛠️ Components Used

1. **Arduino Uno**  
2. **Ultrasonic Sensor (HC-SR04)**  
3. **Relay Module**  
4. **Wires and Breadboard**  

## 📝 Code Overview

### Key Functionalities:

- **Distance Measurement:**  
  Measures the water level using the ultrasonic sensor.

- **Relay Control:**  
  Turns the pump ON/OFF based on predefined water levels.

- **Alerts:**  
  Displays alerts on the serial monitor for:
  - High Level (Tank Full)  
  - Low Level (Tank Empty)  

## 🚦 Thresholds:

- **High Level Threshold:** 7 cm  
- **Low Level Threshold:** 20 cm  

## 📲 Serial Monitor Output:

