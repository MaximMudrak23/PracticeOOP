#pragma once
//Задано текст, слова в якому розділені пробілами і розділовими знаками.
//Розробити програму, яка знаходить і друкує всі слова, що входять у заданий
//текст по одному разу.
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

void task3()
{
    // вводимо назву файлів
    string outputfilename, inputfilename;
    cout << "Send input file name: ";
    cin >> inputfilename;
    cout << "Send output file name: ";
    cin >> outputfilename;

    ofstream out(outputfilename + ".txt");
    ofstream in(inputfilename + ".txt");

    // вводимо текст
    string text;
    cout << "Enter the text: ";
    cin.ignore(); // Ігноруємо символ нового рядка після введення імені файлу
    getline(cin, text);

    vector<string> words; // тут ми зберігаємо всі слова з введеного тексту
    unordered_map<string, int> wordCounts;

    istringstream iss(text); // розділяємо текст на окремі слова і додаємо до масиву вордс не забуваємо про 34 строку там ми рахуємол кількість входжень кожного слова
    string word;

    // Додавання слів до масиву та підрахунок їх кількості
    while (iss >> word) {
        // Пропускаємо розділові знаки
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalnum(c);
            }), word.end());

        if (!word.empty()) {
            words.push_back(word);
            ++wordCounts[word];
        }
    }

    // Запис усіх слів у вихідний файл
    for (const string& word : words) {
        out << word << " ";
    }

    // Запис слів, які не повторюються, у вхідний файл
    for (const string& word : words) {
        if (wordCounts[word] == 1) {
            in << word << " ";
        }
    }

    // Закриття файлів
    out.close();
    in.close();
}