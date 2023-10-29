#include "controller.h"
#include "sstream"
#include "common.h"

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

void Controller::creteUser() {
    std::string name;
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    name = std::any_cast<std::string>(Common::validate(name, "Name", "the name "));

    double money = 0;
    std::cout << "Enter money: ";
    std::cin >> money;
    money = std::any_cast<double>(Common::validate(money, "Money", "the money "));

    this->RegisterUser(name, money);  
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

void Controller::UserInfo(std::string name) {
    std::shared_ptr<User> us = this->checkName(name);
    if (us != nullptr)
        std::cout << *us;
    else
        std::cout << "Unknown user!";
}

void Controller::Shutdown() {
    for (std::shared_ptr<User> user : this->users)
        std::cout << *user;
}

void Controller::CreateComputer(std::string name, std::string procType, std::string procModel, int procGen, double procPrice, std::string videoType, std::string videoModel, int videoGen, int RAM, double videoPrice) {
        std::shared_ptr<User> us = this->checkName(name);
        if (!us) {
            std::cout << "User doesn not exists!" << std::endl;
            return;
        }
        double money_for_pc = procPrice + videoPrice;
        if (us->getMoney() > money_for_pc) {
            us->decreaseMoney(money_for_pc);
            std::shared_ptr<VideoCard> vc = Common::videoCardFactory(videoType, videoModel, videoPrice, videoGen, RAM);
            std::shared_ptr<Processor> prc = Common::processorFactory(procType, procModel, procPrice, procGen);
            std::shared_ptr<Computer> cmp = std::make_shared<Computer>(prc, vc, 64);
            us->setComputer(cmp);
        }
        else
            std::cout << "Not enough!";
    
}

void Controller::initializeCmp() {
    std::string name;
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    name = std::any_cast<std::string>(Common::validate(name, "Name", "the name "));

    std::string procType;
    std::cout << "Enter processor type: ";
    std::getline(std::cin, procType);

    std::string procModel;
    std::cout << "Enter proccessor model: ";
    std::getline(std::cin, procModel);
    procModel = std::any_cast<std::string>(Common::validate(procModel, "Model", "the processor model "));

    int procGen;
    std::cout << "Enter proccessor generation: ";
    std::cin >> procGen;
    procGen = std::any_cast<int>(Common::validate(procGen, "ProcessorGen", "the processor generation "));

    double procPrice;
    std::cout << "Enter proccessor price: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> procPrice;
    procGen = std::any_cast<double>(Common::validate(procPrice, "Price", "the processor price "));

    std::string videoType;
    std::cout << "Enter video card type: ";
    std::getline(std::cin, videoType);

    std::string videoModel;
    std::cout << "Enter video card model: ";
    std::getline(std::cin, videoModel);
    videoModel = std::any_cast<std::string>(Common::validate(videoModel, "Model", "the video card model "));

    int videoGen;
    std::cout << "Enter video card generation: ";
    std::cin >> videoGen;
    videoGen = std::any_cast<int>(Common::validate(videoGen, "Gen", "the vide card generation "));

    int ram;
    std::cout << "Enter vide card RAM: ";
    std::cin >> ram;
    ram = std::any_cast<int>(Common::validate(ram, "RAM", "the vide card generation "));

    double videoPrice;
    std::cout << "Enter video card price: ";
    std::cin >> videoPrice;
    videoPrice = std::any_cast<double>(Common::validate(videoPrice, "Price", "the video card price "));

    this->CreateComputer(name, procType, procModel, procGen, procPrice, videoType, videoModel, videoGen, ram, videoPrice);
}