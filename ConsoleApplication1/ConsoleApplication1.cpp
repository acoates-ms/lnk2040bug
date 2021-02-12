// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../lnk2040/framework.h"

int main()
{
    std::cout << "Hello World!\n";

    dynamic d;
    std::cout << d.get<std::string>();
}
