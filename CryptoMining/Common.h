#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <iostream>
#include <functional>
#include "video_card.h"
#include "processor.h"
#include <any>

class Common {
private:
	static const bool validateProcessorGen(int);
	static const bool validatePrice(double);
	static const bool validateModel(std::string);
	static const bool validateGen(int number);
	static const bool validateVideoRAM(int RAM);
	static const bool validateName(std::string);
	static const bool validateMoney(double);
	static std::function<bool(std::any)> getValidationFunction(std::string);
	static const std::type_info& getValueType(std::any);
public:
	Common();
	static const std::any validate(std::any, const std::string, const std::string);
	static std::shared_ptr<VideoCard> videoCardFactory(std::string, std::string, double, int, int);
	static std::shared_ptr<Processor> processorFactory(std::string, std::string, double, int);

};
#endif
