#ifndef USER_H
#define USER_H

#include "base.h"
#include "computer.h"

class User : Base {
private:
	User();
	std::string name;
	int stars;
	double money;
	std::shared_ptr<Computer> computer;
	std::ostream& print(std::ostream& os) const override;
public:
	User(std::string, int, double, std::shared_ptr<Computer>);
	const std::string getName() const;
	const int getStars() const;
	const double getMoney() const; 
	std::shared_ptr<Computer> getComputer();
	~User();
};

#endif
