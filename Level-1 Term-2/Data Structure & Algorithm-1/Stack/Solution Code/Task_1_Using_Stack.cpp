#include <iostream>

using namespace std;

template <typename t>


class Stack
{
private:
    int x = 10;
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

int main()
{
    int x, k;
    cin >> x >> k;
    int choice;

    cout << "Select the type of stack:\n";
    cout << "1. Integer stack\n";
    cout << "2. Character stack\n";
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 1)
    {
        Stack<int> st(x, k);

        int *arr;
        arr = new int[k];

        for (int i = 0; i < st.getK() ; i++)
        {
            cin >> arr[i];
        }

        st.setArr(arr);

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

    else if (choice == 2)
    {

        Stack<char> st(x, k);

        char *arr;
        arr = new char[k];

        for (int i = 0; i < st.getK() ; i++)
        {
            cin >> arr[i];
        }

        st.setArr(arr);

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


    else
    {
        cout << "Invalid Choice!" << endl;
    }
}
