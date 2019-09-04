/* 
 Soil Moisture Sensor  
 Trahan, A
 04 Sep 19
*/

// Pin Definitions
#define SensorPin A0

// Variable Definitions
float sensorValue = 0;
float dryValue = 600;
float wetValue = 400;

// Initialize
void setup() { 
 Serial.begin(9600); 
} 

// Run
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 delay(30); 
} 
