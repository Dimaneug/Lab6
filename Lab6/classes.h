#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;


class date {

private:
	int day;
	char* month;
	int year;
	friend class supplier;
	friend class supplier1;
public:
	date();

	date(int entered_day, char* entered_month, int entered_year);

	date(const date& sdate);

	~date();

	void set_day();

	void set_month();

	void set_year();

	void set_day(int entered_day);

	void set_month(char* entered_month);

	void set_year(int entered_year);

	int get_day();

	char* get_month();

	int get_year();

};

class fio {
private:
	char* last_name;
	char* first_name;
	char* middle_name;
	friend class supplier1;
public:

	fio();

	fio(const fio& sfio);

	~fio();

	void set_last_name(char* entered_last_name);

	void set_first_name(char* entered_first_name);

	void set_middle_name(char* entered_middle_name);

	char* get_last_name();

	char* get_first_name();

	char* get_middle_name();


};

class common {
protected:
	double saldo;
	date data;
public:

	common();

	~common();

	void set_saldo();

	void set_date();

	void set_saldo(double entered_saldo);

	void set_date(int entered_day, char* entered_month, int entered_year);

	double get_saldo();

	int get_day();

	char* get_month();

	int get_year();

	date get_date();
};

class supplier : public common {

private:

	char* name;
	char* adress;
	int producer;
	static int count;

public:

	supplier();

	supplier(char* entered_name, char* entered_adress, int entered_producer, double entered_saldo,
		int entered_day, char* entered_month, int entered_year);

	~supplier();

	void operator = (const supplier& obj);

	friend istream& operator>> (istream& in, supplier& A);

	friend bool operator== (supplier& A, supplier& B);

	friend ostream& operator<< (ostream& out, supplier1& A);

	void set_name();

	void set_adress();

	void set_producer();

	void set_name(char* entered_name);

	void set_adress(char* entered_adress);

	void set_producer(int entered_producer);

	static void set_count(int entered_count);


	char* get_name();

	char* get_adress();

	int get_producer();

	static int get_count();

};

class supplier1 : public common {
private:
	fio seller;
	static int count1;
public:
	supplier1();

	supplier1(char* entered_last_name, char* entered_first_name, char* entered_middle_name,
		int day, char* month, int year, double saldo);

	~supplier1();

	void set_fio(char* entered_last_name, char* entered_first_name, char* entered_middle_name);

	static void set_count(int entered_count);

	char* get_last_name();

	char* get_first_name();

	char* get_middle_name();

	fio get_fio();

	static int get_count();

	void operator = (const supplier1& obj);

	friend ostream& operator<< (ostream& out, supplier1& A);

};



#endif