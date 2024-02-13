//Первая ЛР по курсу САОД код задания 1.2.4
#include "stack.h"
#include "Menu.h"

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian"); //изменение языка для корректного отображения в консоли

    Stack* sp; //указатели
    Stack* spDeleted;

    initNullStack(sp, spDeleted); //инициализация двух пустых стеков

    std::cout << "Стек (динамическая реализация с доп функциями) " << std::endl;
    
    int operation{ 0 }; //код операции, который будет запрошен у пользователя
    int value{0}; //значение, которое будет запрошено от пользователя

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
                    sp = push(sp, value);
                }
                else {
                    std::cout << "Резмерность желаемого множества. ";
                    enteringNumber(0, 1000, value);
                    pushRandom(sp,value);
                }
                
            }
            else if(operation == 2){
                if (isEmptyDeletedStack(spDeleted)) {
                    std::cout << "Вспомогательный стек пуст. Элемент не был добавлен. " << std::endl;
                }
                else { 
                    pushFromStack(sp, spDeleted);
                }
            }
            break;
        case 3:
            printMenu(3);
            enteringNumber(0, 2, operation);
            if (operation == 1) {
                std::cout << "Вершина " << pop(sp) << ") была удалена из стека." << std::endl;
            }
            else if(operation == 2){
                moveToDeletedStack(sp,spDeleted);
                std::cout << "вспомогательный" << std::endl;
                returnStackStaticFull(spDeleted);
            }
            std::cout << "основной" << std::endl;

            returnStackStatic(sp);
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
            std::cout << "Был прозведен некорректный ввод. Повторите." << std::endl;
            break;
        }
    }
    return 0;
}
