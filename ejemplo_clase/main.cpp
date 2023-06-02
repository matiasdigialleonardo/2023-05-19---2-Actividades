#include <iostream>

using namespace std;

class Sensor
{
    public:
        virtual void sensate(float data) = 0;
        virtual float getData() = 0;
};

class TemperatureSensor : public Sensor
{
    private:
        float temperature;

    public:
        void sensate(float data)
        {
            temperature = data;
        }

        float getData()
        {
            return temperature;
        }
};

class HumiditySensor : public Sensor
{
    private:
        float humidity;

    public:
        void sensate(float data)
        {
            humidity = data;
        }

        float getData()
        {
            return humidity;
        }
};

class SensorFactory
{
    public:
        static Sensor* createSensor(string sensorType)
        {
            Sensor* instance = nullptr;

            if (sensorType == "TEMPERATURE")
            {
                return new TemperatureSensor();
            }
            if (sensorType == "HUMIDITY")
            {
                return new HumiditySensor();
            }

            return instance;
        }
};

int main()
{
    Sensor* t = SensorFactory::createSensor("TEMPERATURE");
    Sensor* h = SensorFactory::createSensor("HUMIDITY");

    t->sensate(32);
    h->sensate(55.5);

    cout << "Temperature: " << t->getData() << endl;
    cout << "Humidity: " << h->getData() << endl;

    delete h;
    delete t;


    return 0;
}