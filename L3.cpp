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

    void print(){
        cout << "Session Name: " << name << ", Time: " << time << ", Date: " << date << endl;
    }
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
        cout << "The default constructor for Reservation was called" << endl;
    }

    Reservation(string nameParam, string timeParam, string dateParam, bool status, int seatNum) : Session(nameParam, timeParam, dateParam) {
        isReserved = status;
        seatNumber = seatNum;
        cout << "The constructor with parameters for Reservation was called" << endl;
    }

    ~Reservation() {
        cout << "The destructor for Reservation was called" << endl;
    }

    void print(){
        Session::print();
        cout << "Reservation Status: " << getReservationStatus() << ", Seat Number: " << seatNumber << endl;
    }
};

class PaidTicket : public Reservation {
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

    PaidTicket() : Reservation(){
        isPaid = false;
        price = 0;
        cout << "The default constructor for PaidTicket was called" << endl;
    }

    PaidTicket(string nameParam, string timeParam, string dateParam, bool resStatus, int seatNum, bool payStatus, int ticketPrice) : Reservation(nameParam, timeParam, dateParam, resStatus, seatNum) {
        isPaid = payStatus;
        price = ticketPrice;
        cout << "The constructor with parameters for PaidTicket was called" << endl;
    }

    ~PaidTicket() {
        cout << "The destructor for PaidTicket was called" << endl;
    }

    void print(){
        Session::print();
        cout << "Payment Status: " << getPaymentStatus() << ", Price: " << price << endl;
    }
};

int main(){
    cout << "Creating Session object:" << endl;
    Session session1("Morning Show", "10:00", "01.01.2024");
    Session session2;

    cout << "Creating Reservation object:" << endl;
    Reservation reservation1("Evening Show", "18:00", "01.01.2024", true, 15);
    Reservation reservation2;

    cout << "Creating PaidTicket object:" << endl;
    PaidTicket ticket1("Night Show", "21:00", "01.01.2024", true, 20, true, 12);
    PaidTicket ticket2;

    cout << "Creating massive of Session objects:" << endl;
    Session sessionsArray[6];
    sessionsArray[0] = session1;
    sessionsArray[1] = session2;
    sessionsArray[2] = reservation1;
    sessionsArray[3] = reservation2;
    sessionsArray[4] = ticket1;
    sessionsArray[5] = ticket2;

    cout << "Printing all Session objects in the array:" << endl;
    for(int i = 0; i < 6; i++){
        cout << "Session " << (i + 1) << ": ";
        sessionsArray[i].print();
    }

    cout << "Creating massive of Reservation objects:" << endl;
    Reservation reservationsArray[2];
    reservationsArray[0] = reservation1;
    reservationsArray[1] = reservation2;

    cout << "Printing all Reservation objects in the array:" << endl;
    for(int i = 0; i < 2; i++){
        cout << "Reservation " << (i + 1) << ": ";
        reservationsArray[i].print();
    }

    return 0;
}