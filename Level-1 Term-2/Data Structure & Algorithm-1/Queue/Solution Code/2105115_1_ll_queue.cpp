#include <bits/stdc++.h>
//#include "Task1_using_LL.h"

using namespace std;


template <typename tem>

class node
{
private:
    tem val;
    node<tem> *next;

public:

    node(tem value)
    {
        this->val = value;
        this->next = NULL;
    }

    void setVal(tem val)
    {
        this->val = val;
    }

    tem getVal()
    {
        return val;
    }

    void setNext(node<tem>* &node1) {
        next = node1;
    }

    node<tem>* getNext() {
        return next;
    }

};

template <typename tem>

class Queue
{
private:
    node<tem>* head ;
    node<tem>* tail ;
    int CurrSize;
public:

    Queue()
    {
        CurrSize = 0;
        head= NULL;
        tail = NULL;
    }

    void enqueue(tem p)
    {
        node<tem> *temp = new node<tem> (p);

        if (CurrSize == 0)
        {
            head = temp;
            tail = head;
            CurrSize++;
            return;
        }


        tail->setNext(temp);
        tail = temp;

        CurrSize++;
    }

    tem dequeue()
    {

        if (CurrSize == 0)
        {
            cout << "Queue is Empty!" << endl;
            head = NULL;
            tail = NULL;

            return 0;
        }

        node<tem> *temp = head;
        head = head->getNext();

        CurrSize--;

        return temp->getVal();


    }

    int length()
    {
        return CurrSize;
    }

    tem front()
    {
        if (CurrSize == 0)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }

        return head->getVal();
    }

    tem back()
    {
        if (CurrSize == 0)
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }

        return tail->getVal();
    }

    bool isEmpty()
    {
        return CurrSize == 0;
    }

    void clear()
    {
        CurrSize = 0;
        head = NULL;
        tail = head;
    }

    void print()
    {
        if (CurrSize == 0)
        {
            cout << "<>" << endl;
            return;
        }

        cout << "<" ;

        node<tem> *temp = head;
        cout << temp->getVal();
        temp = temp->getNext();

        while (temp != NULL)
        {
            cout << ", " ;
            cout << temp->getVal() ;
            temp = temp->getNext();
        }



        cout << ">" << endl;

    }
};


int main()
{

    int choice;

    cout << "Select the type of Queue:\n";
    cout << "1. Integer Queue\n";
    cout << "2. Character Queue\n";
    cout << "3. Float Queue\n";
    cout << "4. Double Queue\n";
    cout << "5. Boolean Queue\n";
    cout << "6. String Queue\n";
    cout << "7. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Integer Queue!!!" << endl;

        Queue<int> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                int p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                int retVal = q.dequeue();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                int retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                int retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();

                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 2)
    {
        cout << "Character Queue!!!" << endl;

        Queue<char> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                char p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                char retVal = q.dequeue();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                char retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                char retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();

                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 3)
    {
        cout << "Float Queue!!!" << endl;

        Queue<float> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                float p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                float retVal = q.dequeue();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                float retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                float retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();

                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 4)
    {
        cout << "Double Queue!!!" << endl;

        Queue<double> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                double p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                q.dequeue();
                q.print();
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                double retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                double retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();

                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 5)
    {
        cout << "Boolean Queue!!!" << endl;

        Queue<bool> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                bool p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                q.dequeue();
                q.print();
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                bool retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                bool retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();
                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 6)
    {
        cout << "String Queue!!!" << endl;

        Queue<string> q;

        while (true)
        {
            int query;
            cin >> query;

            if (query == 0)
            {
                break;
            }
            else if (query == 1)
            {
                string p;
                cin >> p;
                q.enqueue(p);
                q.print();
            }
            else if (query == 2)
            {
                q.dequeue();
                q.print();
            }
            else if (query == 3)
            {
                int retVal = q.length();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 4)
            {
                string retVal = q.front();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 5)
            {
                string retVal = q.back();
                q.print();
                cout << retVal << endl;
            }
            else if (query == 6)
            {
                bool retVal = q.isEmpty();
                q.print();
                if (retVal == 1)
                {
                    cout << "True" << endl;
                }

                else
                {
                    cout << "False" << endl;
                }
            }
            else if (query == 7)
            {
                q.clear();
                q.print();
            }
        }
    }
    else if (choice == 7)
    {
        return 0;
    }

    return 0;
}
