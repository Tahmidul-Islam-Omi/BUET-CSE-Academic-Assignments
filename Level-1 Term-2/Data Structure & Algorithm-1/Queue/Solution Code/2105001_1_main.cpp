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

                if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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

                 if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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

                if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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

                if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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
                if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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
                 if(retVal == 1) {
                    cout << "True" << endl;
                }

                else {
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

