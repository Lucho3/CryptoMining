#include "controller.h"
#include "sstream"
#include "common.h"
#include "processor_type.h"
#include "videocard_type.h"

Controller::Controller() {
    this->minedAmountDaily = 0;
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

void Controller::RegisterUser(std::string name, double money) {
    try {
        std::system("cls");
        if (this->checkName(name)) {
            std::cout << "User exists!" << std::endl;
        }
        this->users.push_back(std::make_shared<User>(name, money));
        std::cout << "User registered: " << name << "!" << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Invalid argument: " << ex.what() << std::endl;
    }
}

void Controller::creteUser() {
    std::system("cls");
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    name = std::any_cast<std::string>(Common::validate(name, "Name", "the name "));

    std::system("cls");
    std::string money;
    std::cout << "Enter money: ";
    std::getline(std::cin, money);
    double m = std::stod(money);
    m = std::any_cast<double>(Common::validate(m, "Money", "the money "));

    this->RegisterUser(name, m);  
}

void Controller::Mine() {
    double minedMoney = 0;
    std::system("cls");
    for (std::shared_ptr<User> us : this->users) {
        try {
            minedMoney = us->getComputer()->getMinedAmountPerHour() * 24;
            us->increaseMoney(minedMoney);
            this->minedAmountDaily += minedMoney;
            us->getComputer()->getProcessor()->drainLife(24);
            us->getComputer()->getVideoCard()->drainLife(24);
            std::cout << "Mined amount: " << minedMoney << std::endl;
        }
        catch (const std::invalid_argument& ex) {
            std::cerr << "Invalid argument: " << ex.what() << std::endl;
        }
    }

    std::cout << "Daily profits: " << this->minedAmountDaily << "!" << std::endl;
}

void Controller::UserInfo(std::string name) {
    std::system("cls");
    std::shared_ptr<User> us = this->checkName(name);
    if (us != nullptr)
        std::cout << *us;
    else
        std::cout << "Unknown user!";
}

void Controller::Shutdown() {
    std::system("cls");
    for (std::shared_ptr<User> user : this->users)
        std::cout << *user;
}

void Controller::CreateComputer(std::string name, std::string procType, std::string procModel, int procGen, double procPrice, std::string videoType, std::string videoModel, int videoGen, int RAM, double videoPrice) {
    std::system("cls");
    try {
        std::shared_ptr<User> us = this->checkName(name);
        if (!us) {
            std::cout << "User doesn not exists!" << std::endl;
            return;
        }
        double money_for_pc = procPrice + videoPrice;
        if (us->getMoney() > money_for_pc) {
            us->decreaseMoney(money_for_pc);
            std::shared_ptr<Processor> prc = Common::processorFactory(procType, procModel, procPrice, procGen);
            std::shared_ptr<VideoCard> vc = Common::videoCardFactory(videoType, videoModel, videoPrice, videoGen, RAM);
            std::shared_ptr<Computer> cmp = std::make_shared<Computer>(prc, vc, 16);
            us->setComputer(cmp);
            std::cout << "Computer assigned to user!" << std::endl;
        }
        else
            std::cout << "Not enough!";
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "The computer wasnt created!";
    }
    
}

void Controller::initializeCmp() {
    std::system("cls");
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    name = std::any_cast<std::string>(Common::validate(name, "Name", "the name "));

    std::system("cls");
    std::string procType;
    std::cout << "Enter processor type: ";
    std::getline(std::cin, procType);
    procType = std::any_cast<std::string>(Common::validate(procType, "Proc", "the proccessor type "));

    std::system("cls");
    std::string procModel;
    std::cout << "Enter proccessor model: ";
    std::getline(std::cin, procModel);
    procModel = std::any_cast<std::string>(Common::validate(procModel, "Model", "the processor model "));

    std::system("cls");
    std::string procGen;
    std::cout << "Enter proccessor generation: ";
    std::getline(std::cin, procGen);
    int genP = std::stoi(procGen);
    genP = std::any_cast<int>(Common::validate(genP, "ProcessorGen", "the processor generation "));

    std::system("cls");
    std::string procPrice;
    std::cout << "Enter proccessor price: ";
    std::getline(std::cin, procPrice);
    double priceP = std::stod(procPrice);
    priceP = std::any_cast<double>(Common::validate(priceP, "Price", "the processor price "));

    std::system("cls");
    std::string videoType;
    std::cout << "Enter video card type: ";
    std::getline(std::cin, videoType);
    videoType = std::any_cast<std::string>(Common::validate(videoType, "Video", "the video card type "));

    std::system("cls");
    std::string videoModel;
    std::cout << "Enter video card model: ";
    std::getline(std::cin, videoModel);
    videoModel = std::any_cast<std::string>(Common::validate(videoModel, "Model", "the video card model "));

    std::system("cls");
    std::string videoGen;
    std::cout << "Enter video card generation: ";
    std::getline(std::cin, videoGen);
    int genV = std::stoi(videoGen);
    genV = std::any_cast<int>(Common::validate(genV, "Gen", "the vide card generation "));

    std::system("cls");
    std::string ram;
    std::cout << "Enter vide card RAM: ";
    std::getline(std::cin, ram);
    int ramV = std::stoi(ram);
    ram = std::any_cast<int>(Common::validate(ramV, "RAM", "the vide card generation "));

    std::system("cls");
    std::string videoPrice;
    std::cout << "Enter video card price: ";
    std::getline(std::cin, videoPrice);
    double priceV = std::stod(videoPrice);
    priceV = std::any_cast<double>(Common::validate(priceV, "Price", "the video card price "));

    this->CreateComputer(name, procType, procModel, genP, priceP, videoType, videoModel, genV, ramV, priceV);
}