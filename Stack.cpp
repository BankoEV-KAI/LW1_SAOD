
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
        std::cout << "Вершина стека: " << _sp->data << std::endl;
    }
    else {
        std::cout << "стек пуст.";
    }
}

void returnStackStaticFull(Stack* _sp) {
    std::cout << "Состояние стека: ";
    if (_sp != nullptr) {
        std::cout << "стек не пуст. Элементы стека:";
        std::cout << " вершина стека: " << _sp->data << ", ";
        printStack(_sp);
    }
    else {
        std::cout << "стек пуст.";
    }
}

void push(Stack*& _sp, int _value) {
    Stack* item = new Stack;
    if (item == nullptr) {
        std::cerr << "Ошибка выделения памяти." << std::endl;
        
    }
    item->data = _value;
    item->next = _sp;
    _sp = item;
    std::cout << "Элемент " << item->data << " добавлен в вершину стека." << std::endl;
    
}

void pushRandom(Stack*& _sp, int count) {
    srand(time(0));
    int value{ 0 };
    for (int i = 0; i < count; ++i) {
        value = rand() % 100;
        push(_sp, value);
    }
}

void pushFromStack(Stack*& _sp, Stack*& _spDeleted) {
    if (!isEmptyDeletedStack(_spDeleted)) {
        Stack* current = _spDeleted;
        _spDeleted = _spDeleted->next;
        current->next = _sp;
        _sp = current;
        std::cout << "Произошли изменения во вспомогательном стеке." << std::endl;
        returnStackStatic(_spDeleted);
    }
    else {
        std::cerr << "Вспомогательный стек пуст. Элемент не был добавлен. " << std::endl;
    }
}

void pop(Stack*& _sp) {
    if (!isEmpty(_sp)) {
        int value = _sp->data;
        Stack* current = _sp;
        _sp = _sp->next;
        delete current;
        std::cout << "Элемент вершины  " << value << " был удален из стека." << std::endl;
    }
    else {
        std::cerr << "Попытка извлечения из пустого стека." << std::endl;
    }
}

void moveToDeletedStack(Stack*& _sp, Stack*& _spDeleted) {
    if (!isEmpty(_sp)) {
        Stack* current = _sp;
        _sp = _sp->next;
        current->next = _spDeleted;
        _spDeleted = current;
        std::cout << "Произошли изменения во вспомогательном стеке." << std::endl;
        returnStackStatic(_spDeleted);
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
            std::cout << current->data;
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
    std::cout << "Стек очищен." << std::endl;
}
