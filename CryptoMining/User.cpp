#include "User.h"

User::User(std::string name, double money)
{
	if (name.empty()) {
		throw std::invalid_argument("The name shall not be empty!");
	}
	if (money < 0) {
		throw std::invalid_argument("The money shall not be lower than 0");
	}

	this->name = name;
	this->money = money;
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

void User::increaseMoney(double money) {
	this->money += money;
}

void User::decreaseMoney(double money) {
	this->money -= money;
}

void User::setComputer(std::shared_ptr<Computer> cmp) {
	this->computer = cmp;
}


std::ostream& User::print(std::ostream& os) const {
	os << "User Details:" << std::endl;
	os << "Name: " << name << std::endl;
	os << "Stars: " << stars << std::endl;
	os << "Money: $" << money << std::endl;

	if (computer) {
		os << this->computer;
	}

	os << std::endl;
	return os;
}