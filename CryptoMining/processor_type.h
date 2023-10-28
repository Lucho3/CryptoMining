#ifndef POCESSORTYPE_H
#define POCESSORTYPE_H

#include "processor.h"

class LowPerformanceProcessor : Processor {
private:
	LowPerformanceProcessor();
public:
	LowPerformanceProcessor(std::string, double, int, int);
};

class HighPerformanceProcessor : Processor {
private:
	HighPerformanceProcessor();
public:
	HighPerformanceProcessor(std::string, double, int, int);
};

#endif
