#include "Computer.h"
#include <iostream>

Computer::Computer(std::shared_ptr<Processor> proc, std::shared_ptr<VideoCard> videoC, int RAM)
{
	if (proc == nullptr) {
		throw std::invalid_argument("There is no processor!");
	}
	if (videoC == nullptr) {
		throw std::invalid_argument("There is no video card!");
	}
	if (RAM < 0 || RAM > 32) {
		throw std::invalid_argument("The ram sall be between 0 and 32");
	}

	this->processor = proc;
	this->videoCard = videoC;
	this->ram = RAM;

	this->minedAmountPerHour = this->processor->getMineMultiplier() * this->videoCard->getMinedMoneyPerHour();
}

Computer::~Computer()
{
	//release the onject counter for the instance
	this->processor.reset();
	this->videoCard.reset();
}

std::shared_ptr<Processor> Computer::getProcessor()
{
	return this->processor;
}

std::shared_ptr<VideoCard> Computer::getVideoCard()
{
	return this->videoCard;
}

const int Computer::getRam() const
{
	return this->ram;
}

const double Computer::getMinedAmountPerHour() const
{
	return this->minedAmountPerHour;
}

std::ostream& Computer::print(std::ostream& os) const {
	os << "Computer Details:" << std::endl;
	os << "  RAM: " << ram << " GB" << std::endl;

	os << "  Mined Amount Per Hour: $" << minedAmountPerHour << std::endl;

	if (processor) {
		os << *this->processor;
	}
	if (videoCard) {
		os << *this->videoCard;
	}

	return os;
}
