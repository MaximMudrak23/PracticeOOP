#pragma once
//���� ������ V.� ������ ���� ���� ��������, �� ����������� �� ��
//���� �����, ������ ���� ������� ��� ��������, �� �������� �����������
//�������� �����(�������������, �� �������� ����� �������������� � ���� �
//	�������, �� � � ��������� ������).���� ����� ���������� � ������� ��������,
//	�� ���� ������� ���������� 0. ��� ����� ����� ������� �������� �� ����� �
//	�������� ����, ������������� ����, �� ���������� �� ���������� ����.
//	��������������� �������� ����������� M �� ������ �����������, �������� �
//	������ ������_3_7.��� ����������� ��� ��������������� �������� accumulate .

/*
� ������ V. �� ����� �� ����������� �� �� ���� �����, ����� ������ �� ����� ���� ������� �������� ����� �����, ���� ����������� �� �����
���� ����� �� ���� ����������� ���, �� � ������ ������ ��������, ��� ���������.
���� � ���� ����� 1 �������, �� ���� �� �� �� ��� ���� �� = 0
��������������� ��� ����������� � �� ���� ����������� �������� � ������ 3_7 ��� ����������� ��� ��������������� �������� ����������
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;



void task6()
{
    vector<int> V;
    vector<int> TV;
    int target;
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
    


    cout << "Send number: ";
    cin >> target;

    int sum;

    for (int num : V) 
    {
        if (num % 10 == target)
            TV.push_back(num);
    }

    if (TV.size() > 1)
    {
        sum = accumulate(TV.begin(), TV.end(), -TV[0]);
    }
    else
    {
        sum = 0;
    }

    cout << "���� �����, �� ����������� �� " << target << ": " << sum << endl;
    system("pause");
}