#pragma once
#include <Arduino.h>

enum {
    OFF = 0,
    ON = 1,
    UNCONNECTED = 2
    };

class Relay{
    public:
            Relay(unsigned char pin_Relay){
                this->pin_Relay = pin_Relay;
                }
        unsigned char pin_Relay;
        unsigned char relay;     

        void ON_Switch(){
            Relay::relay = ON;
            pinMode(pin_Relay, OUTPUT); 
            digitalWrite(pin_Relay, ON);
            };

        void OFF_Switch(){
            Relay::relay = OFF;
            pinMode(pin_Relay, OUTPUT); 
            digitalWrite(pin_Relay, OFF);
            };
    };