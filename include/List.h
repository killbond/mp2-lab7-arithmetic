#ifndef MP2_LAB7_ARITHMETIC_LIST_H
#define MP2_LAB7_ARITHMETIC_LIST_H


#include "Node.h"

template<class Type>
class List
{
protected:
    Node<Type> *D;
    int* L;
    int start;
    int end;
    int size;
public:
    explicit List(int s=1);
    List(List &a);
    void AddStart(Node<Type> A);
    void AddEnd(Node<Type> A);
    Node<Type> GetStart();
    Node<Type> GetEnd();
    bool IsEmpty();
};

using namespace std;

template<class Type>
List<Type>::List(int s)
{
    L = new int[s];
    D = new Node<Type>[s];
    start = 0;
    end = 0;
    size = s;
    for (int i = 0; i < size; i++)
        L[i] = -1;
}

template<class Type>
List<Type>::List(List&a)
{
    start = a.start;
    end = a.end;
    size = a.size;
    L = new int[size];
    D = new Node<Type>[size];
    for (int i = 0; i < size; i++)
    {
        D[i] = a.D[i];
        L[i] = a.L[i];
    }
}

template<class Type>
void List<Type>::AddStart(Node<Type> A)
{
    int c = -1;
    for (int i = 0; i < size; i++)
    {
        if (L[i] == -1)
        {
            c = i;
            break;
        }
    }
    if (c == -1) return;
    D[c] = A;
    L[c] = start;
    start = c;
    L[end] = start;
}

template<class Type>
void List<Type>::AddEnd(Node<Type> A)
{
    int c = -1;
    for (int i = 0; i < size; i++)
    {
        if (L[i] == -1)
        {
            c = i;
            break;
        }
    }
    if (c == -1) return;
    D[c] = A;
    end = c;
    L[end-1] = c;
    L[end] = start;
}

template<class Type>
Node<Type> List<Type>::GetStart()
{
    Node<Type> k = D[start];
    D[start] = Node<Type>();
    int startOld = start;
    start = L[startOld];
    L[startOld] = -1;
    return k;
}

template<class Type>
Node<Type> List<Type>::GetEnd()
{
    Node<Type> k = D[end];
    int cur = start;
    while (cur != end)
        cur = L[cur];
    D[end] = Node<Type>();
    L[end] = -1;
    L[end-1] = start;
    end = L[end-1];
    return k;
}

template<class Type>
bool List<Type>::IsEmpty()
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (L[i] == -1)
        {
            count++;
        }
    }
    return count == size;
}


#endif //MP2_LAB7_ARITHMETIC_LIST_H
