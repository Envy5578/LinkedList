//Минимум для c++
#include <iostream> // стандартная библиотека с функциями
#include <iomanip> /*Манипуляция вводами данных, ввод консоли*/
#include <string> // объявлять переменную строкой
#include <stdlib.h> //содержаться классы (тренеры, векторы)
#include <cmath> //Возведение в степень
#include <windows.h> //доступ к API
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <vector>
#include <sstream>
#include "test.h"
#include "Data.h"
using namespace std; // рабочее пространство, чтобы не писать каждый раз std

template <typename Type>

void filling(size_t length, LinkedList<Type> &mass) {
	for (size_t i = 0; i < length; i++)
	{
		mass.push_back(rand() % 10);
	}
	cout << endl;
}
void filling(size_t length, LinkedList<date>& mass) {
	
	for (size_t i = 0; i < length; i++)
	{	
		
		/*mass.push_back({mm, dd, yyyy});*/
	}
	cout << endl;
}

int main()
{
#pragma region Starterpuck
	SetConsoleOutputCP(1251); //изменение кодировки на другую
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian"); //добавление русской локализации в консоль
	srand(time(NULL)); //обнуление рандома
#pragma endregion
	size_t size;
	cout << "размер массива - ", cin >> size;
	
	LinkedList<int> list;
	/*({
		{0,0,2001}
		});*/
	cout << list << "                  +=========================+";
	/*list.set_size(size);*/
	int dd = 0, mm = 0, yyyy = 0;
	date test(mm, dd, yyyy);
	/*list.push_back(test);*/
	cout << list<<"\n";
	/*cout << test;*/
	/*filling(size, list);*/
	list.push_back(0);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	/*list.print();*/
	list.pop();
	/*list.push_back();*/
	size--;
	list.print();
	
	cout <<"---------------------------------------"<< endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout <<"***" << list[2];
}


