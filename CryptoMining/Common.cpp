#include "common.h"
#include <functional>
#include <variant>

const bool Common::validateProcessorGen(int number) const {
	if (number > 0 && number <= 9)
		return true;
	return false;
}

Common::Common() {

}

const bool Common::validateGen(int number) const {
	if (number > 0)
		return true;
	return false;
}

const bool Common::validatePrice(double price) const {
	if (price > 0 && price <= 10000)
		return true;
	return false;
}

const bool Common::validateModel(std::string model) const {
	if (!model.empty())
		return true;
	return false;
}

const bool Common::validateVideoRAM(int RAM) const {
	if (RAM > 0 && RAM <= 32)
		return true;
	return false;
}

std::function<bool(std::variant<int, double, std::string>)> Common::getValidationFunction(std::string validate) {
	//returns lambda that accepts this variant
	return [validate, this](std::variant<int, double, std::string> arg) -> bool {
		if (validate == "ProcessorGen") {
			return this->validateProcessorGen(*std::get_if<int>(&arg));
		}
		else if (validate == "Gen") {
			return this->validateGen(*std::get_if<int>(&arg));
		}
		else if (validate == "Price") {
			return validatePrice(*std::get_if<double>(&arg));
		}
		else if (validate == "Model") {
			return validateModel(*std::get_if<std::string>(&arg));
		}
		else if (validate == "RAM") {
			return validateVideoRAM(*std::get_if<int>(&arg));
		}
		else {
			return false;
		}
	};
}

std::string Common::getValueType(std::variant<int, double, std::string> args) {
	if(std::holds_alternative<int>(args)) {
		return "int";
	}
	else if(std::holds_alternative<double>(args)) {
		return "double";
	}
	else if(std::holds_alternative<std::string>(args)) {
		return "string";
	}
}

const std::variant<int, double, std::string> Common::validate(std::variant<int, double, std::string> value, const std::string valFunction, const std::string prompt) {
	std::function<bool(std::variant<int, double, std::string>)> validationFunction = this->getValidationFunction(valFunction);
	std::string valueType = this->getValueType(value);
	std::cout << "Please enter " << prompt << ": ";
	std::string option;
	while(!validationFunction(value))
	{
		std::cout << "Please renter " << prompt << ": ";
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
	} 

	return value;
}

const int 

/*template <>
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