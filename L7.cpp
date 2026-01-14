<<<<<<< HEAD
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int fromDateToInt(const string& Date) {
	string str = Date;
	str.append(" ");
	string days = str.substr(0, 2);
	string months = str.substr(3, 2);
	string years = str.substr(6, 4);

	str = years + months + days;

	return stoi(str);
}

template<class T>
class MyArray {
	T* arr;
	int count = 0;
	int size;
public:
	MyArray(int n) {
		arr = new T[n];
		size = n;
	}
	~MyArray() {
		delete[] arr;
	}
	void addItem(T obj) {
		if (count < size) {
			arr[count] = obj;
			count++;
		}
	}
	int findItem(T obj) {
		int index = -1;
		for (int i = 0; i < count; i++) {
			if (arr[i] == obj) {
				index = i;
				break;
			}
		}
		return index;
	}
	int min() {
		if (count == 0) return -1;
		int minIdx = 0;
		for (int i = 1; i < count; i++) {
			if (deref(arr[i]) < deref(arr[minIdx])) {
				minIdx = i;
			}
		}
		return minIdx;
	}
	int max() {
		if (count == 0) return -1;
		int maxIdx = 0;
		for (int i = 1; i < count; i++) {
			if (deref(arr[i]) > deref(arr[maxIdx])) {
				maxIdx = i;
			}
		}
		return maxIdx;
	}
private:
	template<typename U>
	static U& deref(U* ptr) { return *ptr; }
	static int deref(int val) { return val; }
	static char deref(char val) { return val; }
};

class Session {
private:
	string SessionDate;
	string SessionTime;
	string SessionName;
	static int SessionCount;
public:
	string GetDate() {
		return SessionDate;
	}
	string GetTime() {
		return SessionTime;
	}
	string GetName() {
		return SessionName;
	}

	void setData(string SessionName, string SessionTime, string SessionDate) {
		this->SessionName = SessionName;
		this->SessionTime = SessionTime;
		this->SessionDate = SessionDate;
	}
	void SetData() {
		string str;
		cout << "Название: ";
		getline(cin, str);
		SessionName = str;
		cout << "Длительность: ";
		getline(cin, str);
		SessionTime = str;
		cout << "Дата: ";
		getline(cin, str);
		SessionDate = str;
	}

	Session() {
		//cout << "\n----------\nВызван конструктор по умолчанию класса 'Сеанс'\n----------\n";
		SessionCount++;
		SessionName = "Name";
		SessionTime = "00:00";
		SessionDate = "01.01.2001";
	}
	Session(string SessionName, string SessionTime, string SessionDate) {
		SessionCount++;
		this->SessionName = SessionName;
		this->SessionTime = SessionTime;
		this->SessionDate = SessionDate;
	}
	~Session() {
		SessionCount--;
	}

	virtual void print() = 0;

	static int getCount() {
		return SessionCount;
	}

	bool operator< (const Session& other) const {
		return fromDateToInt(this->SessionDate) < fromDateToInt(other.SessionDate);
	}
	bool operator> (const Session& other) const {
		return fromDateToInt(this->SessionDate) > fromDateToInt(other.SessionDate);
	}
	operator int() const {
		return fromDateToInt(this->SessionDate);
	}
};

int Session::SessionCount = 0;

class Reservation : public Session {
private:
	int SeatNumber;
	bool Reserv;
public:
	int getSeatNumber() {
		return SeatNumber;
	}
	string getReserv() {
		if (Reserv) return "Забронировано";
		else return "Не забронировано";
	}

	void setSeatNumber(int SeatNumber) {
		this->SeatNumber = SeatNumber;
	}
	void setReserv(bool Reserv) {
		this->Reserv = Reserv;
	}

	void PrintData() {
		cout << "----------\nНомер места: " << getSeatNumber() << "\nСтатус: " << getReserv() << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}

	Reservation() {
		//cout << "----------\nВызван конструктор по умолчанию класса 'Бронь'\n----------\n";
		SeatNumber = 0;
		Reserv = false;
	}
	Reservation(string SessionName, string SessionTime, string SessionDate, int SeatNumber, bool Reserv) : Session(SessionName, SessionTime, SessionDate) {
		//cout << "----------\nВызван конструктор с параметрами класса 'Бронь'\n----------\n";
		this->SeatNumber = SeatNumber;
		this->Reserv = Reserv;
	}

	~Reservation() {
		//cout << "----------\nВызван деструктор класса 'Бронь'\n----------\n";
	}

	void print() {
		cout << "----------\nНомер места: " << getSeatNumber() << "\nСтатус: " << getReserv() << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}
};

class PaidTickets : public Session {
private:
	int Price;
	bool PaymentStatus;
public:
	int getPrice() {
		return Price;
	}
	string getPaymentStatus() {
		if (PaymentStatus) return "Оплачено";
		else return "Не оплачено";
	}

