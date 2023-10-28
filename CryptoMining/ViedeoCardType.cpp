#include "videocard_type.h"

MineVideoCard::MineVideoCard(std::string model, double price, int generation, int ram)
	: VideoCard(model, price, generation, ram)
{
	if (generation > 6) {
		throw std::invalid_argument("The generation shall be > 6");
	}

	this->setMinedMoneyPerHour(8 * this->getMinedMoneyPerHour()); 
	this->setLifeWorkingHours(this->getLifeWorkingHours()*2);
}

GameVideoCard::GameVideoCard(std::string model, double price, int generation, int ram)
	: VideoCard(model, price, generation, ram)
{
	if (generation > 9) {
		throw std::invalid_argument("he generation shall not be > 9!");
	}

	this->setMinedMoneyPerHour(2 * this->getMinedMoneyPerHour());
}