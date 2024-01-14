#include <Arduino.h>
#include "SGTermoNTC.h"
#include "SGTermoMAX6675.h"
#include "SGWaterGO.h"




//Создание Датчиков потока воды: WaterGO Название_датчика(Пин_ардуино);
WaterGO class1 (1, 18);
WaterGO class2 (2, 19);
WaterGO class3 (3, 20);
WaterGO class4 (4, 21);
        
//Создание ТЕРМОМЕТРОВ MAX6675: TERMO_MAX Название_датчика(Пин_ардуино);
TERMO_MAX TEMP_fire (49);
TERMO_MAX TEMP_furnace(52);
TERMO_MAX TEMP_exhaust(50);

//Создание термометров NTC :TermoNTC Название_датчика(Пин_мультиплекса,Аналоговый_пин_ардуино);
TermoNTC TEMP0(0,1);
TermoNTC term_Tank1_lvl1 (1,1);
TermoNTC term_Tank1_lvl2 (2,1);
TermoNTC term_Tank1_lvl3 (3,1);
TermoNTC term_Tank1_lvl4 (4,1);
TermoNTC term_Tank1_lvl5 (5,1);
TermoNTC term_Tank1_lvl6 (6,1);
TermoNTC term_Tank1_lvl7 (7,1);
TermoNTC term_Tank1_lvl8 (8,1);
TermoNTC term_Tank2_lvl1 (1,0);
TermoNTC term_Tank2_lvl2 (2,0);
TermoNTC term_Tank2_lvl3 (3,0);
TermoNTC term_Tank2_lvl4 (4,0);
TermoNTC term_Tank2_lvl5 (5,0);
TermoNTC term_Tank2_lvl6 (6,0);
TermoNTC term_Tank2_lvl7 (7,0);
TermoNTC term_Tank2_lvl8 (8,0);



void setup(){
  Serial.begin(9600);
//  WaterGOsetup();
   pinMode(class1.Pin_waterGO, INPUT);
        digitalWrite(class1.Pin_waterGO, HIGH);
                pinMode(class2.Pin_waterGO, INPUT);
        digitalWrite(class2.Pin_waterGO, HIGH);
                pinMode(class3.Pin_waterGO, INPUT);
        digitalWrite(class3.Pin_waterGO, HIGH);
                pinMode(class4.Pin_waterGO, INPUT);
        digitalWrite(class4.Pin_waterGO, HIGH);

            attachInterrupt(digitalPinToInterrupt(class1.Pin_waterGO), getFlow1, RISING);
            attachInterrupt(digitalPinToInterrupt(class2.Pin_waterGO), getFlow2, RISING);
            attachInterrupt(digitalPinToInterrupt(class3.Pin_waterGO), getFlow3, RISING);
            attachInterrupt(digitalPinToInterrupt(class4.Pin_waterGO), getFlow4, RISING);   
}

unsigned long loopTimer;

void loop(){
    int literperhour1 = class1.get_WaterGO();
    int literperhour2 = class2.get_WaterGO();
    int literperhour3 = class3.get_WaterGO();
    int literperhour4 = class4.get_WaterGO();
  //      literperhour = WaterGO();

        if(millis() - loopTimer > 3000){
            loopTimer = millis();
            Serial.print(" Т0 = ");
            Serial.print(TEMP0.get_tempNTC());
            Serial.print(" term_Tank1_lvl1 = ");
            Serial.print(term_Tank1_lvl1.get_tempNTC());
            Serial.print(" term_Tank1_lvl2 = ");
            Serial.print(term_Tank1_lvl2.get_tempNTC());
            Serial.print(" term_Tank1_lvl3 = ");
            Serial.print(term_Tank1_lvl3.get_tempNTC());
            Serial.print(" term_Tank1_lvl4 = ");
            Serial.print(term_Tank1_lvl4.get_tempNTC());
            Serial.print(" term_Tank1_lvl5 = ");
            Serial.print(term_Tank1_lvl5.get_tempNTC());
            Serial.print(" term_Tank1_lvl6 = ");
            Serial.print(term_Tank1_lvl6.get_tempNTC());
            Serial.println();
            Serial.print("TEMP_fire = ");
            Serial.print(TEMP_fire.get_TEMP_MAX());
            Serial.print(" TEMP_furnace = ");
            Serial.print(TEMP_furnace.get_TEMP_MAX());
            Serial.print(" TEMP_exhaust = ");
            Serial.print(TEMP_exhaust.get_TEMP_MAX());
            Serial.println();

//            Serial.print(literperhour);
//            Serial.println(" Л/мин");
            Serial.print(literperhour1);
            Serial.print(" Л/мин   ");
            Serial.print(literperhour2);
            Serial.print(" Л/мин   ");
            Serial.print(literperhour3);
            Serial.print(" Л/мин   ");
            Serial.print(literperhour4);
            Serial.print(" Л/мин");
            Serial.println();
            Serial.println();
        }
  }
