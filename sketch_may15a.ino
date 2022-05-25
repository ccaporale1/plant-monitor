// Interfacing Arduino uno with LDR sensor
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
const int ldrPin = A1; // analog pin 1
const int moisturePin = A3;
const int tempHumPin = A5;
int val;

void setup() { //  Void setup function will only run once, after each powerup or reset of the Arduino board.
  
  Serial.begin(9600);
  pinMode(ldrPin, INPUT); // Here LDR sensor is determined as input.
  pinMode(moisturePin, INPUT); // Here LDR sensor is determined as input.
  dht.begin();

}

void loop() { // Void loop is ran again and again and contains main code.
  getLight();
  getMoisture();
  getTemp();
  getHumidity();

}

void getLight () {
  val = analogRead(ldrPin);
  Serial.println("Light:");
  Serial.println(val);
}

void getMoisture () {
  val = analogRead(moisturePin);
  Serial.println("Moisture:");
  Serial.println(val);
}

void getTemp () {
  float t = dht.readTemperature();  
  float f = dht.readTemperature(true);

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}

void getHumidity () {
  
  float h = dht.readHumidity();        // read humidity
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  
}
