#include <iostream>
#include <limits>

#include "Menu.h"


void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от "<< rangeStart <<" до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}

void printMenu(int operation) {
    switch (operation)
    {
    case 2:
        std::cout << std::endl
            << "1. Создать новый элемент;" << std::endl
            << "2. Выбор с вершины вспомогательного стека; " << std::endl;
        break;
    case 3:
        std::cout << std::endl
            << "1. Удалить элемент;" << std::endl
            << "2. Переместить во вспомогательный стек удаленных элементов; " << std::endl;
        break;
    case 5:
        std::cout << std::endl
            << "1." << std::endl
            << "2." << std::endl
            << "3." << std::endl
            << "4." << std::endl
            << "5." << std::endl;
        break;
    default:
        break;
    }
}