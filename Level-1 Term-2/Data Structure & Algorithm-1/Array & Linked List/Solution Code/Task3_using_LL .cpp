#include <bits/stdc++.h>
using namespace std;

class node
{

public:

    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

node *head = NULL;
node *tail = NULL;
int bar = 0;
int serach_garage;
node *arr[1000];
int total_cars, garages, parking_spots;

void init() {
    for (int i = 1; i <= garages; i++)
    {
        arr[i] = NULL;
    }
}

void insert_node(int insert_item)
{

    node *insert_node = new node(insert_item);

    int cnt = 0;

    node *temp = head;

    while (cnt < bar - 1)
    {
        temp = temp->next;
        cnt++;
    }

    insert_node->next = temp->next;
    temp->next = insert_node;
}

int lenght()
{

    node *temp = head;

    if (temp->data == 0)
    {
        return 0;
    }

    int cnt = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

void remove()
{

    if (bar == 0 && lenght() == 1)
    {

        node *node1 = new node(0);
        arr[serach_garage] = node1;
    }

    else if (bar == 0)
    {

        node *temp = head;
        head = head->next;

        temp->next = NULL;

        delete temp;

        arr[serach_garage] = head;

        return;
    }

    else
    {

        node *curr = head;
        node *prev = NULL;

        int cnt = 0;

        while (cnt < bar)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

void search()
{

    node *temp = head;

    int min = temp->data;

    int index = 0;
    bar = 0;

    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
            bar = index;
        }

        temp = temp->next;
        index++;
    }
}

void Search()
{

    node *temp = head;

    int max = temp->data;

    int index = 0;
    bar = 0;

    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
            bar = index;
        }

        temp = temp->next;
        index++;
    }

    bar = index;
}

void append(int item)
{
    int cnt = 0;

    bar = lenght();
    insert_node(item);
}

void print()
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    cin >> total_cars >> garages >> parking_spots;

    init();

    for (int i = 1; i <= garages; i++)
    {
        int garage_number, cars;
        cin >> garage_number >> cars;

        if (cars != 0)
        {

            int car_num;
            cin >> car_num;

            node *node1 = new node(car_num);
            head = node1;
            tail = node1;
            arr[garage_number] = head;

            for (int i = 2; i <= cars; i++)
            {
                cin >> car_num;

                append(car_num);
            }
        }

        else
        {
            node *node1 = new node(0);
            head = node1;
            arr[garage_number] = head;
        }
    }

    for (int i = 1; i <= garages; i++)
    {
        if (arr[i]->data == 0)
        {
            cout << endl;
        }

        else
        {
            head = arr[i];
            print();
        }
    }



    while (1)
    {


        string str;
        cin >> str;

        if (str == "end")
        {

            break;
        }

        else if (str == "req")
        {

            int i;
            int flag = 0;
            for (i = 1; i <= garages; i++)
            {
                if (arr[i]->data != 0)
                {
                    serach_garage = i;
                    flag = 1;
                    break;
                }
            }


            if (flag == 0)
            {
                cout << "No cars are available" << endl;
            }

            else
            {

                head = arr[i];

                search();
                remove();

                for (int i = 1; i <= garages; i++)
                {
                    if (arr[i]->data == 0)
                    {
                        cout << endl;
                    }

                    else
                    {
                        head = arr[i];
                        print();
                    }
                }
            }
        }

        else
        {

            int append_item = 0;

            for(int i=3; i<str.size() ; i++) {
                append_item = append_item*10 + str[i] - '0' ;
            }

            int flag = 0;

            for (int i = garages; i >= 1; i--)
            {
                head = arr[i];
                if (lenght() != parking_spots)
                {
                    serach_garage = i;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                cout << "All garages are full" << endl;
                print();
            }

            else
            {
                if (arr[serach_garage]->data == 0)
                {

                    node *node1 = new node(append_item);
                    head = node1;
                    arr[serach_garage] = head;


                    for (int i = 1; i <= garages; i++)
                    {
                        if (arr[i]->data == 0)
                        {
                            cout << endl;
                        }

                        else
                        {
                            head = arr[i];
                            print();
                        }
                    }
                }

                else
                {

                    head = arr[serach_garage];
                    Search();
                    insert_node(append_item);

                    for (int i = 1; i <= garages; i++)
                    {
                        if (arr[i]->data == 0)
                        {
                            cout << endl;
                        }

                        else
                        {
                            head = arr[i];
                            print();
                        }
                    }
                }
            }
        }
    }

}
