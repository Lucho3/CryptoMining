#include "common.h"
#include "videocard_type.h"
#include "processor_type.h"
#include <functional>
#include <variant>


const bool Common::validateProcessorGen(int number) {
	if (number > 0 && number <= 9)
		return true;
	return false;
}

Common::Common() {

}

const bool Common::validateGen(int number) {
	if (number > 0)
		return true;
	return false;
}

const bool Common::validatePrice(double price) {
	if (price > 0 && price <= 10000)
		return true;
	return false;
}

const bool Common::validateModel(std::string model) {
	if (!model.empty())
		return true;
	return false;
}

const bool Common::validateVideoRAM(int RAM) {
	if (RAM > 0 && RAM <= 32)
		return true;
	return false;
}

const bool Common::validateName(std::string model) {
	//ppc ima i drugi proverki tuk ako ne me murzi
	if (!model.empty())
		return true;
	return false;
}


const bool Common::validateMoney(double price) {
	if (price > 0)
		return true;
	return false;
}


std::function<bool(std::any)> Common::getValidationFunction(std::string validate) {
	//returns lambda that accepts this variant moje i switch case
	return [validate](std::any arg) -> bool {
		if (validate == "ProcessorGen") {
			return validateProcessorGen(std::any_cast<int>(arg));
		}
		else if (validate == "Gen") {
			return validateGen(std::any_cast<int>(arg));
		}
		else if (validate == "Price") {
			return validatePrice(std::any_cast<double>(arg));
		}
		else if (validate == "Model") {
			return validateModel(std::any_cast<std::string>(arg));
		}
		else if (validate == "RAM") {
			return validateVideoRAM(std::any_cast<int>(arg));
		}
		else if (validate == "Name") {
			return validateName(std::any_cast<std::string>(arg));
		}
		else if (validate == "Money") {
			return validateMoney(std::any_cast<double>(arg));
		}
		else {
			return false;
		}
	};
}



const std::type_info& Common::getValueType(std::any value) {
	return value.type();
}

//ne e ni oky chupi OOp principi, no ideqta e da pokajem kakvo moje ezikut principut potrebitelqt znae kakvo pravi moje is variant
const std::any Common::validate(std::any value, const std::string valFunction, const std::string prompt) {
	std::function<bool(std::any)> validationFunction = getValidationFunction(valFunction);
	const std::type_info& valueType = getValueType(value);
	std::string option;
	while (!validationFunction(value))
	{
		std::cout << "Invalid input. Please reenter " << prompt << ": ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, option);
		if (valueType == typeid(int))
			value = std::stoi(option);
		else if (valueType == typeid(double))
			value = std::stod(option);
		else
			value = option;
	}

	return value;
}

std::shared_ptr<VideoCard> Common::videoCardFactory(std::string type, std::string model, double price, int generation, int ram) {
	if (type == "Game")
		return std::make_shared<GameVideoCard>(model, price, generation, ram);
	else if (type == "Mine")
	    return std::make_shared<MineVideoCard>(model, price, generation, ram);
	else
		return nullptr;
}

std::shared_ptr<Processor> Common::processorFactory(std::string type, std::string model, double price, int generation) {
	if (type == "High")
		return std::make_shared<HighPerformanceProcessor>(model, price, generation);
	else if (type == "Low")
		return std::make_shared<LowPerformanceProcessor>(model, price, generation);
	else
		return nullptr;
}

/*
template <typename T>
const T Common::validate(T value, const std::string valFunction, const std::string prompt) {
	std::function<bool(std::variant<int, double, std::string>)> validationFunction = this->getValidationFunction(valFunction);
	std::string valueType = this->getValueType(value);
	std::cout << "Please enter " << prompt << ": ";
	std::string option;
	while(true)
	{
		getline(std::cin, option);

		if (valueType == "int")
		{
			value = std::stoi(option);
		}
		else if (valueType == "double")
		{
			value = std::stod(option);
		}
		else
			value = option;

		if (std::visit(validationFunction, value)) {
			return value;
		}
		else {
			std::cout << "Invalid input. Please reenter " << prompt << ": ";
		}
	} 
}


template <>
const int Common::validate(int value, const std::string valFunction, const std::string prompt) {
	std::function<bool(std::variant<int, double, std::string>)> validationFunction = this->getValidationFunction(valFunction);
	std::string option;
	while (!validationFunction(value))
	{
		std::cout << "Please renter " << prompt << ": ";
		getline(std::cin, option);
		value = std::stoi(option);
	}
	return value;
}*/