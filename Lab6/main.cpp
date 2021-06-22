#include "header_lab6.h"
#define size_max 100
#define size1_max 100
int supplier::count = 0;
int supplier1::count1 = 0;

int main() {


	int size, size1;
	supplier* pD;
	supplier1* sD;
	setlocale(LC_ALL, "Russian");

	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) {
		cout << "Файла для supplier нет, инициализация с клавиатуры!" << endl;
		size = size_max;
		pD = new supplier[size];
		(*pD).set_count(0);
		init_supplier(pD, 1);
		(*pD).set_count(pD->get_count() + 1);
	}
	else {
		fin >> size;
		pD = new supplier[size];
		load_supplier(pD);
	}
	fin.close();
	ifstream fin1;
	fin.open("data1.txt");
	if (!fin.is_open()) {
		cout << "Файла для supplier1 нет, инициализация с клавиатуры!" << endl;
		size1 = size1_max;
		sD = new supplier1[size1];
		(*sD).set_count(0);
		init_supplier1(sD, 1);
		(*sD).set_count(sD->get_count() + 1);
	}
	else {
		fin >> size1;
		sD = new supplier1[size1];
		load_supplier1(sD);
	}
	fin.close();
	menu(pD, sD, size, size1);

	return 0;
}