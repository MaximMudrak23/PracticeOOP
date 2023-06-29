#pragma once
//��������� ��������, ��� ������� ������ L, ���������� ����� � ����
//�����. �������� ������� (x[0] - x[n]) (x[1] - x[n-1]) ... (x[n] - x[0]) � ����� ��������
//������� �� �� �������� ������ L . (��� ������������ ������ ��������
//����������� ���������� ������).
//���� ���� �������� ����� ����� ������ ����� ����� � ��������� ��� ������� ����� ����� � ��� �� �������� �������� �� �������� � ������ �� ��������
#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;
    Node* prev;
};

void addNode(Node** head, double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
    }
    else {
        Node* tail = *head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
}

void computeProduct(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "������ ������� ��� ������ ����� ���� �������." << endl;
        return;
    }

    double product = 1.0;
    Node* front = head;
    Node* back = head;

    while (back->next != nullptr) {
        back = back->next;
    }

    while (front != nullptr && back != nullptr) {
        product *= (front->data - back->data);
        cout << front->data << " - " << back->data << " = " << (front->data - back->data) << endl;
        front = front->next;
        back = back->prev;
    }

    cout << "�������: " << product << endl;
}



void printList(Node* head) {
    if (head == nullptr) {
        cout << "������ �������." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}