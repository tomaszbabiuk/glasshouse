#include <Arduino.h>
#include <DebugLog.h>
#include <Relay.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


#define USER_LED_PIN 13
#define RELAY_AND_RED_LED_PIN 12
#define JACKPIN  14
#define DHTTYPE DHT21

DHT _dht(JACKPIN, DHTTYPE);
Relay _relay(RELAY_AND_RED_LED_PIN);
Relay _led(USER_LED_PIN);

void setup() {
  _dht.begin();
  DebugLog::init(0);
  DebugLog::info("Starting GLASSHOUSE project\n");
}

void loop() {
  float h = _dht.readHumidity();
  float t = _dht.readTemperature();

  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("°C"));

  if (t<7.0) {
    _relay.on();
  } else {
    _relay.off();
  }

  if (t>1) {
    for (int i = 0; i < t; i++) {
        delay(250);
        _led.off();

          delay(250);
        _led.on();
    }
  }

  delay(5000);
}