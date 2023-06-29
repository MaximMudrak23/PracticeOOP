#pragma once
//������ �����, ����� � ����� ������� �������� � ���������� �������.
//��������� ��������, ��� ��������� � ����� �� �����, �� ������� � �������
//����� �� ������ ����.
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

void task3()
{
    // ������� ����� �����
    string outputfilename, inputfilename;
    cout << "Send input file name: ";
    cin >> inputfilename;
    cout << "Send output file name: ";
    cin >> outputfilename;

    ofstream out(outputfilename + ".txt");
    ofstream in(inputfilename + ".txt");

    // ������� �����
    string text;
    cout << "Enter the text: ";
    cin.ignore(); // �������� ������ ������ ����� ���� �������� ���� �����
    getline(cin, text);

    vector<string> words; // ��� �� �������� �� ����� � ��������� ������
    unordered_map<string, int> wordCounts;

    istringstream iss(text); // ��������� ����� �� ����� ����� � ������ �� ������ ����� �� �������� ��� 34 ������ ��� �� ������� ������� �������� ������� �����
    string word;

    // ��������� ��� �� ������ �� ��������� �� �������
    while (iss >> word) {
        // ���������� ������� �����
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalnum(c);
            }), word.end());

        if (!word.empty()) {
            words.push_back(word);
            ++wordCounts[word];
        }
    }

    // ����� ��� ��� � �������� ����
    for (const string& word : words) {
        out << word << " ";
    }

    // ����� ���, �� �� ������������, � ������� ����
    for (const string& word : words) {
        if (wordCounts[word] == 1) {
            in << word << " ";
        }
    }

    // �������� �����
    out.close();
    in.close();
}