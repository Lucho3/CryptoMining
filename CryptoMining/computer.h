#ifndef COMPUTER_H
#define COMPUTER_H

#include "processor.h"
#include "video_card.h"
#include "base.h"

class Computer : Base {
private:
    Computer();
    std::shared_ptr<Processor> processor;
    std::shared_ptr<VideoCard> videoCard;
    int ram;
    double minedAmountPerHour;
	std::ostream& print(std::ostream& os) const override;
private:
	Computer(std::shared_ptr<Processor>, std::shared_ptr<VideoCard>, int);
	~Computer();
	std::shared_ptr<Processor> getProcessor();
	std::shared_ptr<VideoCard> getVideoCard();
	const int getRam() const;

};

#endif