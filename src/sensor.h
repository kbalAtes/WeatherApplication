#pragma once

class Sensor
{
public:
	virtual void Value(int& outVal) = 0;
};