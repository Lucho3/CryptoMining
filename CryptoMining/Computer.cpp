#include "Computer.h"
#include <iostream>

Computer::Computer(std::shared_ptr<Processor> processor, std::shared_ptr<VideoCard> videoCard, int ram)
{
	if (processor == nullptr) {
		throw std::invalid_argument("There is no processor!");
	}
	if (videoCard == nullptr) {
		throw std::invalid_argument("There is no video card!");
	}
	if (ram < 0 || ram > 32) {
		throw std::invalid_argument("The ram sall be between 0 and 32");
	}

	this->processor = processor;
	this->videoCard = videoCard;
	this->ram = ram;

	this->minedAmountPerHour = processor->getMineMultiplier() * videoCard->getMinedMoneyPerHour();
}

Computer::~Computer()
{
	//release the onject counter for the instance
	this->processor.reset();
	this->videoCard.reset();
}

std::shared_ptr<Processor> Computer::getProcessor()
{
	return this->getProcessor();
}

std::shared_ptr<VideoCard> Computer::getVideoCard()
{
	return this->videoCard;
}

const int Computer::getRam() const
{
	return this->ram;
}

std::ostream& Computer::print(std::ostream& os) const {
	os << "Computer Details:" << std::endl;
	os << "  RAM: " << ram << " GB" << std::endl;

	os << "  Mined Amount Per Hour: $" << minedAmountPerHour << std::endl;

	if (processor) {
		os << this->processor;
	}
	if (videoCard) {
		os << this->videoCard;
	}

	return os;
}
