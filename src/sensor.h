#ifndef boiler_automatic_sensor_h
#define boiler_automatic_sensor_h

#include <initializer>


class Sensor
{
public:
    Sensor()
    {
        m_isInit = false;
    }

    virtual ~Sensor() {}
    virtual bool isInit() const { return m_isInit; }
    //virtual void initialize(const int* data, int count) = 0;
    virtual bool initialize(std::initializer<int>) = 0;

protected:
    bool m_isInit;
};


class AnalogSensor : public Sensor
{
public:
    AnalogSensor();
    virtual ~AnalogSensor();
    virtual double value() const = 0;
};


class DiscreteSensor : public Sensor
{
public:
    DiscreteSensor();
    virtual ~DiscreteSensor();
    virtual int count() const = 0;
};

class TemperatureSensor : public AnalogSensor
{
public:
    TemperatureSensor();
    virtual ~TemperatureSensor();
};

TemperatureSensor* CreateSensor(const char*);

#endif // !boiler_automatic_sensor_h
