#include "MyRandom.hpp"

std::mt19937 MyRandom::rng{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

double MyRandom::Rand()
{
	std::uniform_real_distribution<> range{ 0.0, 1.0 };
	return range(rng);
}

int MyRandom::RandInt(int min, int max)
{
	std::uniform_int_distribution<> range{ min, max };
	return range(rng);
}

float MyRandom::RandFloat(float min, float max)
{
	std::uniform_real_distribution<> range{ min, max };
	return (float)range(rng);
}

double MyRandom::RandDouble(double min, double max)
{
	std::uniform_real_distribution<> range{ min, max };
	return range(rng);
}