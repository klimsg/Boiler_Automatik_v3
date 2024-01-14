#pragma once
#include <Arduino.h>
#include  <max6675.h>
#define thermoCS  51
#define thermoSCK 53


class TERMO_MAX{
    public:
        TERMO_MAX(unsigned char pin_arduino){
            this->pin_arduino = pin_arduino;
            }
        unsigned char pin_arduino;


        float get_TEMP_MAX(){
            MAX6675 TERMO (thermoSCK, thermoCS, pin_arduino);
            return TERMO.readCelsius();
        }
    };