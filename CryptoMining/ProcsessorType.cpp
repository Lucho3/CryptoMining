#include "processor_type.h"

LowPerformanceProcessor::LowPerformanceProcessor(std::string model, double price, int generation)
	: Processor(model, price, generation, 2) {
};

HighPerformanceProcessor::HighPerformanceProcessor(std::string model, double price, int generation)
	: Processor(model, price, generation, 8) {
};