
#include "stack.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>

void initNullStack(Stack*& _sp, Stack*& _spDeleted) {
    _sp = nullptr;
    _spDeleted = nullptr;
}

bool isEmpty(const Stack* _sp) {
    return (_sp == nullptr);
}

bool isEmptyDeletedStack(const Stack* _spDeleted) {
    return (_spDeleted == nullptr);
}

void returnStackStatic(const Stack* _sp) {
    std::cout << "��������� �����: ";
    if (_sp != nullptr) {
        std::cout << "���� �� ����. ";
        std::cout << "������� �����: " << _sp->value << std::endl;
    }
    else {
        std::cout << "���� ����.";
    }
}

void returnStackStaticFull(Stack* _sp) {
    std::cout << "��������� �����: ";
    if (_sp != nullptr) {
        std::cout << "���� �� ����. �������� �����:";
        std::cout << " ������� �����: " << _sp->value << ", ";
        printStack(_sp);
    }
    else {
        std::cout << "���� ����.";
    }
}

Stack* push(Stack* _sp, int _value) {
    Stack* item = new Stack;
    if (item == nullptr) {
        std::cerr << "������ ��������� ������." << std::endl;
        return _sp;
    }
    item->value = _value;
    item->next = _sp;
    _sp = item;
    std::cout << "������� " << item->value << " �������� � ������� �����." << std::endl;
    return _sp;
}

void pushRandom(Stack*& _sp, int count) {
    srand(time(0));
    int value{ 0 };
    for (int i = 0; i < count; ++i) {
        value = rand() % 100;
        _sp = push(_sp, value);
    }
}

void pushFromStack(Stack*& _sp, Stack*& _spDeleted) {
    if (!isEmptyDeletedStack(_spDeleted)) {
        Stack* current = _spDeleted;
        _spDeleted = _spDeleted->next;
        current->next = _sp;
        _sp = current;
    }
    else {
        std::cout << "��������������� ���� ����. ������� �� ��� ��������. " << std::endl;
    }
}

int pop(Stack*& _sp) {
    if (!isEmpty(_sp)) {
        int value = _sp->value;
        Stack* current = _sp;
        _sp = _sp->next;
        delete current;
        return value;
    }
    else {
        std::cerr << "������� ���������� �� ������� �����." << std::endl;
        return -1;
    }
}

void moveToDeletedStack(Stack*& _sp, Stack*& _spDeleted) {
    if (!isEmpty(_sp)) {
        Stack* current = _sp;
        _sp = _sp->next;
        current->next = _spDeleted;
        _spDeleted = current;
    }
    else {
        std::cerr << "������� ����������� �� ������� �����." << std::endl;
    }
}

void printStack(Stack*& stack) {
    if (stack != NULL) {
        Stack* current;
        current = stack;
        int i = 1;
        std::cout << "�������� �����: (";
        while (current != nullptr) {
            std::cout << current->value;
            current = current->next;
            if (current != nullptr) {
                std::cout << "; ";
            }
        }
        std::cout << ")" << std::endl;
    }
    else {
        std::cout << "���� ����.\n";
    }
}

void clearStack(Stack*& _sp) {
    while (_sp != nullptr) {
        Stack* temp = _sp;
        _sp = _sp->next;
        delete temp;
    }
}
