#include "Task2.h";
#include "Task3.h";
#include "Task4.h";
#include "Task5.h";
#include "Task6.h";

void main() {
    setlocale(LC_CTYPE, "Ukr");
e:  system("cls");
    cout << "Enter task number: ";
    int task; cin >> task;
    system("cls");

    if (task == 2)
    {
        Node* myList = nullptr;

        int elements;
        cout << "Send elements (0 if thats all): ";
        for (int i = 0; i < 100; i++)
        {
            cin >> elements;
            if (elements == 0)
            {
                break;
            }
            addNode(&myList, elements);
        }

        cout << "Елементи списку: ";
        printList(myList);

        computeProduct(myList);
        system("pause");
    }
    else if (task == 3)
    {
        task3();
    }
    else if (task == 4)
    {
        task4();
    }
    else if (task == 5)
    {
        task5();
    }
    else if (task == 6)
    {
        task6();
    }
    goto e;
}