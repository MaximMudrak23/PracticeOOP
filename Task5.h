#pragma once
//Дано вектор V з парною кількістю елементів.У першій половині
//вихідного вектора замінити всі негативні числа на −1, а другий – все позитивні
//числа на 1. Використовувати два виклики алгоритму replace_if з різними
//параметрами – функціональними обєктами.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task5()
{
	vector<int> V;
	int element;
	for (int i = 0; i < 100; i++)
	{
		cout << "Send element (send 0 if thats all): ";
		cin >> element;
		V.push_back(element);
		if (element == 0)
		{
			break;
		}
	}

	// Заміна негативних чисел у першій половині вектора на -1
	replace_if(V.begin(), V.begin() + V.size() / 2, [](int num) { return num < 0; }, -1);

	// Заміна позитивних чисел у другій половині вектора на 1
	replace_if(V.begin() + V.size() / 2, V.end(), [](int num) { return num > 0; }, 1);

	for (int num : V) 
	{
		cout << num << " ";
	}
	cout << endl;
	system("pause");
}