#pragma once

#include <iostream>
#include "FrontEnd.h"

void printHelp()
{
    system("CLS");
    setColor(11);
    printLogo();
    printBorder();
    goToCoordinates(57, 15); setColor(14); std::cout << "This is a history-themed project which with the help of linked lists and Grey's code gives";
    goToCoordinates(57, 16); setColor(14); std::cout << "the user the opportunity to create, read, update, and delete historical events.The program"; 
    goToCoordinates(57, 17); setColor(14); std::cout << "currently has historical events which occurred on Bulgarian soiland involved Bulgarian";
    goToCoordinates(57, 18); setColor(14); std::cout << "tribes. But we intend on expanding it in the future so that it includes historical events";
    goToCoordinates(57, 19); setColor(14); std::cout << "which occurred outside the Bulgarian borders.";
    goToCoordinates(57, 20); setColor(14); std::cout << "How to use the program: In the start menu, you will find 5 options: Show all, Create, Update,";
    goToCoordinates(57, 21); setColor(14); std::cout << "Search and Delete. With those options you can manage the events we have in our system, as well";
    goToCoordinates(57, 22); setColor(14); std::cout << "as adding new and deleting old ones.\n\n\n\n\n\n\n\n\n";
    system("PAUSE");
    system("CLS");
}