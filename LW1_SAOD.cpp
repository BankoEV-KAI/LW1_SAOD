//Первая ЛР по курсу САОД код задания 1.2.4
#include "stack.h"
#include "Menu.h"

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    Stack* sp;
    Stack* spDeleted;

    initNullStack(sp, spDeleted);

    std::cout << "Стек (динамическая реализация с доп функциями) " << std::endl;
    
    int operation{ 0 };
    int value{0};

    while (true) {
        printMenu(5);
        enteringNumber(0, 5, operation);
        switch (operation)
        {
        case 1:
            isEmpty(sp) ? std::cout << "Стек пуст. " << std::endl : std::cout << "Стек не пуст." << std::endl;
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
                    push(sp, value);
                }
                else {
                    std::cout << "Резмерность желаемого множества. ";
                    enteringNumber(0, 1000, value);
                    pushRandom(sp,value);
                }
                
            }
            else if(operation == 2){
                pushFromStack(sp, spDeleted);
            }
            break;
        case 3:
            printMenu(3);
            enteringNumber(0, 2, operation);
            operation == 1 ? pop(sp) : moveToDeletedStack(sp, spDeleted);
            break;
        case 4:
            returnStackStatic(sp);
            break;
        case 5:
            returnStackStaticFull(spDeleted);
            break;
        case 0:
            clearStack(sp); clearStack(spDeleted);
            return 0;
            break;
        default:
            std::cerr << "Был прозведен некорректный ввод. Повторите." << std::endl;
            break;
        }
    }
    return 0;
}
