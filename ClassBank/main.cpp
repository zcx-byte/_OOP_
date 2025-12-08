// main.cpp
// Даниил Прасков - автор
// реализация банковской системы  главный фацл

#include "sberbank.hpp"
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main()
{
    // Переключаем консоль Windows на UTF-8
    system("chcp 65001 > nul");

    Klacc();

    system("cls");
    cout << "        СБЕРБАНК ОНЛАЙН v1.0 by Даниил Прасков 2025" << endl;
    cout << "        ============================================" << endl;

    while(1)
    {
        cout << "\n1. Создать аккаунт" << endl;
        cout << "2. Положить деньги" << endl;
        cout << "3. Снять деньги" << endl;
        cout << "4. Посмотреть баланс" << endl;
        cout << "5. Перевод" << endl;
        cout << "6. Выход" << endl;
        cout << "Выбор: ";
        
        int x;
        cin >> x;
        system("cls");
        
        if(x == 1)
        {
            cout << "Введите имя (без пробелов): ";
            cin >> name[total];
            money[total] = 0;
            pin[total] = 1234;
            card[total] = 4276000012345678 + total;
            blocked[total] = false;
            cout << "Аккаунт создан! Пин-код: 1234 (не меняй)" << endl;
            cout << "Номер карты: " << card[total] << endl;
            total++;
            cout << "Нажмите любую клавишу...";
            _getch();
            system("cls");
        }
        
        if(x == 2)
        {
            cout << "Введите имя: ";
            string s;
            cin >> s;
            for(int i = 0; i < total; i++)
            {
                if(name[i] == s)
                {
                    cout << "Сколько положить: ";
                    int m;
                    cin >> m;
                    money[i] = money[i] + m;
                    cout << "Теперь у тебя " << money[i] << " рублей" << endl;
                    goto end2;
                }
            }
            cout << "Такого окаунта нет" << endl;
            end2:;
            _getch();
            system("cls");
        }
        
        if(x == 3)
        {
            cout << "Имя: ";
            string s;
            cin >> s;
            cout << "Пин: ";
            int p;
            cin >> p;
            if(p != 1234)
            {
                cout << "Неправильный пин 3 раза — блокировка!!!" << endl;
                for(int i = 0; i < total; i++) if(name[i] == s) blocked[i] = true;
                goto end3;
            }
            for(int i = 0; i < total; i++)
            {
                if(name[i] == s && blocked[i] == false)
                {
                    cout << "Сколько снять: ";
                    int m;
                    cin >> m;
                    if(money[i] >= m)
                    {
                        money[i] = money[i] - m;
                        cout << "Снял, осталось " << money[i] << endl;
                    }
                    else cout << "У вас не денег" << endl;
                    goto end3;
                }
            }
            cout << "Ошибка или заблокирован" << endl;
            end3:;
            _getch();
            system("cls");
        }
        
        if(x == 4)
        {
            cout << "Имя: ";
            string s;
            cin >> s;
            for(int i = 0; i < total; i++)
            {
                if(name[i] == s)
                {
                    cout << "Баланс: " << money[i] << " руб." << endl;
                    cout << "Карта: " << card[i] << endl;
                    if(blocked[i]) cout << "!!! КАРТА ЗАБЛОКИРОВАНА !!!" << endl;
                    goto end4;
                }
            }
            cout << "Не найден" << endl;
            end4:;
            _getch();
            system("cls");
        }
        
        if(x == 5)
        {
            cout << "От кого (имя): ";
            string from;
            cin >> from;
            cout << "Кому (имя): ";
            string to;
            cin >> to;
            cout << "Сколько: ";
            int sum;
            cin >> sum;
            
            int f = -1, t = -1;

            for(int i = 0; i < total; i++)
            {
                if(name[i] == from) f = i;
                if(name[i] == to) t = i;
            }
            if(f != -1 && t != -1 && money[f] >= sum)
            {
                money[f] -= sum;
                money[t] += sum;
                cout << "Перевод успешен" << endl;
            }
            else cout << "Ошибка перевода" << endl;
            _getch();
            system("cls");
        }
        
        if(x == 6) break;
    }
    
    cout << "Спасибо что выбрали Сбер от Данила Прасоква" << endl;
    system("pause");
    return 0;
}