#include "video_card.h"

VideoCard::VideoCard(std::string model, double price, int generation, int ram)
	: Component(model, price, generation, ram* generation * 10) {
	if (ram < 0 || ram > 32) {
		throw std::invalid_argument("The RAM shall be >= 0 and <=32");
	}

	this->ram = ram;
	this->mindeMoneyPerHour = static_cast<double>(ram) * generation / 10;
}

const int VideoCard::getRAM() const {
	return this->ram;
}

void VideoCard::setMinedMoneyPerHour(double money)
{
	this->mindeMoneyPerHour = money;
}

const double VideoCard::getMinedMoneyPerHour() const {
	return this->mindeMoneyPerHour;
}

std::ostream& VideoCard::print(std::ostream& os) const {
	os << "Video Card Details:" << std::endl;
	os << "  Model: " << getModel() << std::endl;
	os << "  Price: " << getPrice() << std::endl;
	os << "  Generation: " << getGeneration() << std::endl;
	os << "  Life Working Hours: " << getLifeWorkingHours() << std::endl;
	os << "  RAM: " << ram << " GB" << std::endl;
	os << "  Mined Money Per Hour: $" << mindeMoneyPerHour << std::endl;

	os << std::endl;

	return os;
}