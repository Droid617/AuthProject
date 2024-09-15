#pragma once
#include <string>

bool ValidUser(const std::string& nick, 
	const std::string& passwd, bool check);//check if user exists
void SignIn();//authorization
void SignUp();//registration