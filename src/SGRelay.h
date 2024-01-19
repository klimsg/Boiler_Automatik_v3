#pragma once
#include <Arduino.h>


class Relay{
    public:
            Relay(unsigned char pin_Relay){
                this->pin_Relay = pin_Relay;
                }
        unsigned char pin_Relay;
        unsigned char relay;     

        void Switch_ON(){
            Relay::relay = ON;
            pinMode(pin_Relay, OUTPUT); 
            digitalWrite(pin_Relay, ON);
            };

        void Switch_OFF(){
            Relay::relay = OFF;
            pinMode(pin_Relay, OUTPUT); 
            digitalWrite(pin_Relay, OFF);
            };
    };