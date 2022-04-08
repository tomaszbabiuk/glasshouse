/*
  Debug.cpp - Library for debug messages
*/

#ifndef Debug_h
#define Debug_h

#include <Arduino.h>

class DebugLog
{
  public:
    static void init(uint8_t debugLevel);
    static void debug(const char* message);
    static void debugHex(uint8_t hex);
    static void counter(const char* message, long counter);
    static void sensorValue(const char* message, int value);
    static void property(const char* name, const char* value);
    static void info(const char* message);
    static void error(const char* message);
};



#endif
