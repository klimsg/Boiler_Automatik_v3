#include "sensor.h"


class TemperatureSensor_MAX : public TemperatureSensor
{
public:
    double value() const override;
    bool initialize(std::initializer<int>) override
    {
        // ...
        m_isInit = true;
        return m_isInit;
    }
};

class TemperatureSensor_NTC : public TemperatureSensor
{
public:
    double value() const override;
    bool initialize(std::initializer<int>)
    {
        // ...
        m_isInit = true;
        return m_isInit;
    }
};


TemperatureSensor* CreateSensor(const char* sensorType)
{
    if(strcmp(sensorType,"NTC") == 0)
        return new TemperatureSensor_NTC();
    if(strcmp(sensorType,"MAX") == 0)
        return new TemperatureSensor_MAX();
    return nullptr;
}


int main()
{
    auto tSensor1 = CreateSensor("MAX");
    if(!tSensor1)
        return 1;
    if(!tSensor1->initialize({3,5,7}))
        return 2;

    double t = tSensor1->value();

    delete tSensor1;

    TemperatureSensor_MAX tSensor2;
    tSensor2.initialize({2,3,5});

    return 0;
}