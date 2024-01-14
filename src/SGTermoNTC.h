#include <Arduino.h>
#define S0 14
#define S1 15
#define S2 16
#define S3 17 
#define RESISTOR 10000
#define THERMISTOR 10000
#define NOMINAL 25
#pragma once


class TermoNTC{
    public:
            TermoNTC(unsigned char pin_multiplex, unsigned char analog_pin_NTC){
                this->pin_multiplex = pin_multiplex;
                this->analog_pin_NTC = analog_pin_NTC;
                }
        unsigned char pin_multiplex;
        unsigned char analog_pin_NTC;
        
        float calc_Term(char analog_pin_NTC){
            int t = analogRead(analog_pin_NTC);
            float temp;
            temp = 1023.0 / t - 1;
            temp = RESISTOR / temp;
            temp = temp / THERMISTOR;
            temp = log(temp) / 3950 + 1.0 / (NOMINAL + 273.15);
            temp = 1.0 / temp - 273.15;
            temp=(int)(10.0*temp)/10.0;
            return temp;
            };
        float get_tempNTC(){
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
        //      delay(2);
            return calc_Term(analog_pin_NTC);
            };
    };
/*
float calc_Term(int analog_pin_NTC);
float get_tempNTC(int pin_multiplex, int analog_pin_NTC);
*/