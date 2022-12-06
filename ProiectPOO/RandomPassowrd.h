#pragma once
#include <json/json.h>
#include<iostream>
#include<random>
#include <fstream>
using namespace std;
class RandomPassowrd
{
private:
	string password;

public:
	 RandomPassowrd() {}
	 string genPassword(){
		 char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		 string generatedpassword;
		 int length = 0;
		 random_device randomgen;
		 mt19937 seeder(randomgen());
		 uniform_int_distribution<> distribution(0, 31);
		 while (length < 9)
		 {   generatedpassword = generatedpassword + characters[distribution(seeder)];
			 length++;}
		 return generatedpassword; }


};
