#ifndef VIDEOCARDTYPE_H
#define VIDEOCARDTYPE_H

#include "video_card.h"

class MineVideoCard : public VideoCard
{
public:
	MineVideoCard(std::string, double, int, int);
};

class GameVideoCard : public VideoCard
{
public:
	GameVideoCard(std::string, double, int, int);
};

#endif