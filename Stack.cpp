/*
проверку пустоты стека
добавление элемента в вершину стека
удаление элемента из вершины стека
вывод текущего состояния стека на экран

*/
#include "stack.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

Stack::Stack(int maxSize) {
	data = new int[maxSize];
	size = maxSize;
	sp = -1;
}

Stack::~Stack() {
	delete[] data;
}

bool Stack::isEmpty() {
	return sp == -1;
}

int Stack::pop() {
	if (!isEmpty()) {
		return data[sp--];
	}
	else {
		cout << "Стек пуст, невозможно удалить элемент." << endl;
		return -1;
	}
}

void Stack::push(int value) {
	if (sp + 1 == size) {
		resize(size + 10);
	}
	data[++sp] = value;
	cout << "Элемент " << value << " добавлен в вершину стека." << endl;

}

void Stack::resize(int newSize) {
	int* newData = new int[newSize];
	for (int i = 0; i <= sp; ++i) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	size = newSize;
	cout << "Размер стека увеличен до " << newSize << "." << endl;
}

int Stack::getVertexStack()
{
	if (!isEmpty()) {
		return data[sp];
	}
	else {
		return -1;
	}
}

void Stack::forReturnDeletedItemStack() //можно ли итерироваться по стеку удаленных элементов?
{
	if (isEmpty()) {
		std::cout << "Стек удаленных элементов пуст. " << std::endl;
	}
	else {
		std::cout << "Стек удаленных элементов можно представить следующим образом: [";
		for (int i = 0; i <= sp; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << "]. ";
	}
}

void Stack::returnFullStack() //если итерироваться запрещено: создаем дополнительный список и работаем с перезаписью
{
	if (isEmpty()) {
		std::cout << "Заданный стек пуст. " << std::endl;
	}
	else {
		int* listMemory = new int[++sp];
		std::cout << "Заданный стек можно представить следующим образом: [";
		for (int i = 0; i <= sp; i++) {
			std::cout << getVertexStack() << ", ";
			listMemory[sp - i] = data[i];
			pop();
		}
		std::cout << "]. ";
		for (int i = 0; i <= sp;  i++) {
			push(listMemory[i]);
		}
		delete[] listMemory;
	}
}

void Stack::returnStack() {
	cout << "Состояние стека: ";
	if (!isEmpty()) {
		cout << "cтек не пуст. Вершина стека: ( " << sp + 1 << ", " << data[sp] << " )." << endl;
	}
	else {
		cout << "cтек пуст. " << endl;
	}
}

void Stack::pushRandom(int count)
{
	if (count >= size - sp) {
		resize(count - sp);
	}
	srand(time(0)); 
	int value{0};
	for (int i = 0; i < count; ++i) {
		value = rand() % 100;  // Генерация случайного числа от 0 до 99
		push(value);
	}
}


