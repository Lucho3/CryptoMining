#include "processor_type.h"

LowPerformanceProcessor::LowPerformanceProcessor(std::string model, double price, int generation, int lifeWorkingHours)
	: Processor(model, price, generation, lifeWorkingHours, 2) {
};

HighPerformanceProcessor::HighPerformanceProcessor(std::string model, double price, int generation, int lifeWorkingHours)
	: Processor(model, price, generation, lifeWorkingHours, 8) {
};