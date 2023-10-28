#include "controller.h"
#include "sstream"

Controller::Controller() {

}

template <typename Container>
void Controller::ClearList(Container& container) {
    for (auto& item : container) {
        item.reset();
    }
    container.clear();
}

Controller::~Controller() {
    this->ClearList(this->users);
}

std::shared_ptr<User> Controller::checkName(std::string name) {
    for (auto& user : this->users) 
        if (user->getName() == name)
            return user;
    
    return nullptr;
}

std::string Controller::RegisterUser(std::string name, double money) {
    std::ostringstream sstr;
    try {
        if (this->checkName(name)) {
            sstr << "User exists!" << std::endl;
            return sstr.str();
        }
        this->users.push_back(std::make_shared<User>(name, money));
        sstr << "User registered: " << name << "!" << std::endl;
        return sstr.str();
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid argument: " << ex.what() << std::endl;
    }
}

std::string Controller::Mine() {
    double minedMoney = 0;
    for (std::shared_ptr<User> us : this->users) {
        try {
            minedMoney = us->getComputer()->getMinedAmountPerHour() * 24;
            us->increaseMoney(minedMoney);
            this->minedAmountDaily += minedMoney;
            us->getComputer()->getProcessor()->drainLife(24);
            us->getComputer()->getVideoCard()->drainLife(24);
        }
        catch (const std::invalid_argument& ex) {
            std::cerr << "Invalid argument: " << ex.what() << std::endl;
        }
    }

    std::ostringstream sstr;
    sstr << "Daily profits: " << this->minedAmountDaily << "!" << std::endl;
    return sstr.str();
}

std::string Controller::UserInfo(std::string name) {
    std::ostringstream sstr;
    std::shared_ptr<User> us = this->checkName(name);
    if (us != nullptr)
        sstr << us;
    else
        sstr << "Unknown user!";
    return sstr.str();
}

void Controller::Shutdown() {
    for (auto& user : this->users)
        std::cout << user;
}