#include <bits/stdc++.h>
#include "Task1_using_Arr.h"

using namespace std;

int MAX_SIZE = 5;

template <typename tem>

class Queue
{

private:
    tem *arr;
    int ListStart;
    int CurrSize;
    int index;

public:
    Queue()
    {
        arr = new tem[MAX_SIZE];
        index = -1;
        CurrSize = 0;
        ListStart = -1;
    }


    void enqueue(tem p) {

        if(ListStart == -1) {
            ListStart = 0;
        }


        if(CurrSize == MAX_SIZE) {
            cout << "Queue is FULL!" << endl;
            return;
        }

        index++;

        index = index % MAX_SIZE ;


        arr[index] = p;
        CurrSize++;
    }



    tem dequeue() {

        if(CurrSize == 0) {
            cout << "Queue is Empty!" << endl;
            index = -1;
            ListStart = - 1;
            return 0;
        }

        tem val = arr[ListStart];
        ListStart++;
        ListStart = ListStart % MAX_SIZE;
        CurrSize--;

        return val;

    }

    int length()
    {
        return CurrSize;
    }

    tem front()
    {
        if(CurrSize == 0) {
            cout << "Queue is empty!" << endl;
            return 0;
        }

        return arr[ListStart];
    }

    tem back()
    {
        if(CurrSize == 0) {
            cout << "Queue is empty!" << endl;
            return 0;
        }

        return arr[index];
    }

    bool isEmpty()
    {
        return CurrSize == 0;
    }

    void clear()
    {
        index = -1;
        CurrSize = 0;
        ListStart = -1;
    }

    void print()
    {
        if(CurrSize == 0) {
            cout << "<>" << endl;
            return;
        }

        int loop = CurrSize;
        loop--;

        cout << "<";

        int i= ListStart;

        while(loop--) {
            cout << arr[i] << ", " ;

            if(i == MAX_SIZE-1) {
                i=-1;
            }

            i++;

        }

        cout << arr[i];

        cout << ">" << endl;

    }
};

