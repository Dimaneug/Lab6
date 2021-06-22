#ifndef HEADER_LAB6_H
#define HEADER_LAB6_H
#include "classes.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
#include "string.h"
#include "stdlib.h"

using namespace std;



void init_supplier(supplier* m, int n);

void list_supplier(supplier* m);

void save_supplier(supplier* m);

void load_supplier(supplier* m);

void user_interface(supplier* m, int size);

void find_name(supplier* m, char* name);

void sort_saldo(supplier* m);

void find_supplier(supplier* m);

void init_supplier1(supplier1* m, int n);

void list_supplier1(supplier1* m);

void save_supplier1(supplier1* m);

void load_supplier1(supplier1* m);

void user_interface1(supplier1* m, int size);

void find_fio(supplier1* m, char* entered_last_name, char* entered_first_name, char* entered_middle_name);

void sort_saldo1(supplier1* m);

void menu(supplier* m, supplier1* m1, int size, int size1);

void find_by_fio(supplier1* m);

void find_by_date(supplier* m);

void find_by_date(supplier1* m);


#endif