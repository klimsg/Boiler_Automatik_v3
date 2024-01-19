#pragma once
#include <Arduino.h>

volatile int  pulse_frequency1 = 0;
volatile int  pulse_frequency2 = 0;
volatile int  pulse_frequency3 = 0;
volatile int  pulse_frequency4 = 0;

    void getFlow1 (){ 
        pulse_frequency1++;
    }
    void getFlow2 (){ 
        pulse_frequency2++;
    }
    void getFlow3 (){ 
        pulse_frequency3++;
    }
    void getFlow4 (){ 
        pulse_frequency4++;
    }

class WaterGO{
    public:
        WaterGO(unsigned char namber,unsigned char Pin_waterGO){
            this->Pin_waterGO = Pin_waterGO;
            this->namber = namber;
            }
        unsigned char namber;
        unsigned int  literperhour;
        unsigned long currentTime, loopTime;
        unsigned char Pin_waterGO;
        unsigned long loopTimer1;

        int get_WaterGO (){
            if((namber == 1) & (millis() - loopTimer1 > 5000)){
                loopTimer1 = millis();
                literperhour = (pulse_frequency1 / 5 * 60 / 447);
                pulse_frequency1 = 0;
                }
            if((namber == 2) & (millis() - loopTimer1 > 5000)){
                loopTimer1 = millis();
                literperhour = (pulse_frequency2 / 5 * 60 / 447);
                pulse_frequency2 = 0;
                }
            if((namber == 3) & (millis() - loopTimer1 > 5000)){
                loopTimer1 = millis();
                literperhour = (pulse_frequency3 / 5 * 60 / 447);
                pulse_frequency3 = 0;
                }
            if((namber == 4) & (millis() - loopTimer1 > 5000)){
                loopTimer1 = millis();
                literperhour = (pulse_frequency4 / 5 * 60 / 447);
                pulse_frequency4 = 0;
                }
            return literperhour;
            };
    };