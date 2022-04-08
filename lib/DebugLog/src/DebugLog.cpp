#include <Arduino.h>
#include "DebugLog.h"

//LEVELS:
// 0 - Debug
// 1 - info
// 2 - warning
// 3 - error
static uint8_t DebugLevel = 0;

void DebugLog::init(uint8_t debugLevel) {
  #if defined(H801) || defined(H802)
    Serial1.begin(9600);
  #else
    Serial.begin(9600);
  #endif
  DebugLevel = debugLevel;
}

void DebugLog::debug(const char * message) {
  if (DebugLevel < 1) {
    #if defined(H801) || defined(H802)
      Serial1.printf(message);
    #else
      Serial.printf(message);
    #endif
  }
}

void DebugLog::debugHex(uint8_t hex) {
  #if defined(H801) || defined(H802)
    Serial1.printf("%02X ", hex);
  #else
    Serial.printf("%02X ", hex);
  #endif
}

void DebugLog::counter(const char * message, long counter) {
  if (DebugLevel < 1) {
    #if defined(H801) || defined(H802)
      Serial1.printf("%s: %d\n", message, counter);
    #else
      Serial.printf("%s: %d\n", message, counter);
    #endif
  }
}

void DebugLog::sensorValue(const char * message, int value) {
  if (DebugLevel < 1) {
    #if defined(H801) || defined(H802)
      Serial1.printf("%s: %d\n", message, value);
    #else
      Serial.printf("%s: %d\n", message, value);
    #endif
  }
}

void DebugLog::info(const char * message) {
  if (DebugLevel < 2) {
    #if defined(H801) || defined(H802)
      Serial1.printf(message);
    #else
      Serial.printf(message);
    #endif
  }
}

void DebugLog::property(const char* name, const char* value) {
  if (DebugLevel < 1) {
    #if defined(H801) || defined(H802)
      Serial1.printf("%s: %s\n", name, value);
    #else
      Serial.printf("%s: %s\n", name, value);
    #endif
  }
}

void DebugLog::error(const char * message) {
  if (DebugLevel < 3) {
    #if defined(H801) || defined(H802)
      Serial1.printf(message);
    #else
      Serial.printf(message);
    #endif
  }
}
