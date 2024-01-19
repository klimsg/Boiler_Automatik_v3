#pragma once
#include <Arduino.h>
#define S0 14
#define S1 15
#define S2 16
#define S3 17 



class Switch{
    public:
            Switch(unsigned char pin_multiplex, unsigned char analog_pin_Switch){
                this->pin_multiplex = pin_multiplex;
                this->analog_pin_Switch = analog_pin_Switch;
                }
        unsigned char pin_multiplex;
        unsigned char analog_pin_Switch;
        unsigned int condition;
                
        void reed_Switch(){
            pinMode(S0, OUTPUT); 
            pinMode(S1, OUTPUT); 
            pinMode(S2, OUTPUT); 
            pinMode(S3, OUTPUT);
            bool all_pin_multiplex[16][4]={
                {0,0,0,0}, //pin_multiplex 0
                {1,0,0,0}, //pin_multiplex 1
                {0,1,0,0}, //pin_multiplex 2
                {1,1,0,0}, //pin_multiplex 3
                {0,0,1,0}, //pin_multiplex 4
                {1,0,1,0}, //pin_multiplex 5
                {0,1,1,0}, //pin_multiplex 6
                {1,1,1,0}, //pin_multiplex 7
                {0,0,0,1}, //pin_multiplex 8
                {1,0,0,1}, //pin_multiplex 9
                {0,1,0,1}, //pin_multiplex 10
                {1,1,0,1}, //pin_multiplex 11
                {0,0,1,1}, //pin_multiplex 12
                {1,0,1,1}, //pin_multiplex 13
                {0,1,1,1}, //pin_multiplex 14
                {1,1,1,1}  //pin_multiplex 15
                };

            digitalWrite(S0, all_pin_multiplex[pin_multiplex][0]);
            digitalWrite(S1, all_pin_multiplex[pin_multiplex][1]);
            digitalWrite(S2, all_pin_multiplex[pin_multiplex][2]);
            digitalWrite(S3, all_pin_multiplex[pin_multiplex][3]);

            condition = analogRead(analog_pin_Switch);
            if (condition >= 800)
            {
                condition = ON;
            }
            else if (301 < condition && condition < 800)
            {
                condition = OFF;
            }
            else
            {
                condition = UNCONNECTED;
            }
            };
    };