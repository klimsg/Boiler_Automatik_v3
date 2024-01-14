#pragma once
#include <Arduino.h>
volatile int  pulse_frequency;
unsigned int  literperhour;
unsigned char Pin_waterGO = 19;
unsigned long loopTimer1;

void getFlow (){ 
   pulse_frequency++;
}


void WaterGOsetup(){ 
   pinMode(Pin_waterGO, INPUT);
   digitalWrite(Pin_waterGO, HIGH);
   attachInterrupt(digitalPinToInterrupt(Pin_waterGO), getFlow, RISING);
} 

int WaterGO (){
   if(millis() - loopTimer1 > 5000){
            loopTimer1 = millis();
            literperhour = (pulse_frequency / 5 * 60 / 447);
            pulse_frequency = 0;
            }
   return literperhour;
}

