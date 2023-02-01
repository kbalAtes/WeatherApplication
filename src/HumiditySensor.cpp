#include "HumiditySensor.h"
#include <iostream>
#include <thread>

using namespace std;

HumiditySensor::HumiditySensor(float minVal, float maxVal, long interval)
    : m_minVal(minVal)
    , m_maxVal(maxVal)
    , m_interval(interval)
{

}

void HumiditySensor::Value(int& outVal)
{
    while (true)
    {
        auto randVal = (int)m_minVal + (rand() % (int)(m_maxVal - m_minVal));
        //cout << "Temprature: " << randVal << endl;
        outVal = randVal;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
