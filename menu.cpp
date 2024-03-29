#include <iostream>
#include <limits>

#include "Menu.h"
#include "stack.h"


void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "������� ����� �� "<< rangeStart <<" �� " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "������������ ����. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cerr << "������������ �����. ";
        }
    }
}

void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;


    switch (operation)
    {
    case 2:
        std::cout << std::endl
            << "1. ������� ����� �������;" << std::endl
            << "2. ����� � ������� ���������������� �����; " << std::endl
            << "0. ��������� � ������. " << std::endl
            << std::endl;
        break;
    case 3:
        std::cout << std::endl
            << "1. ������� �������;" << std::endl
            << "2. ����������� �� ��������������� ���� ��������� ���������; " << std::endl
            << "0. ��������� � ������. " << std::endl
            << std::endl;
        break;
    case 5:
        std::cout << std::endl
            << "1. �������� ������� �����; " << std::endl
            << "2. ���������� �������� � ����;" << std::endl
            << "3. �������� ������� �����; " << std::endl
            << "4. ����� �������� ��������� �����; " << std::endl
            << "5. ����� ����������� ���������������� ����� ��������� ���������;" << std::endl
            << "0. ��������� ����������." << std::endl
            << std::endl;
        break;
    default:
        break;
    }
}