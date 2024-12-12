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
