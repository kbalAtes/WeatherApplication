#include <iostream>

#include "TempratureSensor.h"
#include "HumiditySensor.h"
#include "PressureSensor.h"
#include <thread>

using namespace std;

Sensor* temp1;
Sensor* hum1;
Sensor* pr1;

int sensorVal[3];

void fun1(int* val)
{
	temp1->Value(*val);
}

void fun2(int* val)
{
	hum1->Value(*val);
}

void fun3(int* val)
{
	pr1->Value(*val);
}

void fun4(int val[])
{
	while (true)
	{
		std::cout << val[0] << " " << val[1] << " " << val[2] << std::endl;
	}
}

int main(void)
{
	temp1 = new TempratureSensor(12.2f, 26.8f, 1000);
	hum1 = new HumiditySensor(1.2f, 10.8f, 1000);
	pr1 = new PressureSensor(10.2f, 20.8f, 1000);

	std::thread th1(fun1, &sensorVal[0]);
	std::thread th2(fun2, &sensorVal[1]);
	std::thread th3(fun3, &sensorVal[2]);
	std::thread th4(fun4, sensorVal);
                                                                                                                                                                                 
	std::cout << "Working" << std::endl;

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	delete(temp1, hum1, pr1);

	return 0;
}

