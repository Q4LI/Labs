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
    }

    Session(string nameParam, string timeParam, string dateParam){
        name = nameParam;
        time = timeParam;
        date = dateParam;
    }

    virtual void print() = 0;
};

class Reservation : public Session {
private:
    bool isReserved;
    int seatNumber;
public:
    void setReservationStatus(bool status) {
        isReserved = status;
    }
    void setSeatNumber(int seatNum) {
        seatNumber = seatNum;
    }

    string getReservationStatus() {
        return isReserved ? "Reserved" : "Available";
    }
    int getSeatNumber() {
        return seatNumber;
    }

    Reservation() : Session(){
        isReserved = false;
        seatNumber = -1;
    }

    Reservation(string nameParam, string timeParam, string dateParam, bool status, int seatNum) : Session(nameParam, timeParam, dateParam) {
        isReserved = status;
        seatNumber = seatNum;
    }

    void print(){
        cout << "Session Name: " << getName() << ", Time: " << getTime() << ", Date: " << getDate() << endl;
        cout << "Reservation Status: " << getReservationStatus() << ", Seat Number: " << seatNumber << endl;
    }
};

class PaidTicket : public Session {
private:
    bool isPaid;    
    int price;
public:
    void setPaymentStatus(bool status) {
        isPaid = status;
    }
    void setPrice(int ticketPrice) {
        price = ticketPrice;
    }

    string getPaymentStatus() {
        return isPaid ? "Paid" : "Unpaid";
    }
    int getPrice() {
        return price;
    }

    PaidTicket() : Session(){
        isPaid = false;
        price = 0;
    }

    PaidTicket(string nameParam, string timeParam, string dateParam, int ticketPrice, bool payStatus) : Session(nameParam, timeParam, dateParam) {
        isPaid = payStatus;
        price = ticketPrice;
    }

    void print(){
        cout << "Session Name: " << getName() << ", Time: " << getTime() << ", Date: " << getDate() << endl;
        cout << "Payment Status: " << getPaymentStatus() << ", Price: " << price << endl;
    }
};

class Cinema{
private:
	string name, address;
	Session* arr[4];
public:
	void setName(string nameParam){
		name = nameParam;
	}
	void setAddress(string addressParam){
		address = addressParam;
	}
	void setSession(Session* obj, int index){
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
	Session* getSession(int index){
		return arr[index];
	}
};

int main(){
    cout << "Creating massive of Session pointers:" << endl;

    Session* sessionArr[4];
    Reservation* obj1 = new Reservation();
    Reservation* obj2 = new Reservation("Movie A", "15:00", "20.12.2024", true, 5);
    PaidTicket* obj3 = new PaidTicket();
    PaidTicket* obj4 = new PaidTicket("Movie B", "18:00", "21.12.2024", 1000, true);

    sessionArr[0] = obj1;
    sessionArr[1] = obj2;
    sessionArr[2] = obj3;
    sessionArr[3] = obj4;

    for(int i = 0; i < 4; i++ ) {
        sessionArr[i]->print();
        cout << "------------------------" << endl;
    }

    cout << "Creating Cinema object and assigning Session pointers:" << endl;
    
    Cinema cinema;
    cinema.setData("CinemaX", "123 Main St");

    for(int i = 0; i < 4; i++) {
        cinema.setSession(sessionArr[i], i);
    }

    cout << "Cinema Name: " << cinema.getName() << ", Address: " << cinema.getAddress() << endl;
    cout << "------------------------" << endl;
    for(int i = 0; i < 4; i++) {
        cinema.getSession(i)->print();
        cout << "------------------------" << endl;
    }

    return 0;
}