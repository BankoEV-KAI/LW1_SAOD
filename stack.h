
#ifndef STACK_H
#define STACK_H

struct Stack {
    int data;
    Stack* next;
};

void initNullStack(Stack*& _sp, Stack*& _spDeleted);

bool isEmpty(const Stack* _sp);

bool isEmptyDeletedStack(const Stack* _spDeleted);

void returnStackStatic(const Stack* _sp);

void returnStackStaticFull(Stack* _sp);

void push(Stack*& _sp, int _value);

void pushRandom(Stack*& _sp, int count);

void pop(Stack*& _sp);

void moveToDeletedStack(Stack*& _sp, Stack*& _spDeleted);

void printStack(Stack*& stack);

void pushFromStack(Stack*& _sp, Stack*& _spDeleted);

void clearStack(Stack*& _sp);

#endif
