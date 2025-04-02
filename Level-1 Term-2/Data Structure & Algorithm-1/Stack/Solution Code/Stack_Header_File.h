#include <iostream>

using namespace std;

template <typename t>

class Stack
{
private:
    int x;
    int k;
    t *arr;

public:
    Stack(int x, int k)
    {
        this->x = x;
        this->k = k;

        arr = new t[x];

    }


    void print()
    {
        cout << "<";

        if (k != 0)
        {
            cout << arr[0];
        }

        for (int i = 1; i < k; i++)
        {
            cout << ", ";
            cout << arr[i];
        }

        cout << ">";

        cout << endl;
    }

    void clear()
    {
        k = 0;
    }

    void push(t val)
    {
        t *temp = new t[k];
        copy(arr, arr + k, temp);

        delete[] arr;

        arr = new t[k * 2];
        copy(temp, temp + k, arr);

        arr[k] = val;
        k++;
    }

    t pop()
    {
        if (k == 0)
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        else
        {
            t temp = arr[k - 1];
            k--;
            return temp;
        }
    }

    int length()
    {
        return k;
    }

    t topValue()
    {
        if (k != 0)
        {
            return arr[k - 1];
        }

        else
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (k == 0)
        {
            return true;
        }

        return false;
    }


    int getK() {
        return k;
    }

    void setK(int d) {
        k=d;
    }

    void setArr(t *newArr) {
        arr = newArr;
    }

    ~Stack()
    {
        delete[] arr;
    }
};


//#ifndef STACK_HEADER_FILE_H
//#define STACK_HEADER_FILE_H

//template <typename t>
//class Stack
//{
//private:
//    int x;
//    int k;
//    t* arr;
//
//public:
//    Stack(int x, int k);
//    void print();
//    void clear();
//    void push(t val);
//    t pop();
//    int length();
//    t topValue();
//    bool isEmpty();
//    ~Stack();
//};
//
//template <typename t>
//Stack<t>::Stack(int x, int k)
//{
//    this->x = x;
//    this->k = k;
//    arr = new t[x];
//}
//
//template <typename t>
//void Stack<t>::print()
//{
//    std::cout << "<";
//
//    if (k != 0)
//    {
//        std::cout << arr[0];
//    }
//
//    for (int i = 1; i < k; i++)
//    {
//        std::cout << ", ";
//        std::cout << arr[i];
//    }
//
//    std::cout << ">\n";
//}
//
//template <typename t>
//void Stack<t>::clear()
//{
//    k = 0;
//}
//
//template <typename t>
//void Stack<t>::push(t val)
//{
//    t* temp = new t[k];
//    std::copy(arr, arr + k, temp);
//
//    delete[] arr;
//
//    arr = new t[k * 2];
//    std::copy(temp, temp + k, arr);
//
//    arr[k] = val;
//    k++;
//}
//
//template <typename t>
//t Stack<t>::pop()
//{
//    if (k == 0)
//    {
//        std::cout << "Stack is Empty!\n";
//        return -1;
//    }
//    else
//    {
//        t temp = arr[k - 1];
//        k--;
//        return temp;
//    }
//}
//
//template <typename t>
//int Stack<t>::length()
//{
//    return k;
//}
//
//template <typename t>
//t Stack<t>::topValue()
//{
//    if (k != 0)
//    {
//        return arr[k - 1];
//    }
//    else
//    {
//        std::cout << "Stack is Empty!\n";
//        return -1;
//    }
//}
//
//template <typename t>
//bool Stack<t>::isEmpty()
//{
//    return k == 0;
//}
//
//template <typename t>
//Stack<t>::~Stack()
//{
//    delete[] arr;
//}

//#endif // STACK_HEADER_FILE_H



