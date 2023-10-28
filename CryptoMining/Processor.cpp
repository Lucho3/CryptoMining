#include "processor.h"
#include <iostream>

Processor::Processor(std::string model, double price, int generation, int lifeWorkingHours, int mineMultiplier)
	: Component(model, price, generation, lifeWorkingHours)
{
	if (generation > 9) {
		throw std::invalid_argument("The generation shall be <= 9! ");
	}

	this->mineMultiplier = mineMultiplier;
}

const int Processor::getMineMultiplier() const {
	return this->mineMultiplier;
}

std::ostream& Processor::print(std::ostream& os) const {
    os << "Processor Details:" << std::endl;;
    os << "  Model: " << getModel() << std::endl;;
    os << "  Price: " << getPrice() << std::endl;;
    os << "  Generation: " << getGeneration() << std::endl;;
    os << "  Life Working Hours: " << getLifeWorkingHours() << std::endl;;
    os << "  Mine Multiplier: " << mineMultiplier << std::endl;;

    os << std::endl;

    return os;
}