#include <iostream>

#include "2105115_1_a_queue.h"

using namespace std;

template <typename tem>

class Stack {
    Queue<int> q1;
public:
    Stack() {

    }

    void push(tem x) {
        q1.enqueue(x);
    }

    tem pop() {
        int size = q1.length();

        for(int i=2; i<= size; i++) {
            tem front_ele = q1.front();
            q1.dequeue();
            q1.enqueue(front_ele);
        }

        tem pop_ele = q1.front();
        q1.dequeue();
        return pop_ele;
    }

    tem top() {
        tem front_ele;
        int size = q1.length();

        for(int i=1; i<= size; i++) {
            front_ele = q1.front();
            q1.dequeue();
            q1.enqueue(front_ele);
        }

        return front_ele;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }

    void clear() {
        q1.clear();
    }

    void print()
    {
        q1.print();
    }

    int length() {
        q1.length();
    }

    tem topValue() {
        q1.front();
    }


};


int main()
{
    int choice;

    cout << "Select the type of stack:\n";
    cout << "1. Integer stack\n";
    cout << "2. Character stack\n";
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 2)
    {

        Stack<char>st;

        st.print();

        while (1)
        {
            int q;
            cin >> q;

            char par;

            if (q == 2)
            {
                cin >> par;
            }

            if (q == 0)
            {
                break;
            }

            else if (q == 1)
            {
                st.clear();
                st.print();
            }

            else if (q == 2)
            {
                st.push(par);
                st.print();
            }

            else if (q == 3)
            {
                char temp = st.pop();
                st.print();
                cout << temp << endl;
            }

            else if (q == 4)
            {
                st.print();
                cout << st.length() << endl;
            }

            else if (q == 5)
            {
                st.print();
                cout << st.topValue() << endl;
            }

            else
            {
                st.print();
                if (st.isEmpty() == true)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
        }
    }

    if (choice == 1)
    {
        Stack<int>st;

        st.print();

        while (1)
        {
            int q;
            cin >> q;

            int par;

            if (q == 2)
            {
                cin >> par;
            }

            if (q == 0)
            {
                break;
            }

            else if (q == 1)
            {
                st.clear();
                st.print();
            }

            else if (q == 2)
            {
                st.push(par);
                st.print();
            }

            else if (q == 3)
            {
                int temp = st.pop();
                st.print();
                cout << temp << endl;
            }

            else if (q == 4)
            {
                st.print();
                cout << st.length() << endl;
            }

            else if (q == 5)
            {
                st.print();
                cout << st.topValue() << endl;
            }

            else
            {
                st.print();
                if (st.isEmpty() == true)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
        }
    }
    else
    {
        cout << "Invalid Choice!" << endl;
    }
}
