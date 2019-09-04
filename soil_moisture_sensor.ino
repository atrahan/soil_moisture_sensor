/*
 Soil Moisture Sensor
 Trahan, A
 04 Sep 19
*/

// Pin Definitions
#define SensorPin A0
#define PhotoResPin A1
#define BuzzzerPin 8
#define LedPin 7

// Variable Definitions
float sensorValue = 0.0;
float photoValue = 0.0;
float ledThresh = 475;
float buzzThresh = 550;
int t = 0;
int dt = 1e3;

// Initialize
void setup() {
 Serial.begin(9600);
 pinMode(LedPin, OUTPUT);
}

// Run
void loop() {
 // Take average of 50 sensor readings for soil moisture and photo
 for (int i = 0; i <= 50; i++)
 { 
   sensorValue = sensorValue + analogRead(SensorPin);
   photoValue = photoValue + analogRead(PhotoResPin);
   delay(1);
 }
 sensorValue = sensorValue/50.0;
 photoValue = photoValue/50.0;

  // If very dry, blink (always) and buzz (slowly, and only if lights are on)
  if (sensorValue > buzzThresh) {
    if (photoValue > 60 && t>=1e4) {
      tone(BuzzzerPin, 440, 50);
      t = 0;
    }
    digitalWrite(LedPin, !digitalRead(LedPin));
  }
  // If somewhat dry, turn on LED
  else if (sensorValue > ledThresh) {
    digitalWrite(LedPin, 1);
  }
  // If wet enough, turn off LED
  else {
    digitalWrite(LedPin, 0);
  }

 // Print values to console for debugging
 Serial.print(sensorValue);
 Serial.print("\t");
 Serial.println(photoValue);

 // Increment timer for slow buzzer
 t = t + dt;
 delay(dt);
}
