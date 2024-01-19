#include <Arduino.h>
#include "SGTermoNTC.h"
#include "SGTermoMAX6675.h"
#include "SGWaterGO.h"
#include "SGSwitch.h"
#include "SGRelay.h"


//Создание управляемых реле: Relay Название_датчика(Пин_ардуино);
Relay pump1_register(1);
Relay pump2_register(2);
Relay pump_radiator(3);
Relay pump_floor(4);
Relay pump_boiler(5);

//Создание концевых датчиков: Switch Название_датчика(Пин_мультиплекса,Аналоговый_пин_ардуино);
Switch switch_door(1,3);
Switch switch_window(2,3);
Switch switch_level_water(3,3);
Switch switch_door_furnace(4,3);
Switch switch_down_door(5,3);

//Создание Датчиков потока воды: WaterGO Название_датчика(Пин_ардуино);
WaterGO sensor_flow_register (1, 18);
WaterGO sensor_flow_return_tank (2, 19);
WaterGO sensor_flow_return_home (3, 20);
WaterGO class4 (4, 21);

//Создание ТЕРМОМЕТРОВ MAX6675: TERMO_MAX Название_датчика(Пин_ардуино);
TERMO_MAX TEMP_fire (49);
TERMO_MAX TEMP_furnace(52);
TERMO_MAX TEMP_exhaust(50);

//Создание термометров NTC :TermoNTC Название_датчика(Пин_мультиплекса,Аналоговый_пин_ардуино);
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
    pinMode(sensor_flow_register.Pin_waterGO, INPUT);
        digitalWrite(sensor_flow_register.Pin_waterGO, HIGH);
                pinMode(sensor_flow_return_tank.Pin_waterGO, INPUT);
        digitalWrite(sensor_flow_return_tank.Pin_waterGO, HIGH);
                pinMode(sensor_flow_return_home.Pin_waterGO, INPUT);
        digitalWrite(sensor_flow_return_home.Pin_waterGO, HIGH);
                pinMode(class4.Pin_waterGO, INPUT);
        digitalWrite(class4.Pin_waterGO, HIGH);

            attachInterrupt(digitalPinToInterrupt(sensor_flow_register.Pin_waterGO), getFlow1, RISING);
            attachInterrupt(digitalPinToInterrupt(sensor_flow_return_tank.Pin_waterGO), getFlow2, RISING);
            attachInterrupt(digitalPinToInterrupt(sensor_flow_return_home.Pin_waterGO), getFlow3, RISING);
            attachInterrupt(digitalPinToInterrupt(class4.Pin_waterGO), getFlow4, RISING);   
}

unsigned long loopTimer;

void loop(){
    int literperhour1 = sensor_flow_register.get_WaterGO();
    int literperhour2 = sensor_flow_return_tank.get_WaterGO();
    int literperhour3 = sensor_flow_return_home.get_WaterGO();
    int literperhour4 = class4.get_WaterGO();

        if(millis() - loopTimer > 3000){
            loopTimer = millis();

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

            Serial.print(" term_Tank2_lvl1 = ");
            Serial.print(term_Tank2_lvl1.get_tempNTC());
            Serial.print(" term_Tank2_lvl2 = ");
            Serial.print(term_Tank2_lvl2.get_tempNTC());
            Serial.print(" term_Tank2_lvl3 = ");
            Serial.print(term_Tank2_lvl3.get_tempNTC());
            Serial.print(" term_Tank2_lvl4 = ");
            Serial.print(term_Tank2_lvl4.get_tempNTC());
            Serial.print(" term_Tank2_lvl5 = ");
            Serial.print(term_Tank2_lvl5.get_tempNTC());
            Serial.print(" term_Tank2_lvl6 = ");
            Serial.print(term_Tank2_lvl6.get_tempNTC());
            Serial.println();

            Serial.print("TEMP_fire = ");
            Serial.print(TEMP_fire.get_TEMP_MAX());
            Serial.print(" TEMP_furnace = ");
            Serial.print(TEMP_furnace.get_TEMP_MAX());
            Serial.print(" TEMP_exhaust = ");
            Serial.print(TEMP_exhaust.get_TEMP_MAX());
            Serial.println();


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
