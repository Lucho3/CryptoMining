#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>
#include "user.h"
#include "computer.h"

class Controller  {
private:
	std::vector<std::shared_ptr<User>> users;
	double minedAmountDaily;
	std::shared_ptr<User> checkName(std::string);
	template <typename Container>
	void ClearList(Container&);
public:
	Controller();
	~Controller();
	std::string RegisterUser(std::string, double);
	void CreateComputer(std::string, std::string, std::string, int, double, std::string, std::string, int, int, double);
	std::string Mine();
	void UserInfo(std::string);
	void initializeCmp();
	void creteUser();
	void Shutdown();
};

#endif