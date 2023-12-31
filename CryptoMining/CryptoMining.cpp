﻿// CryptoMining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "common.h"
#include "controller.h"
#include "processor_type.h"

const int setGlobalMenu()  {
    std::system("cls");
    std::cout << "Manin Menu:\n";
    std::cout << "0. Create user.\n";
    std::cout << "1. Buy computer for user\n";
    std::cout << "2. Mine\n";
    std::cout << "3. User Info\n";
    std::cout << "4. Shutdown\n";
    std::string choice;
    std::getline(std::cin, choice);
    return std::stoi(choice);
}


void startApp(Controller * ctrl) {
    std::string username;
    while (true) {
        switch (setGlobalMenu()) {
        case 0:
            ctrl->creteUser();
            std::getchar();
            break;
        case 1:
            ctrl->initializeCmp();
            std::getchar();
            break;
        case 2:
            ctrl->Mine();
            std::getchar();
            break;
        case 3:
            std::system("cls");
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            ctrl->UserInfo(username);
            std::getchar();
            break;
        case 4:
            ctrl->Shutdown();
            std::getchar();
            return;
        default:
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

int main()
{
    //singleton best here
    //ne kombinirame getline s cin>>promenliva ako ne znaem kakvo pravim
    Controller* ctrl = new Controller();
    startApp(ctrl);
    delete ctrl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
