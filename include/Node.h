#ifndef MP2_LAB7_ARITHMETIC_NODE_H
#define MP2_LAB7_ARITHMETIC_NODE_H


#include <iostream>

using namespace std;

template<class Type>
class Node
{
protected:
    Type data;
public:
    Node();
    Node(Node &n);
    explicit Node(int n);
    Node * operator=(const Node &n);
    Node operator+(const Node &n);
    Node operator-(const Node &n);
    Node operator*(const Node &n);
    Node operator/(const Node &n);
    bool operator==(const Node &n);
    friend istream& operator>>(istream &in, Node &v);
    Type getData();
};

template<class Type>
Node<Type>::Node()
{
    this->data = 0;
}

template<class Type>
Node<Type>::Node(Node &n)
{
    this->data = n.data;
};

template<class Type>
Node<Type> * Node<Type>::operator=(const Node<Type> &n)
{
    if (this == &n) throw 1;
    this->data = n.data;
    return this;
};

template<class Type>
Node<Type> Node<Type>::operator+(const Node<Type> &n)
{
    Node newNode;
    newNode.data = this->data + n.data;
    return newNode;
};

template<class Type>
Node<Type> Node<Type>::operator-(const Node<Type> &n)
{
    Node<Type> newNode;
    newNode.data = this->data - n.data;
    return newNode;
}

template<class Type>
Node<Type> Node<Type>::operator*(const Node<Type> &n)
{
    Node newNode;
    newNode.data = this->data * n.data;
    return newNode;
}

template<class Type>
Node<Type> Node<Type>::operator/(const Node<Type> &n)
{
    Node newNode;
    newNode.data = this->data / n.data;
    return newNode;
}

template<class Type>
bool Node<Type>::operator==(const Node<Type> &n)
{
    return (this->data == n.data);
}


template<class Type>
Type Node<Type>::getData()
{
    return this->data;
}

template<class Type>
Node<Type>::Node(int n)
{
    this->data = n;
};

template<class Type>
istream& operator>>(istream &in, Node<Type> &v)
{
    in >> v.data;
    return in;
}

template<class Type>
ostream& operator<<(ostream &out, Node<Type> &v)
{
    out << v.getData();
    return out;
}


#endif //MP2_LAB7_ARITHMETIC_NODE_H
