#include <Arduino.h>
#include  <max6675.h>
#include "SGTermoNTC.h"




//Создание ТЕРМОМЕТРОВ MAX6675: MAX6675 Название_датчика(Пин_SCK < общее, Пин_CS < общее, Пин_SO< его нужно выбрать для каждого);
#define thermoCS  51
#define thermoSCK 53
MAX6675 TEMP_fire(thermoSCK, thermoCS, 49);
MAX6675 TEMP_furnace(thermoSCK, thermoCS, 52);
MAX6675 TEMP_exhaust(thermoSCK, thermoCS, 50);

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

}


void loop(){


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
  Serial.print(TEMP_fire.readCelsius()); //thermocouple
    Serial.print(" TEMP_furnace = ");
    Serial.print(TEMP_furnace.readCelsius()); //thermocouple*/
  Serial.println();
    delay(3000);
  }