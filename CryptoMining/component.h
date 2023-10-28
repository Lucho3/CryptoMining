#ifndef COMPONENT_H
#define COMPONENT_H

#include "base.h"

class Component : Base {
private:
	Component();
	std::string model;
	int generation;
	double price;
	int lifeWorkingHours;
public:
	Component(std::string, double, int, int);
	void drainLife(int);
	const std::string getModel() const;
	const double getPrice() const;
	const int getGeneration() const;
	void setLifeWorkingHours(int);
	const int getLifeWorkingHours() const;
};

#endif
