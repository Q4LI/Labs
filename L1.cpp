#include <iostream>
#include <string>

using namespace std;

class Session{
private:
	string name, time, date;
public:
	void setName(string nameParam){
		name = nameParam;
	}
	void setTime(string timeParam){
		time = timeParam;
	}
	void setDate(string dateParam){
		date = dateParam;
	}

	string getName(){
		return name;
	}
	string getTime(){
		return time;
	}
	string getDate(){
		return date;
	}
};

class Cinema{
private:
	string name, address;
	Session arr[4];
public:
	void setName(string nameParam){
		name = nameParam;
	}
	void setAddress(string addressParam){
		address = addressParam;
	}
	void setSession(Session& obj, int index){
		if(index < 4) arr[index] = obj;
	}
	void setData(string nameParam, string addressParam){
		setName(nameParam);
		setAddress(addressParam);
	}
	void setData(){
		string temp;
		cout << "Enter the name: ";
		getline(cin, temp);
		setName(temp);
		cout << "Enter the address: ";
		getline(cin, temp);
		setAddress(temp);
	}

	string getName(){
		return name;
	}
	string getAddress(){
		return address;
	}
	Session getSession(int index){
		return arr[index];
	}
};

int main(){
	cout << "<<<<<-----| The first example |----->>>>>" << endl;
	
	Cinema cinema1;

	string tName, tAddress;
	cout << "Enter the name and address: ";
	getline(cin, tName);
	getline(cin, tAddress);
	cinema1.setData(tName, tAddress);
	
	for(int i = 0; i < 4; i++){
		Session obj;
		obj.setName("Name" + to_string(i));
		obj.setTime("13:43");
		obj.setDate("13.10.2017");
		cinema1.setSession(obj, i);
	}

	cout << "<<<<< Cinema 1: " << cinema1.getName() << ". ";
	cout << "Address 1: " << cinema1.getAddress() << ". >>>>>" << endl;
	cout << "Sessions:" << endl;
	for(int i = 0; i < 4; i++){
		cout << "Name: " << cinema1.getSession(i).getName() << endl;
		cout << "Time: " << cinema1.getSession(i).getTime() << endl;
		cout << "Date: " << cinema1.getSession(i).getDate() << endl;
		cout << "----------" << endl;
	}

	cout << "<<<<<-----| The second example |----->>>>>" << endl;
	
	Cinema cinema2;

	cinema2.setData();

	for(int i = 0; i < 4; i++){
		Session obj;
		obj.setName("Name" + to_string(i));
		obj.setTime("13:43");
		obj.setDate("13.10.2017");
		cinema2.setSession(obj, i);
	}

	cout << "<<<<< Cinema 2: " << cinema2.getName() << ". ";
	cout << "Address 2: " << cinema2.getAddress() << ". >>>>>" << endl;
	cout << "Sessions:" << endl;
	for(int i = 0; i < 4; i++){
		cout << "Name: " << cinema2.getSession(i).getName() << endl;
		cout << "Time: " << cinema2.getSession(i).getTime() << endl;
		cout << "Date: " << cinema2.getSession(i).getDate() << endl;
		cout << "----------" << endl;
	}

	return 0;
}