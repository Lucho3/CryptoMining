#include "User.h"

User::User(std::string name, int stars, double money, std::shared_ptr<Computer> computer)
{
	if (name.empty()) {
		throw std::invalid_argument("The name shall not be empty!");
	}
	if (money < 0) {
		throw std::invalid_argument("The money shall not be lower than 0");
	}

	this->name = name;
	this->money = money;
	this->computer = computer;

	this->stars = money / 100;
}

const std::string User::getName() const {
	return this->name;
}

const int User::getStars() const {
	return this->stars;
}

const double User::getMoney() const {
	return this->money;
}

std::shared_ptr<Computer> User::getComputer() {
    return this->computer;
}

User::~User() {
	this->computer.reset();
}