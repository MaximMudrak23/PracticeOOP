#pragma once
//����� ���� ������ �����, �� ������ �� ����� ���� ��������.
//������� ����� � ��������� ������ � ������� ����������� ��������(����� �����
//	�����, ������ ����� � �.�.).��������������� ��������� ptin_iterator, ptout_iterator
//	�� �������� remove_copy_if.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task4()
{
	const int SIZE = 5;
	int numbers[SIZE];
	vector<int> tnumbers;

	int elements;
	cout << "Enter elements: ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> elements;
		if (elements == 0)
		{
			break;
		}
		numbers[i] = elements;
	}

	int* ptin_iterator = begin(numbers);
	int* ptout_iterator = end(numbers);

	remove_copy_if(ptin_iterator, ptout_iterator, back_inserter(tnumbers),
		[](int num) { return num % 2; });
	
	cout << "Numbers: ";
	for (int i = 0; i < tnumbers.size(); i++)
	{
		cout << tnumbers[i] << " ";
	}
	cout << endl;
	system("pause");
}