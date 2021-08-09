#pragma once

#include <random> // for std::mt19937
#include <ctime>  // for std::time

class MyRandom
{
private:
	static std::mt19937 rng;
public:
	static double Rand();
	static int RandInt(int min, int max);
	static float RandFloat(float min, float max);
	static double RandDouble(double min, double max);
};
