#pragma once
#include "header_lab6.h"


using namespace std;

date::date() {
	day = 0;
	month = new char[strlen("none") + 1];
	strcpy(month, "none");
	year = 0;
}

date::date(int entered_day, char* entered_month, int entered_year) {
	day = entered_day;
	month = new char[strlen(entered_month) + 1];
	strcpy(month, entered_month);
	year = entered_year;
}

date::date(const date& sdate) {
	day = sdate.day;
	month = new char[strlen(sdate.month) + 1];
	strcpy(month, sdate.month);
	year = sdate.year;
}

date::~date() {
	delete[] month;
}

void date::set_day() {
	while (true) {
		cout << "Введите день: ";
		cin >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
}
void date::set_month() {
	delete[] month;
	char buff[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите название месяца: ";
		cin.getline(buff, 4000, '\n');
		//cin.ignore(32767, '\n');
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}

	month = new char[strlen(buff) + 1];
	strcpy(month, buff);
}
void date::set_year() {
	while (true) {
		cout << "Введите год: ";
		cin >> year;
		cin.ignore(32767, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else
			break;
	}

}


void date::set_day(int entered_day) {
	day = entered_day;
}
void date::set_month(char* entered_month) {
	delete[] month;
	month = new char[strlen(entered_month) + 1];
	strcpy(month, entered_month);
}
void date::set_year(int entered_year) {
	year = entered_year;
}

int date::get_day() {
	return day;
}
char* date::get_month() {
	return month;
}
int date::get_year() {
	return year;
}

fio::fio() {
	first_name = new char[strlen("none") + 1];
	strcpy(first_name, "none");
	middle_name = new char[strlen("none") + 1];
	strcpy(middle_name, "none");
	last_name = new char[strlen("none") + 1];
	strcpy(last_name, "none");
}

fio::fio(const fio& sfio) {
	first_name = new char[strlen(sfio.first_name) + 1];
	strcpy(first_name, sfio.first_name);
	middle_name = new char[strlen(sfio.middle_name) + 1];
	strcpy(middle_name, sfio.middle_name);
	last_name = new char[strlen(sfio.last_name) + 1];
	strcpy(last_name, sfio.last_name);
}

fio::~fio() {
	delete[] first_name;
	delete[] middle_name;
	delete[] last_name;
}

void fio::set_first_name(char* entered_first_name) {
	delete[] first_name;
	first_name = new char[strlen(entered_first_name) + 1];
	strcpy(first_name, entered_first_name);

}

void fio::set_last_name(char* entered_last_name) {
	delete[] last_name;
	last_name = new char[strlen(entered_last_name) + 1];
	strcpy(last_name, entered_last_name);
}

void fio::set_middle_name(char* entered_middle_name) {
	delete[] middle_name;
	middle_name = new char[strlen(entered_middle_name) + 1];
	strcpy(middle_name, entered_middle_name);
}

char* fio::get_first_name() {
	return first_name;
}

char* fio::get_last_name() {
	return last_name;
}

char* fio::get_middle_name() {
	return middle_name;
}

bool operator== (fio A, fio B) {
	return (strcmp(A.get_first_name(), B.get_first_name()) == 0) && (strcmp(A.get_last_name(), B.get_last_name()) == 0) &&
		(strcmp(A.get_middle_name(), B.get_middle_name()) == 0);
}

common::common() {
	saldo = 0;
}

common::~common() {

}

supplier::supplier() {
	name = new char[strlen("none") + 1];
	strcpy(name, "none");
	adress = new char[strlen("none") + 1];
	strcpy(adress, "none");
	producer = 0;
}

supplier::supplier(char* entered_name, char* entered_adress, int entered_producer, double entered_saldo,
	int entered_day, char* entered_month, int entered_year) {
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
	adress = new char[strlen(entered_adress) + 1];
	strcpy(adress, entered_adress);
	producer = entered_producer;
	saldo = entered_saldo;
	data.day = entered_day;
	data.month = new char[strlen(entered_month) + 1];
	strcpy(data.month, entered_month);
	data.year = entered_year;
}

supplier::~supplier() {
	delete[] name;
	delete[] adress;
}

void supplier::operator = (const supplier& obj) {
	delete[] name;
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	delete[] adress;
	adress = new char[strlen(obj.adress) + 1];
	strcpy(adress, obj.adress);
	producer = obj.producer;
	saldo = obj.saldo;
	data.day = obj.data.day;
	delete[] data.month;
	data.month = new char[strlen(obj.data.month) + 1];
	strcpy(data.month, obj.data.month);
	data.year = obj.data.year;
}

void supplier::set_name() {
	delete[] name;
	char buff[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите новое название фирмы: ";
		cin.getline(buff, 4000, '\n');
		//cin.ignore(32767, '\n');
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}

	name = new char[strlen(buff) + 1];
	strcpy(name, buff);
}
void supplier::set_adress() {
	delete[] adress;
	char buff[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите новый адрес: ";
		cin.getline(buff, 4000, '\n');
		while (buff[i]) {
			if (isalnum(buff[i])) i++;
			else {
				cout << "Введите только буквы и цифры!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	//cin.ignore(32767, '\n');
	adress = new char[strlen(buff) + 1];
	strcpy(adress, buff);
}
void supplier::set_producer() {
	while (true) {
		cout << "1 - поставщик сырья 2 - поставщик оборудования" << endl;
		cout << "Введите тип поставщика: ";
		cin >> producer;
		if (cin.fail() || (producer != 1 && producer != 2)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

}
void common::set_saldo() {
	while (true) {
		cout << "Введите сальдо: ";
		cin >> saldo;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

}
void common::set_date() {
	data.set_day();
	data.set_month();
	data.set_year();
}


void supplier::set_name(char* entered_name) {
	delete[] name;
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
}
void supplier::set_adress(char* entered_adress) {
	delete[] adress;
	adress = new char[strlen(entered_adress) + 1];
	strcpy(adress, entered_adress);
}
void supplier::set_producer(int entered_producer) {
	producer = entered_producer;
}
void common::set_saldo(double entered_saldo) {
	saldo = entered_saldo;
}
void supplier::set_count(int entered_count) {
	count = entered_count;
}
void common::set_date(int entered_day, char* entered_month, int entered_year) {
	data.set_day(entered_day);
	data.set_month(entered_month);
	data.set_year(entered_year);
}

char* supplier::get_name() {
	return name;
}
char* supplier::get_adress() {
	return adress;
}
int supplier::get_producer() {
	return producer;
}
double common::get_saldo() {
	return saldo;
}
int supplier::get_count() {
	return count;
}
int common::get_day() {
	return data.get_day();
}
char* common::get_month() {
	return data.get_month();
}
int common::get_year() {
	return data.get_year();
}
date common::get_date() {
	return data;
}

bool operator==(date A, date B) {
	return (A.get_day() == B.get_day()) && (strcmp(A.get_month(), B.get_month()) == 0) && (A.get_year() == B.get_year());
}

supplier1::supplier1() {
	data.day = 0;
	data.month = new char[strlen("none") + 1];
	strcpy(data.month, "none");
	data.year = 0;
}

supplier1::supplier1(char* entered_last_name, char* entered_first_name, char* entered_middle_name,
	int entered_day, char* entered_month, int entered_year, double entered_saldo) {
	seller.first_name = new char[strlen(entered_first_name) + 1];
	strcpy(seller.first_name, entered_first_name);
	seller.last_name = new char[strlen(entered_last_name) + 1];
	strcpy(seller.last_name, entered_last_name);
	seller.middle_name = new char[strlen(entered_middle_name) + 1];
	strcpy(seller.middle_name, entered_middle_name);
	data.day = entered_day;
	data.month = new char[strlen(entered_month) + 1];
	strcpy(data.month, entered_month);
	data.year = entered_year;
	saldo = entered_saldo;
}

supplier1::~supplier1() {

}

void supplier1::set_fio(char* entered_last_name, char* entered_first_name, char* entered_middle_name) {
	delete[] seller.last_name;
	delete[] seller.first_name;
	delete[] seller.middle_name;
	seller.last_name = new char[strlen(entered_last_name) + 1];
	strcpy(seller.last_name, entered_last_name);
	seller.first_name = new char[strlen(entered_first_name) + 1];
	strcpy(seller.first_name, entered_first_name);
	seller.middle_name = new char[strlen(entered_middle_name) + 1];
	strcpy(seller.middle_name, entered_middle_name);
}

void supplier1::set_count(int entered_count) {
	count1 = entered_count;
}

int supplier1::get_count() {
	return count1;
}

char* supplier1::get_last_name() {
	return(seller.get_last_name());
}

char* supplier1::get_first_name() {
	return(seller.get_first_name());
}

char* supplier1::get_middle_name() {
	return(seller.get_middle_name());
}

fio supplier1::get_fio() {
	return seller;
}

void supplier1::operator = (const supplier1& obj) {
	delete[] seller.last_name;
	delete[] seller.first_name;
	delete[] seller.middle_name;
	seller.last_name = new char[strlen(obj.seller.last_name) + 1];
	strcpy(seller.last_name, obj.seller.last_name);
	seller.first_name = new char[strlen(obj.seller.first_name) + 1];
	strcpy(seller.first_name, obj.seller.first_name);
	seller.middle_name = new char[strlen(obj.seller.middle_name) + 1];
	strcpy(seller.middle_name, obj.seller.middle_name);
	saldo = obj.saldo;
	data.day = obj.data.day;
	delete[] data.month;
	data.month = new char[strlen(obj.data.month) + 1];
	strcpy(data.month, obj.data.month);
	data.year = obj.data.year;
}

istream& operator>> (istream& in, supplier& A) {
	char* buff = new char[4096];
	int day, year, producer;
	double saldo;
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Название:";
		in >> buff;
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	A.set_name(buff);
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Адрес:";
		in >> buff;
		while (buff[i]) {
			if (isalnum(buff[i])) i++;
			else {
				cout << "Введите только буквы и цифры!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}

	A.set_adress(buff);

	while (true) {
		cout << "1 - поставщик сырья 2 - поставщик оборудования" << endl;
		cout << "Введите тип поставщика: ";
		in >> producer;
		if (cin.fail() || (producer != 1 && producer != 2)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	A.set_producer(producer);

	while (true) {
		cout << "Введите сальдо: ";
		in >> saldo;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
	A.set_saldo(saldo);

	while (true) {
		cout << "Введите день: ";
		in >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите название месяца: ";
		in.getline(buff, 4000, '\n');
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}

	while (true) {
		cout << "Введите год: ";
		in >> year;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	A.set_date(day, buff, year);
	delete[] buff;
	return in;
}

bool operator== (supplier& A, supplier& B) {
	return ((strcmp(A.get_name(), B.get_name()) == 0) && (strcmp(A.get_adress(), B.get_adress()) == 0) &&
		(A.get_producer() == B.get_producer()) && (A.get_saldo() == B.get_saldo()) &&
		(A.data.get_day() == B.data.get_day()) && (strcmp(A.data.get_month(), B.data.get_month()) == 0) &&
		(A.data.get_year() == B.data.get_year()));
}

ostream& operator<< (ostream& out, supplier& A) {

	out << setw(20) << A.get_name() << setw(20) << A.get_adress() << setw(24);
	if (A.get_producer() == 1)
		out << "Поставщик сырья";
	else
		out << "Поставщик оборудования";
	out << setw(15) << A.get_saldo() << setw(4) << A.get_day() << ":" << setw(10) << A.get_month()
		<< ":" << setw(4) << A.get_year() << endl;
	return out;

}

ostream& operator<< (ostream& out, supplier1& A) {

	out << setw(20) << A.get_last_name() << setw(20) << A.get_first_name() << setw(20) << A.get_middle_name()
		<< setw(10) << A.get_saldo() << setw(4) << A.get_day() << ":" << setw(10) << A.get_month()
		<< ":" << setw(4) << A.get_year() << endl;
	return out;

}

void clear_console() {
	system("pause");
	system("cls");
}

void init_supplier(supplier* m, int n) {

	supplier* tw; //Рабочий указатель для работы с дин памятью
	for (tw = m + supplier::get_count(); tw < m + supplier::get_count() + n; tw++) {
		cout << "--------------------------" << endl;
		cout << "Введите данные для " << tw - m - supplier::get_count() + 1 << " поставщика:" << endl;
		tw->set_name();
		tw->set_adress();
		tw->set_producer();
		tw->set_saldo();
		tw->set_date();
	}

};

supplier* resizee(supplier* m, int newsize) {

	supplier* newm = new supplier[newsize];
	for (int i = 0; i < supplier::get_count(); i++)
		newm[i] = m[i];
	delete[] m;
	return newm;
}

supplier1* resizee(supplier1* m, int newsize) {

	supplier1* newm = new supplier1[newsize];
	for (int i = 0; i < supplier1::get_count(); i++)
		newm[i] = m[i];
	delete[] m;
	return newm;

}

void list_supplier(supplier* m) {

	supplier* tw;
	cout << setw(20) << "Название" << setw(20) << "Юридический адрес" << setw(24) << "Тип поставщика" << setw(15) << "Сальдо"
		<< setw(18) << "Дата" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	for (tw = m; tw < m + supplier::get_count(); tw++) {
		cout << *tw;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;

};


void save_supplier(supplier* m) {

	ofstream fout;
	fout.open("data.txt", ofstream::trunc);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		fout << supplier::get_count() << "\n";
		for (int i = 0; i < supplier::get_count(); i++) {
			fout << m[i].get_name() << "\n";
			fout << m[i].get_adress() << "\n";
			fout << m[i].get_producer() << "\n";
			fout << m[i].get_saldo() << "\n";
			fout << m[i].get_day() << "\n";
			fout << m[i].get_month() << "\n";
			fout << m[i].get_year() << "\n";
		}
	}

	fout.close();


};

void load_supplier(supplier* m) {

	ifstream fin;
	int size;
	fin.open("data.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		fin >> size;
		supplier::set_count(size);
		for (int i = 0; i < size; i++) {
			char* name = new char[100];
			char* adress = new char[100];
			char* month = new char[100];
			fin >> name;
			double saldo;
			int producer, day, year;
			fin >> adress;
			fin >> producer;
			fin >> saldo;
			fin >> day;
			fin >> month;
			fin >> year;
			m[i].set_name(name);
			m[i].set_adress(adress);
			m[i].set_producer(producer);
			m[i].set_saldo(saldo);
			m[i].set_date(day, month, year);
			delete[] name;
			delete[] adress;
			delete[] month;
		}

	}

	fin.close();

};

void user_interface(supplier* m, int size) {

	int k = size;
	int choose;
	while (true) {

		cout << endl << "1. Добавить поставщика" << endl;
		cout << "2. Показать поставщиков" << endl;
		cout << "3. Найти фирму" << endl;
		cout << "4. Сортировка по сальдо" << endl;
		cout << "5. Найти поставщика по всем полям" << endl;
		cout << "6. Сохранить данные" << endl;
		cout << "7. Найти поставщика по дате" << endl;
		cout << "8. Выйти в меню" << endl;
		cout << "-----------------------------------------" << endl;
		while (true) {
			cout << "Введите номер функции: ";
			cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка ввода, попробуйте еще раз\n";
			}
			else {
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (choose == 1) {
			system("cls");
			int n;

			while (true) {
				cout << "Сколько поставщиков вы хотите добавить?" << endl;
				cin >> n;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Ошибка ввода, попробуйте еще раз" << endl;
				}
				else {
					cin.ignore(32767, '\n');
					break;
				}
			}
			if (supplier::get_count() + n > k) {
				k += 2 * n;
				m = resizee(m, k);

			}
			init_supplier(m, n);
			supplier::set_count(supplier::get_count() + n);
			clear_console();
		}
		if (choose == 2) {
			system("cls");
			list_supplier(m);
			clear_console();
		}
		if (choose == 3) {
			char buff[25];
			while (true) {
				int i = 0;
				bool k = false;
				cout << "Введите название фирмы: ";
				cin.getline(buff, 4000, '\n');
				while (buff[i]) {
					if (isalpha(buff[i])) i++;
					else {
						cout << "Введите только буквы!" << endl;
						k = true;
						break;
					}
				}
				if (k == false) break;
			}
			char* name = new char[strlen(buff) + 1];
			strcpy(name, buff);
			system("cls");
			find_name(m, name);
			delete[] name;
			clear_console();
		}
		if (choose == 4) {
			system("cls");
			sort_saldo(m);
			clear_console();
		}
		if (choose == 5) {
			find_supplier(m);
			clear_console();
		}
		if (choose == 6) {
			save_supplier(m);
			clear_console();
		}
		if (choose == 7) {
			find_by_date(m);
			clear_console();
		}
		if (choose == 8) {
			break;
		}
		else continue;
	}
};

void find_name(supplier* m, char* name) {

	supplier* tw;
	cout << endl << "Информация о " << name << endl;
	cout << "----------------------------------------------" << endl;
	cout << setw(20) << "Юридический адрес" << setw(24) << "Тип поставщика" << setw(15) << "Сальдо"
		<< setw(18) << "Дата" << endl;
	cout << "-------------------------------------------------------" << endl;
	for (tw = m; tw < m + supplier::get_count(); tw++)
	{
		if (strcmp(name, (*tw).get_name()) == 0)
		{
			cout << setw(20) << (*tw).get_adress() << setw(24);
			if (tw->get_producer() == 1)
				cout << "Поставщик сырья";
			else
				cout << "Поставщик оборудования";
			cout << setw(15) << (*tw).get_saldo() << setw(4) << (*tw).get_day() << ":" << setw(10) << (*tw).get_month()
				<< ":" << setw(4) << (*tw).get_year() << endl;
		}
	}

};

void find_supplier(supplier* m) {
	cout << "Введите данные нужного поставщика:" << endl;
	supplier sup;
	cin >> sup;
	for (int i = 0; i < supplier::get_count(); i++) {
		if (sup == m[i])
			cout << "Найден такой объект" << endl;
	}
}

void sort_saldo(supplier* m) {

	supplier temp;


	for (supplier* i = m; i < m + supplier::get_count() - 1; i++)
	{
		for (supplier* j = m; j < m + supplier::get_count() - 1; j++)
		{
			if (j->get_saldo() < (j + 1)->get_saldo())
			{
				temp = *j;
				*j = *(j + 1);
				*(j + 1) = temp;

			}
		}
	}
	list_supplier(m);


};

void find_by_date(supplier* m) {

	int day, year;
	char month[4000];
	while (true) {
		cout << "Введите день: ";
		cin >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите название месяца: ";
		cin.getline(month, 4000, '\n');
		if (month[0] == '\0') {
			cout << "Вы ввели пустую строку!" << endl;
			continue;
		}
		while (month[i]) {
			if (isalpha(month[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}

		if (k == false) break;
	}

	while (true) {
		cout << "Введите год: ";
		cin >> year;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}

	}

	date entered_date(day, month, year);
	system("cls");

	supplier* temp = new supplier[supplier::get_count()];
	int k = 0;
	for (supplier* i = m; i < m + supplier::get_count(); i++) {
		if (i->get_date() == entered_date) {
			*(temp + k) = *i;
			k++;
		}
	}

	if (k == 0) {
		cout << "Совпадений не найдено" << endl;
	}
	else {
		cout << setw(20) << "Название" << setw(20) << "Юридический адрес" << setw(24) << "Тип поставщика" << setw(15) << "Сальдо"
			<< setw(18) << "Дата" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		for (supplier* tw = temp; tw < temp + k; tw++) {
			cout << *tw;
		}
		cout << "--------------------------------------------------------------------------------------------------" << endl;
	}

	delete[] temp;
}

void init_supplier1(supplier1* m, int n) {

	char buff[100], buff1[100], buff2[100];
	supplier1* tw; //Рабочий указатель для работы с дин память
	for (tw = m + supplier1::get_count(); tw < m + supplier1::get_count() + n; tw++) {
		cout << "--------------------------" << endl;
		cout << "Введите данные для " << tw - m - supplier1::get_count() + 1 << " продавца:" << endl;
		while (true) {
			int i = 0;
			bool k = false;
			cout << "Введите фамилию: ";
			cin.getline(buff, 4000, '\n');
			while (buff[i]) {
				if (isalpha(buff[i])) i++;
				else {
					cout << "Введите только буквы!" << endl;
					k = true;
					break;
				}
			}
			if (k == false) break;
		}
		while (true) {
			int i = 0;
			bool k = false;
			cout << "Введите имя: ";
			cin.getline(buff1, 4000, '\n');
			while (buff1[i]) {
				if (isalpha(buff1[i])) i++;
				else {
					cout << "Введите только буквы!" << endl;
					k = true;
					break;
				}
			}
			if (k == false) break;
		}
		//cin.ignore(32767, '\n');
		while (true) {
			int i = 0;
			bool k = false;
			cout << "Введите отчество: ";
			cin.getline(buff2, 4000, '\n');
			while (buff2[i]) {
				if (isalpha(buff2[i])) i++;
				else {
					cout << "Введите только буквы!" << endl;
					k = true;
					break;
				}
			}
			if (k == false) break;
		}
		//cin.ignore(32767, '\n');
		tw->set_fio(buff, buff1, buff2);
		tw->set_saldo();
		tw->set_date();
		cin.ignore();
	}
}

void list_supplier1(supplier1* m) {

	supplier1* tw;
	cout << setw(60) << "Продавец" << setw(10) << "Сальдо" << setw(18) << "Дата" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	for (tw = m; tw < m + supplier1::get_count(); tw++) {
		cout << *tw;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;

}

void save_supplier1(supplier1* m) {

	ofstream fout;
	fout.open("data1.txt", ofstream::trunc);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла data1" << endl;
	}
	else {
		fout << supplier1::get_count() << "\n";
		for (int i = 0; i < supplier1::get_count(); i++) {
			fout << m[i].get_last_name() << "\n";
			fout << m[i].get_first_name() << "\n";
			fout << m[i].get_middle_name() << "\n";
			fout << m[i].get_saldo() << "\n";
			fout << m[i].get_day() << "\n";
			fout << m[i].get_month() << "\n";
			fout << m[i].get_year() << "\n";
		}
	}

	fout.close();

}

void load_supplier1(supplier1* m) {

	ifstream fin;
	int size;
	fin.open("data1.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла data1" << endl;
	}
	else {
		fin >> size;
		supplier1::set_count(size);
		for (int i = 0; i < size; i++) {
			char* last_name = new char[100];
			char* first_name = new char[100];
			char* middle_name = new char[100];
			char* month = new char[100];
			fin >> last_name;
			double saldo;
			int day, year;
			fin >> first_name;
			fin >> middle_name;
			fin >> saldo;
			fin >> day;
			fin >> month;
			fin >> year;
			m[i].set_fio(last_name, first_name, middle_name);
			m[i].set_saldo(saldo);
			m[i].set_date(day, month, year);
			delete[] last_name;
			delete[] first_name;
			delete[] middle_name;
			delete[] month;
		}

	}

	fin.close();

}



void user_interface1(supplier1* m, int size) {

	int k = size;
	int choose;
	while (true) {

		cout << endl << "1. Добавить продавца" << endl;
		cout << "2. Показать продавцов" << endl;
		cout << "3. Найти продавца" << endl;
		cout << "4. Сортировка по сальдо" << endl;
		cout << "5. Сохранить данные" << endl;
		cout << "6. Найти по фио" << endl;
		cout << "7. Найти по дате" << endl;
		cout << "8. Выйти в меню" << endl;
		cout << "-----------------------------------------" << endl;
		while (true) {
			cout << "Введите номер функции: ";
			cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка ввода, попробуйте еще раз\n";
			}
			else {
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (choose == 1) {
			system("cls");
			int n;
			while (true) {
				cout << "Сколько продавцов вы хотите добавить?" << endl;
				cin >> n;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Ошибка ввода, попробуйте еще раз" << endl;
				}
				else {
					cin.ignore(32767, '\n');
					break;
				}
			}

			if (supplier1::get_count() + n > k) {
				k += 2 * n;
				m = resizee(m, k);

			}
			init_supplier1(m, n);
			supplier1::set_count(supplier1::get_count() + n);
			clear_console();
		}
		if (choose == 2) {
			system("cls");
			list_supplier1(m);
			clear_console();
		}
		if (choose == 3) {
			char buff[100];
			cin.ignore(); //удаляет \n
			while (true) {
				int i = 0;
				bool k = false;
				cout << "Введите фамилию: ";
				cin.getline(buff, 4000, '\n');
				while (buff[i]) {
					if (isalpha(buff[i])) i++;
					else {
						cout << "Введите только буквы!" << endl;
						k = true;
						break;
					}
				}
				if (k == false) break;
			}
			char* last_name = new char[strlen(buff) + 1];
			strcpy(last_name, buff);
			while (true) {
				int i = 0;
				bool k = false;
				cout << "Введите имя: ";
				cin.getline(buff, 4000, '\n');
				while (buff[i]) {
					if (isalpha(buff[i])) i++;
					else {
						cout << "Введите только буквы!" << endl;
						k = true;
						break;
					}
				}
				if (k == false) break;
			}
			char* first_name = new char[strlen(buff) + 1];
			strcpy(first_name, buff);
			while (true) {
				int i = 0;
				bool k = false;
				cout << "Введите отчество: ";
				cin.getline(buff, 4000, '\n');
				while (buff[i]) {
					if (isalpha(buff[i])) i++;
					else {
						cout << "Введите только буквы!" << endl;
						k = true;
						break;
					}
				}
				if (k == false) break;
			}
			char* middle_name = new char[strlen(buff) + 1];
			strcpy(middle_name, buff);
			system("cls");
			find_fio(m, last_name, first_name, middle_name);
			delete[] last_name;
			delete[] first_name;
			delete[] middle_name;
			clear_console();
		}
		if (choose == 4) {
			system("cls");
			sort_saldo1(m);
			clear_console();
		}
		if (choose == 5) {
			save_supplier1(m);
			clear_console();
		}
		if (choose == 6) {
			find_by_fio(m);
			clear_console();
		}
		if (choose == 7) {
			find_by_date(m);
			clear_console();
		}
		if (choose == 8) {
			break;
		}
		else continue;
	}
}


void find_fio(supplier1* m, char* entered_last_name, char* entered_first_name, char* entered_middle_name) {

	supplier1* tw;
	cout << endl << "Информация о " << entered_last_name << " " << entered_first_name << " " <<
		entered_middle_name << endl;
	cout << "----------------------------------------------" << endl;
	cout << setw(10) << "Сальдо" << setw(18) << "Дата" << endl;
	cout << "-------------------------------------------------------" << endl;
	for (tw = m; tw < m + supplier1::get_count(); tw++)
	{
		if ((strcmp(entered_last_name, tw->get_last_name()) == 0) && (strcmp(entered_first_name, tw->get_first_name()) == 0)
			&& (strcmp(entered_middle_name, tw->get_middle_name()) == 0))
		{
			cout << setw(10) << tw->get_saldo() << setw(4) << (*tw).get_day() << ":" << setw(10) << (*tw).get_month()
				<< ":" << setw(4) << (*tw).get_year() << endl;
		}
	}

}

void sort_saldo1(supplier1* m) {

	supplier1 temp;

	for (supplier1* i = m; i < m + supplier1::get_count() - 1; i++)
	{
		for (supplier1* j = m; j < m + supplier1::get_count() - 1; j++)
		{
			if (j->get_saldo() < (j + 1)->get_saldo())
			{
				temp = *j;
				*j = *(j + 1);
				*(j + 1) = temp;

			}
		}
	}
	list_supplier1(m);

}

void find_by_fio(supplier1* m) {
	system("cls");
	fio entered_fio;
	cin.ignore(); //удаляет \n
	char last_name[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите фамилию: ";
		cin.getline(last_name, 4000, '\n');
		while (last_name[i]) {
			if (isalpha(last_name[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	char first_name[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите имя: ";
		cin.getline(first_name, 4000, '\n');
		while (first_name[i]) {
			if (isalpha(first_name[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	char middle_name[4000];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите отчество: ";
		cin.getline(middle_name, 4000, '\n');
		while (middle_name[i]) {
			if (isalpha(middle_name[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	entered_fio.set_first_name(first_name);
	entered_fio.set_last_name(last_name);
	entered_fio.set_middle_name(middle_name);
	system("cls");
	supplier1* temp = new supplier1[supplier1::get_count()];
	int k = 0;
	for (supplier1* i = m; i < m + supplier1::get_count(); i++) {
		if (i->get_fio() == entered_fio) {
			*(temp + k) = *i;
			k++;
		}
	}


	if (k == 0) {
		cout << "Совпадения не найдены" << endl;
	}
	else {
		cout << setw(60) << "Продавец" << setw(10) << "Сальдо" << setw(18) << "Дата" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		for (supplier1* tw = temp; tw < temp + k; tw++) {
			cout << *tw;
		}
		cout << "--------------------------------------------------------------------------------------------------" << endl;

	}


	delete[] temp;
}

void find_by_date(supplier1* m) {

	int day, year;
	char month[4000];
	while (true) {
		cout << "Введите день: ";
		cin >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	while (true) {
		int i = 0;
		bool k = false;
		cout << "Введите название месяца: ";
		cin.getline(month, 4000, '\n');
		if (month[0] == '\0') {
			cout << "Вы ввели пустую строку!" << endl;
			continue;
		}
		while (month[i]) {
			if (isalpha(month[i])) i++;
			else {
				cout << "Введите только буквы!" << endl;
				k = true;
				break;
			}
		}

		if (k == false) break;
	}

	while (true) {
		cout << "Введите год: ";
		cin >> year;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка ввода, попробуйте еще раз" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}

	date entered_date(day, month, year);
	system("cls");

	supplier1* temp = new supplier1[supplier1::get_count()];
	int k = 0;
	for (supplier1* i = m; i < m + supplier1::get_count(); i++) {
		if (i->get_date() == entered_date) {
			*(temp + k) = *i;
			k++;
		}
	}

	if (k == 0) {
		cout << "Совпадений не найдено" << endl;
	}
	else {
		cout << setw(60) << "Продавец" << setw(10) << "Сальдо" << setw(18) << "Дата" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		for (supplier1* tw = temp; tw < temp + k; tw++) {
			cout << *tw;
		}
		cout << "--------------------------------------------------------------------------------------------------" << endl;
	}

	delete[] temp;
}

void menu(supplier* m, supplier1* m1, int size, int size1) {

	int k = size;
	int k1 = size1;
	int choose;
	while (true) {


		while (true) {
			clear_console();
			cout << "Выберите, с каким классом работать:" << endl
				<< "1. supplier" << endl
				<< "2. supplier1" << endl
				<< "3. Завершить программу" << endl;
			cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Ошибка ввода, попробуйте еще раз" << endl;
			}
			else {
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (choose == 1) {
			system("cls");
			user_interface(m, size);

		}
		if (choose == 2) {
			system("cls");
			user_interface1(m1, size1);
		}
		if (choose == 3) {
			break;
		}
		else continue;
	}
}