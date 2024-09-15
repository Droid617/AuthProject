#include <iostream>
#include <fstream>
#include <string>
#include "Auth.h"

bool ValidUser(const std::string& nick, const std::string& passwd, bool check = false)
{
    std::string nickname;
    std::string password;
    std::string emptyLine;

    std::ifstream dataBase("Database.txt", std::ios::in);
    while (dataBase >> nickname >> password)
    {
        if (check && nickname == nick)
        {
            dataBase.close();
            return true;
        }
        else if (nickname == nick && password == passwd)
        {
            dataBase.close();
            return true;
        }
        dataBase >> emptyLine;
    }
    dataBase.close();
    return false;
}

//authorization
void SignIn()
{
    //user nickname and password
    std::string nick;
    std::string passwd;
    std::string answer;

    std::cout << "Enter your nickname: ";
    std::cin >> nick;
    std::cout << "Enter your password: ";
    std::cin >> passwd;

    //if user enter not valid nickname and password, user can not signIn
    if (ValidUser(nick, passwd))
    {
        std::cout << "=========================" << std::endl;
        std::cout << "====== You SignIn! ======" << std::endl;
        std::cout << "=========================" << std::endl;
    }
    else
    {
        std::cout << "Error! Incorrect nickname or password." << std::endl;
        std::cout << "Do you want SignUp?(y/n): ";
        std::cin >> answer;

        while (answer[0] != 'y' && answer[0] != 'n');
        if (answer[0] == 'y')
        {
            SignUp();
        }
        else
        {
            SignIn();
        }
    }
}

//registration
void SignUp()
{
    //user nickname and password
    std::string nick;
    std::string passwd;

    std::cout << "Enter your new nickname: ";
    std::cin >> nick;

    //checking: if user exists, user must try another nickname
    if (!ValidUser(nick, "", true))
    {
        std::cout << "Enter your new password: ";
        std::cin >> passwd;

        //saving user in database
        std::ofstream dataBase("Database.txt", std::ios::out | std::ios::ate);
        dataBase << std::endl << nick << std::endl << passwd << std::endl;
        dataBase.close();

        std::cout << "Done! Now try to LogIn to your new account." << std::endl;
        SignIn();
    }
    else
    {
        std::cout << "Error! This nickname already exists. Try again." << std::endl;
        SignUp();
    }
}