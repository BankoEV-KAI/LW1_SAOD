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
    int value{0};
    while (true) {
        printMenu(5);
        enteringNumber(0, 5, operation);
        switch (operation)
        {
        case 1:
            mainStack.isEmpty() ? std::cout << "Стек пуст. " << std::endl : std::cout << "Стек не пуст." << std::endl;
            break;
        case 2:
            printMenu(2);
            enteringNumber(0, 2, operation);
            if (operation == 1) {
                std::cout << "1. Добавить единственный элемент;" << std::endl;
                std::cout << "2. Добавить множество случайных элементов;" << std::endl;
                std::cout << "0. Вернуться в начало. " << std::endl;
                enteringNumber(0, 2, operation);
                if (operation == 1) {
                    enteringNumber(0, 1000, value);
                    mainStack.push(value);
                }
                else {
                    std::cout << "Резмерность желаемого множества. ";
                    enteringNumber(0, 1000, value);
                    mainStack.pushRandom(value);
                }
                
            }
            else if(operation == 2){
                if (defaultStack.isEmpty()) {
                    std::cout << "Вспомогательный стек пуст. Элемент не был добавлен. " << std::endl;
                }
                else { 
                    mainStack.push(defaultStack.getVertexStack()); 
                }
            }
            break;
        case 3:
            printMenu(3);
            enteringNumber(0, 2, operation);
            if (operation == 1) {
                std::cout << "Вершина (" << mainStack.sp + 1 << ", " << mainStack.getVertexStack() << ") была удалена из стека." << std::endl;
            }
            else if(operation == 2){
                std::cout << "Вершина (" << mainStack.sp + 1 << ", " << mainStack.getVertexStack() << ") была перемещена в стек удаленных элементов." << std::endl;
                deletedItemsStack.push(mainStack.getVertexStack());
            }
            mainStack.pop();
            mainStack.returnStack();
            break;
        case 4:
            mainStack.returnStack();
            break;
        case 5:
            deletedItemsStack.forReturnDeletedItemStack();
            break;
        case 0:
            return 0;
            break;
        default:
            std::cout << "Был прозведен некорректный ввод. Повторите." << std::endl;
            break;
        }
    }
    return 0;
}
