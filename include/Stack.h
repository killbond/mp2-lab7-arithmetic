#ifndef MP2_LAB7_ARITHMETIC_STACK_H
#define MP2_LAB7_ARITHMETIC_STACK_H


#include "List.h"

template<class Type>
class Stack :public List<Type>
{
public:
    explicit Stack(int s);
    void Push(Type a);
    Type Pop();
    Type Peek();
};

template<class Type>
void Stack<Type>::Push(Type a)
{
    Node<Type> node(a);
    this->AddStart(node);
}

template<class Type>
Stack<Type>::Stack(int s)
{
    this->L = new int[s];
    this->D = new Node<Type>[s];
    this->start = 0;
    this->end = 0;
    this->size = s;
    for (int i = 0; i < this->size; i++)
        this->L[i] = -1;
}

template<class Type>
Type Stack<Type>::Pop() {
    return this->GetStart().getData();
}

template<class Type>
Type Stack<Type>::Peek() {
    return this->D[this->start].getData();
}


#endif //MP2_LAB7_ARITHMETIC_STACK_H
