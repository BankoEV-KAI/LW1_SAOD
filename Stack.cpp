/*
�������� ������� �����
���������� �������� � ������� �����
�������� �������� �� ������� �����
����� �������� ��������� ����� �� �����

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
		cout << "���� ����, ���������� ������� �������." << endl;
		return -1;
	}
}

void Stack::push(int value) {
	if (sp + 1 == size) {
		resize(size + 10);
	}
	data[++sp] = value;
	cout << "������� " << value << " �������� � ������� �����." << endl;

}

void Stack::resize(int newSize) {
	int* newData = new int[newSize];
	for (int i = 0; i <= sp; ++i) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	size = newSize;
	cout << "������ ����� �������� �� " << newSize << "." << endl;
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

void Stack::forReturnDeletedItemStack() //����� �� ������������� �� ����� ��������� ���������?
{
	if (isEmpty()) {
		std::cout << "���� ��������� ��������� ����. " << std::endl;
	}
	else {
		std::cout << "���� ��������� ��������� ����� ����������� ��������� �������: [";
		for (int i = 0; i <= sp; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << "]. ";
	}
}

void Stack::returnFullStack() //���� ������������� ���������: ������� �������������� ������ � �������� � �����������
{
	if (isEmpty()) {
		std::cout << "�������� ���� ����. " << std::endl;
	}
	else {
		int* listMemory = new int[++sp];
		std::cout << "�������� ���� ����� ����������� ��������� �������: [";
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
	cout << "��������� �����: ";
	if (!isEmpty()) {
		cout << "c��� �� ����. ������� �����: ( " << sp + 1 << ", " << data[sp] << " )." << endl;
	}
	else {
		cout << "c��� ����. " << endl;
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
		value = rand() % 100;  // ��������� ���������� ����� �� 0 �� 99
		push(value);
	}
}


