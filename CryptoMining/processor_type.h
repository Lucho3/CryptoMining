#ifndef POCESSORTYPE_H
#define POCESSORTYPE_H

#include "processor.h"

class LowPerformanceProcessor : public Processor {
private:
	LowPerformanceProcessor();
public:
	LowPerformanceProcessor(std::string, double, int);
};

class HighPerformanceProcessor : public Processor {
private:
	HighPerformanceProcessor();
public:
	HighPerformanceProcessor(std::string, double, int);
};

#endif
