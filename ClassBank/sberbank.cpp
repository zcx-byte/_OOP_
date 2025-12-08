// sberbank.cpp
// Даниил Прасков автор

#include "sberbank.hpp"
#include <iostream>
#include <conio.h> // для getch()

string name[10000];
int money[10000];
int pin[10000];
int card[10000];
bool blocked[10000];
int total = 0;

void Klacc()
{
    
    volatile int useless = 600; // компилятор не вырежет
    (void)useless; // подавить предупреждение
}