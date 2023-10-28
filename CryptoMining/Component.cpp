#include "component.h"
#include <iostream>

Component::Component()
{
	throw std::logic_error("Empty constructor is restricted");
}

Component::Component(std::string model, double price, int generation, int lifeWorkingHours)
{
	if (model.empty()) {
		throw std::invalid_argument("The model shall not be null or empty!");
	}
	if (price < 0.001f || price > 10000.0f) {
		throw std::invalid_argument("The price shall be > 0 and < 10 000");
	}
	if (generation < 1) {
		throw std::invalid_argument("The generation shall be greater than 0.");
	}

	this->model = model;
	this->price = price;
	this->generation = generation;
	this->lifeWorkingHours = lifeWorkingHours;
}

Component::~Component()
{
	std::cout << "Component '" << getModel() << "' was destroyed!" << std::endl;
}

const std::string Component::getModel() const
{
	return this->model;
}

const double Component::getPrice() const
{
	return this->price;
}

const int Component::getGeneration() const
{
	return this->generation;
}

void Component::setLifeWorkingHours(int hours)
{
	this->lifeWorkingHours = hours;
}

const int Component::getLifeWorkingHours() const
{
	return this->lifeWorkingHours;
}
