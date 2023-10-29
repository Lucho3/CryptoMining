#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <iostream>
#include <functional>
#include <variant>

class Common {
private:
	const bool validateProcessorGen(int) const;
	const bool validatePrice(double) const;
	const bool validateModel(std::string) const;
	const bool validateGen(int number) const;
	const bool validateVideoRAM(int RAM) const;
	std::function<bool(std::variant<int, double, std::string>)> getValidationFunction(std::string);
	std::string getValueType(std::variant<int, double, std::string>);
public:
	Common();
	const std::variant<int, double, std::string> validate(std::variant<int, double, std::string>, const std::string, const std::string);
};
#endif
