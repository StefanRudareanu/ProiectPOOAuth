#pragma once
#include "RandomPassowrd.h"
#include <json/json.h>
#include <fstream>
#include <iostream>
class NewUser
{

private:
	string userName;
	vector<string> securityQuestions;
	vector<string> answers;
	RandomPassowrd password;
	string passWord;
public:
	NewUser() {};
	NewUser(string userName) {
		this->userName = userName;

	}
	void SetSecurityQuestions() {
		cout << "Enter three security questions" << endl;
		int nrofquestions = 1;
		string question;
		string answer;
		while (nrofquestions <=3) {
			cout << "Question:"<<endl;
			cin >> question;
			cout << "Enter answer"<<endl;
			cin >> answer;
			this->securityQuestions.push_back(question);
			this->answers.push_back(answer);
			nrofquestions++;
		
		}
	}
	void createUserProfile() {
		this->getNewPassword();
		Json::Reader read;
		Json::Value  object;
		fstream file;
		file.open("database.json");
		read.parse(file, object);
		file.close();
		file.open("database.json", std::ofstream::out | std::ofstream::trunc);
		Json::Value objectroot;
		objectroot["nume"] = (this->userName);
		objectroot["paswword"] = (this->passWord);

		for  (string element : this->answers)
		{objectroot["answers"].append(element);}
		for (string element : this->securityQuestions)
		{
			objectroot["questions"].append(element);
			
		}
		object.append(objectroot);
		cout << object;
		file << object;}
private:
	bool verifyUserName() {
		fstream file("database.json");
		Json::Reader read;
		Json::Value  object;
		read.parse(file, object);
		if (object.isNull() == true) { return true; }
		else {
			Json::Value::ArrayIndex i;
			for (i = 0;i < object.size();i++) {
				if (this->userName == object[i]["name"].asString()) {
					return 0;
				}
			}
			return true;
		};
}
	void getNewPassword() {
		this->passWord = password.genPassword();}
};