
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
    std::cout << "Состояние стека: ";
    if (_sp != nullptr) {
        std::cout << "стек не пуст. ";
        std::cout << "Вершина стека: " << _sp->value << std::endl;
    }
    else {
        std::cout << "стек пуст.";
    }
}

void returnStackStaticFull(Stack* _sp) {
    std::cout << "Состояние стека: ";
    if (_sp != nullptr) {
        std::cout << "стек не пуст. Элементы стека:";
        std::cout << " вершина стека: " << _sp->value << ", ";
        printStack(_sp);
    }
    else {
        std::cout << "стек пуст.";
    }
}

Stack* push(Stack* _sp, int _value) {
    Stack* item = new Stack;
    if (item == nullptr) {
        std::cerr << "Ошибка выделения памяти." << std::endl;
        return _sp;
    }
    item->value = _value;
    item->next = _sp;
    _sp = item;
    std::cout << "Элемент " << item->value << " добавлен в вершину стека." << std::endl;
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
        std::cout << "Вспомогательный стек пуст. Элемент не был добавлен. " << std::endl;
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
        std::cerr << "Попытка извлечения из пустого стека." << std::endl;
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
        std::cerr << "Попытка перемещения из пустого стека." << std::endl;
    }
}

void printStack(Stack*& stack) {
    if (stack != NULL) {
        Stack* current;
        current = stack;
        int i = 1;
        std::cout << "элементы стека: (";
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
        std::cout << "Стек пуст.\n";
    }
}

void clearStack(Stack*& _sp) {
    while (_sp != nullptr) {
        Stack* temp = _sp;
        _sp = _sp->next;
        delete temp;
    }
}
