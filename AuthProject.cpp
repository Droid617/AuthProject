#include <iostream>
#include <fstream>
#include <string>
#include "Auth.h"

int main()
{
    //saving user decision
    std::string answer = "";
    std::cout << "Do you have an account?(y/n): ";
    std::cin >> answer;

    //ignoring all answers except ones that start with y or n
    while (answer[0] != 'y' && answer[0] != 'n');
    if (answer[0] == 'y')
    {
        //authorization
        SignIn();
    }
    else
    {
        //registration
        SignUp();
    }

    return 0;
}