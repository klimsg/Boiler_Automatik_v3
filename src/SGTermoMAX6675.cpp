#include "SGTermoMAX6675.h"


TERMO_MAX::TERMO_MAX(unsigned char pin_arduino) {
    this->pin_arduino = pin_arduino;
}


float TERMO_MAX::get_TEMP_MAX() {
    MAX6675 TERMO (thermoSCK, thermoCS, pin_arduino);
    return TERMO.readCelsius();
}
