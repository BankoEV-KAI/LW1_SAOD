// First LW SAOD summer 2024 zadanie from r1, t2, z4

#include "stack.h"
#include "Menu.h"

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    Stack mainStack(10); 
    Stack defaultStack(3);
    Stack deletedItemsStack(1);
    int operation{ 0 };
    /*while (true) {
        std::cout << " //разделитель мб" << std::endl;
        std::cout << "" << std::endl;
        std::cout << ""; 
        std::cin >> operation;

    }*/

    printMenu(2);
    readNUM(1,2,operation);

}
