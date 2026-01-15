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

    Session(){
        name = "SessionName";
        time = "13:43";
        date = "13.10.2017";
        cout << "The default constructor was called" << endl;
    }
    Session(string nameParam, string timeParam, string dateParam){
        name = nameParam;
        time = timeParam;
        date = dateParam;
        cout << "The constructor with parameters was called" << endl;
    }
};

class Cinema{
private:
	string name, address;
    int sizeArr;
	Session* arr;
public:
	void setName(string nameParam){
		name = nameParam;
	}
	void setAddress(string addressParam){
		address = addressParam;
	}
	void setSession(Session& obj, int index){
		if(index < sizeArr) arr[index] = obj;
	}
	void setData(string nameParam, string addressParam){
		setName(nameParam);
		setAddress(addressParam);
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

    Cinema(){
        name = "CinemaName";
        address = "CinemaAddress";
        sizeArr = 4;
        arr = new Session[4];
        cout << "The default constructor was called. 4 elements were initialized." << endl;
    }
    Cinema(string nameParam, string addressParam, int sizeParam){
        name = nameParam;
        address = addressParam;
        sizeArr = sizeParam;
        arr = new Session[sizeParam];
        cout << "The constructor with parameters was called. " << sizeParam << " elements were initialized." << endl;
    }
    Cinema(const Cinema& other){
        this->name = other.name;
        this->address = other.address;
        this->sizeArr = other.sizeArr;
        this->arr = new Session[sizeArr];
        for(int i = 0; i < sizeArr; i++){
            this->arr[i] = other.arr[i];
        }
        cout << "The copy constructor was called. " << sizeArr << " elements were initialized." << endl;
    }
    ~Cinema(){
        delete[] arr;
        cout << "The destructor was called." << endl;
    }
};

int main(){
    cout << "Example 1: The default constructor" << endl;

	Cinema cinema1;

	cinema1.setData("CinemaOne", "AddressOne");

	for(int i = 0; i < 4; i++){
	    Session sessionTemp;
	    sessionTemp.setName("Session" + to_string(i + 1));
	    sessionTemp.setTime("1" + to_string(i) + ":00");
	    sessionTemp.setDate("10.0" + to_string(i)+ ".2024");
	    cinema1.setSession(sessionTemp, i);
	}

	cout << "<<<<< Cinema 1: " << cinema1.getName() << ". Address: " << cinema1.getAddress() << " >>>>>" << endl;
	for(int i = 0; i < 4; i++){
		cout << "Session " << (i + 1) << ": " << cinema1.getSession(i).getName() << ", ";
		cout << cinema1.getSession(i).getTime() << ", " << cinema1.getSession(i).getDate() << endl;
	}

	cout << "Example 2: The constructor with parameters" << endl;

	Cinema cinema2("CinemaTwo", "AddressTwo", 3);

	for(int i = 0; i < 3; i++){
		Session sessionTemp("Session" + to_string(i + 1), "2" + to_string(i) + ":30", "11.0" + to_string(i) + ".2024");
		cinema2.setSession(sessionTemp, i);
	}

	cout << "<<<<< Cinema 2: " << cinema2.getName() << ". Address: " << cinema2.getAddress() << " >>>>>" << endl;
	for(int i = 0; i < 3; i++){
		cout << "Session " << (i + 1) << ": " << cinema2.getSession(i).getName() << ", ";
		cout << cinema2.getSession(i).getTime() << ", " << cinema2.getSession(i).getDate() << endl;
	}

	cout << "Example 3: The copy constructor" << endl;

	Cinema cinema3 = cinema1;
	cout << "<<<<< Cinema 3 (copy of Cinema 1): " << cinema3.getName() << ". Address: " << cinema3.getAddress() << " >>>>>" << endl;
	for(int i = 0; i < 4; i++){
		cout << "Session " << (i + 1) << ": " << cinema3.getSession(i).getName() << ", ";
		cout << cinema3.getSession(i).getTime() << ", " << cinema3.getSession(i).getDate() << endl;
	}

	return 0;
}