	void setPrice(int Price) {
		this->Price = Price;
	}
	void setPaymentStatus(bool PaymentStatus) {
		this->PaymentStatus = PaymentStatus;
	}

	void PrintData() {
		cout << "----------\nСтатус: " << getPaymentStatus() << "\nСтоимость: " << Price << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}

	PaidTickets() {
		//cout << "----------\nВызван конструктор по умолчанию класса 'Оплаченные билеты'\n----------\n";
		Price = 0;
		PaymentStatus = false;
	}
	PaidTickets(string SessionName, string SessionTime, string SessionDate, int Price, bool PaymentStatus) : Session(SessionName, SessionTime, SessionDate) {
		//cout << "----------\nВызван конструктор с параметрами класса 'Оплаченные билеты'\n----------\n";
		this->Price = Price;
		this->PaymentStatus = PaymentStatus;
	}

	~PaidTickets() {
		//cout << "----------\nВызван деструктор класса 'Оплаченные билеты'\n----------\n";
	}

	void print() {
		cout << "----------\nСтатус: " << getPaymentStatus() << "\nСтоимость: " << Price << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	MyArray<int> intArr(3);
	intArr.addItem(12);
	intArr.addItem(22);
	intArr.addItem(31);
	cout << "Index of int: " << intArr.findItem(22) << endl;
	MyArray<char> charArr(3);
	charArr.addItem('a');
	charArr.addItem('b');
	charArr.addItem('c');
	cout << "Index of char: " << charArr.findItem('d') << endl;
	Reservation* sc1 = new Reservation();
	Reservation* sc2 = new Reservation("Name123", "23:50", "13.12.2012", 15, true);
	PaidTickets* n1 = new PaidTickets();
	PaidTickets* n2 = new PaidTickets("Name123", "23:50", "02.04.2025", 1500, true);
	MyArray<Session*> myArr(4);
	myArr.addItem(sc1);
	myArr.addItem(sc2);
	myArr.addItem(n1);
	myArr.addItem(n2);
	cout << "Index min Item: " << myArr.min() << endl;
	cout << "Index max Item: " << myArr.max() << endl;
	cout << "Index of Article: " << myArr.findItem(n1) << endl;
	delete sc1;
	delete sc2;
	delete n1;
	delete n2;

	return 0;
=======
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int fromDateToInt(const string& Date) {
	string str = Date;
	str.append(" ");
	string days = str.substr(0, 2);
	string months = str.substr(3, 2);
	string years = str.substr(6, 4);

	str = years + months + days;

	return stoi(str);
}

template<class T>
class MyArray {
	T* arr;
	int count = 0;
	int size;
public:
	MyArray(int n) {
		arr = new T[n];
		size = n;
	}
	~MyArray() {
		delete[] arr;
	}
	void addItem(T obj) {
		if (count < size) {
			arr[count] = obj;
			count++;
		}
	}
	int findItem(T obj) {
		int index = -1;
		for (int i = 0; i < count; i++) {
			if (arr[i] == obj) {
				index = i;
				break;
			}
		}
		return index;
	}
	int min() {
		if (count == 0) return -1;
		int minIdx = 0;
		for (int i = 1; i < count; i++) {
			if (deref(arr[i]) < deref(arr[minIdx])) {
				minIdx = i;
			}
		}
		return minIdx;
	}
	int max() {
		if (count == 0) return -1;
		int maxIdx = 0;
		for (int i = 1; i < count; i++) {
			if (deref(arr[i]) > deref(arr[maxIdx])) {
				maxIdx = i;
			}
		}
		return maxIdx;
	}
private:
	template<typename U>
	static U& deref(U* ptr) { return *ptr; }
	static int deref(int val) { return val; }
	static char deref(char val) { return val; }
};

class Session {
private:
	string SessionDate;
	string SessionTime;
	string SessionName;
	static int SessionCount;
public:
	string GetDate() {
		return SessionDate;
	}
	string GetTime() {
		return SessionTime;
	}
	string GetName() {
		return SessionName;
	}

	void setData(string SessionName, string SessionTime, string SessionDate) {
		this->SessionName = SessionName;
		this->SessionTime = SessionTime;
		this->SessionDate = SessionDate;
	}
	void SetData() {
		string str;
		cout << "Название: ";
		getline(cin, str);
		SessionName = str;
		cout << "Длительность: ";
		getline(cin, str);
		SessionTime = str;
		cout << "Дата: ";
		getline(cin, str);
		SessionDate = str;
	}

	Session() {
		//cout << "\n----------\nВызван конструктор по умолчанию класса 'Сеанс'\n----------\n";
		SessionCount++;
		SessionName = "Name";
		SessionTime = "00:00";
		SessionDate = "01.01.2001";
	}
	Session(string SessionName, string SessionTime, string SessionDate) {
		SessionCount++;
		this->SessionName = SessionName;
		this->SessionTime = SessionTime;
		this->SessionDate = SessionDate;
	}
	~Session() {
		SessionCount--;
	}

	virtual void print() = 0;

	static int getCount() {
		return SessionCount;
	}

	bool operator< (const Session& other) const {
		return fromDateToInt(this->SessionDate) < fromDateToInt(other.SessionDate);
	}
	bool operator> (const Session& other) const {
		return fromDateToInt(this->SessionDate) > fromDateToInt(other.SessionDate);
	}
	operator int() const {
		return fromDateToInt(this->SessionDate);
	}
};

int Session::SessionCount = 0;

class Reservation : public Session {
private:
	int SeatNumber;
	bool Reserv;
public:
	int getSeatNumber() {
		return SeatNumber;
	}
	string getReserv() {
		if (Reserv) return "Забронировано";
		else return "Не забронировано";
	}

	void setSeatNumber(int SeatNumber) {
		this->SeatNumber = SeatNumber;
	}
	void setReserv(bool Reserv) {
		this->Reserv = Reserv;
	}

	void PrintData() {
		cout << "----------\nНомер места: " << getSeatNumber() << "\nСтатус: " << getReserv() << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}

	Reservation() {
		//cout << "----------\nВызван конструктор по умолчанию класса 'Бронь'\n----------\n";
		SeatNumber = 0;
		Reserv = false;
	}
	Reservation(string SessionName, string SessionTime, string SessionDate, int SeatNumber, bool Reserv) : Session(SessionName, SessionTime, SessionDate) {
		//cout << "----------\nВызван конструктор с параметрами класса 'Бронь'\n----------\n";
		this->SeatNumber = SeatNumber;
		this->Reserv = Reserv;
	}

	~Reservation() {
		//cout << "----------\nВызван деструктор класса 'Бронь'\n----------\n";
	}

	void print() {
		cout << "----------\nНомер места: " << getSeatNumber() << "\nСтатус: " << getReserv() << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}
};

class PaidTickets : public Session {
private:
	int Price;
	bool PaymentStatus;
public:
	int getPrice() {
		return Price;
	}
	string getPaymentStatus() {
		if (PaymentStatus) return "Оплачено";
		else return "Не оплачено";
	}

	void setPrice(int Price) {
		this->Price = Price;
	}
	void setPaymentStatus(bool PaymentStatus) {
		this->PaymentStatus = PaymentStatus;
	}

	void PrintData() {
		cout << "----------\nСтатус: " << getPaymentStatus() << "\nСтоимость: " << Price << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}

	PaidTickets() {
		//cout << "----------\nВызван конструктор по умолчанию класса 'Оплаченные билеты'\n----------\n";
		Price = 0;
		PaymentStatus = false;
	}
	PaidTickets(string SessionName, string SessionTime, string SessionDate, int Price, bool PaymentStatus) : Session(SessionName, SessionTime, SessionDate) {
		//cout << "----------\nВызван конструктор с параметрами класса 'Оплаченные билеты'\n----------\n";
		this->Price = Price;
		this->PaymentStatus = PaymentStatus;
	}

	~PaidTickets() {
		//cout << "----------\nВызван деструктор класса 'Оплаченные билеты'\n----------\n";
	}

	void print() {
		cout << "----------\nСтатус: " << getPaymentStatus() << "\nСтоимость: " << Price << "\nНазвание: " << GetName() << "\nВремя: " << GetTime() << "\nДата: " << GetDate() << "\n----------\n";
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	MyArray<int> intArr(3);
	intArr.addItem(12);
	intArr.addItem(22);
	intArr.addItem(31);
	cout << "Index of int: " << intArr.findItem(22) << endl;
	MyArray<char> charArr(3);
	charArr.addItem('a');
	charArr.addItem('b');
	charArr.addItem('c');
	cout << "Index of char: " << charArr.findItem('d') << endl;
	Reservation* sc1 = new Reservation();
	Reservation* sc2 = new Reservation("Name123", "23:50", "13.12.2012", 15, true);
	PaidTickets* n1 = new PaidTickets();
	PaidTickets* n2 = new PaidTickets("Name123", "23:50", "02.04.2025", 1500, true);
	MyArray<Session*> myArr(4);
	myArr.addItem(sc1);
	myArr.addItem(sc2);
	myArr.addItem(n1);
	myArr.addItem(n2);
	cout << "Index min Item: " << myArr.min() << endl;
	cout << "Index max Item: " << myArr.max() << endl;
	cout << "Index of Article: " << myArr.findItem(n1) << endl;
	delete sc1;
	delete sc2;
	delete n1;
	delete n2;

	return 0;
>>>>>>> dcbd42b59f0041e562cba934596301466096b920
}