#include "RandomPassowrd.h"
#include "fstream"

class ResetPassword
{
private:
	string userName;
	RandomPassowrd password;
	string passWord;
	vector<string> savedSecurityQuestions;
	vector<string> savedSecurity;
	bool identityConfirmed;
public:
	ResetPassword() {}
	ResetPassword(string username) {
		this->userName = username;
	}
	bool verifyUserName() {
		fstream file("database.json");
		Json::Reader reader;
		Json::Value value;
		reader.parse(file, value);
		Json::Value::ArrayIndex index;
		for (index = 0;index < value.size();index++) {
			cout << value[index]["nume"].asString()<< endl;
			if (value[index]["nume"].asString() == this->userName) {
				return true;
			}
		}
		return false;
		
	}





};
int main() {
	ResetPassword* element = new ResetPassword("Stefan");
	cout << element->verifyUserName();


}

