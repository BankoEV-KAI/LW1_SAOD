#include <iostream>
#include <limits>

#include "Menu.h"
#include "stack.h"


void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите цифру от "<< rangeStart <<" до " << rangeStop << " >> ";
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

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;


    switch (operation)
    {
    case 2:
        std::cout << std::endl
            << "1. Создать новый элемент;" << std::endl
            << "2. Выбор с вершины вспомогательного стека; " << std::endl
            << "0. Вернуться в начало. " << std::endl
            << std::endl;
        break;
    case 3:
        std::cout << std::endl
            << "1. Удалить элемент;" << std::endl
            << "2. Переместить во вспомогательный стек удаленных элементов; " << std::endl
            << "0. Вернуться в начало. " << std::endl
            << std::endl;
        break;
    case 5:
        std::cout << std::endl
            << "1. Проверка пустоты стека; " << std::endl
            << "2. Добавление элемента в стек;" << std::endl
            << "3. Удаление вершины стека; " << std::endl
            << "4. Вывод текущего состояния стека; " << std::endl
            << "5. Вывод содержимого вспомогательного стека удаленных элементов;" << std::endl
            << "0. Завершить выполнение." << std::endl
            << std::endl;
        break;
    default:
        break;
    }
}