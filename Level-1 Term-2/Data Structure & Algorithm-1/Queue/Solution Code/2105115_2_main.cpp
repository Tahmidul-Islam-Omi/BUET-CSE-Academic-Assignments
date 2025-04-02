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

