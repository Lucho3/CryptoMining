#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "component.h"

class Processor : public Component
{
private:
	int mineMultiplier;
	std::ostream& print(std::ostream& os) const override;
public:
	Processor(std::string, double, int, int);
	const int getMineMultiplier() const;
};

#endif
