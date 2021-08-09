#pragma once

#include <random> // for std::mt19937
#include <ctime>  // for std::time

class MyRandom
{
private:
	static std::mt19937 rng;
public:
	static double Rand(); // Returns a random double between 0.0 and 1.0
	static int RandInt(int min, int max); // Returns a random integer between min and max.
	static float RandFloat(float min, float max); // Returns a random float between min and max.
	static double RandDouble(double min, double max); // Returns a random double between min and max.
};
