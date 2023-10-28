#ifndef VIDEOCARD_H
#define VIDEOCARD_H

#include "component.h"

class VideoCard : public Component
{
private:
	VideoCard();
	std::ostream& print(std::ostream& os) const override;
	int ram;
	double mindeMoneyPerHour;
public:
	VideoCard(std::string, double, int, int);
	const int getRAM() const;
	void setMinedMoneyPerHour(double);
	const double getMinedMoneyPerHour() const;
};

#endif
