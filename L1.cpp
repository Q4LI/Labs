#include <iostream>
#include <string>

using namespace std;

class Session {
private:
	string name, time, date;
public:
	void setName(string name) {
		this->name = name;
	}
};