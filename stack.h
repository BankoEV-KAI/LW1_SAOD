#ifndef STACK_H
#define STACK_H

struct Stack {
    int* data;
    int size;
    int sp;

    Stack(int maxSize);
    ~Stack();

    bool isEmpty();
    void push(int value);
    int pop();
    void returnStack();
    void pushRandom(int count);
    void resize(int newSize);
    int getVertexStack();
    void forReturnDeletedItemStack();
    void returnFullStack();
};

#endif
