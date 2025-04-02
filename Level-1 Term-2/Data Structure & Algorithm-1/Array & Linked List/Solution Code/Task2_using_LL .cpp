#include <bits/stdc++.h>
#include "Task1_using_LL.h"
using namespace std;

int temp_bar;


void clear() {

    while (head != NULL)
    {
        node* temp = head;
        head = temp->next;
        delete temp;
    }

}

void append(int item) {
    int cnt = 0;
    k++;

    temp_bar = bar;
    bar = length();
    insert(item);
    bar = temp_bar;

}

int Search(int item) {

    print();

    node* temp = head;

    while (temp != NULL)
    {
        if(item == temp->data) {
            return 1;
        }
        temp = temp->next;
    }

    return -1;

}


int main() {

    cin >> k;

    cin >> first_element;

    init();

    int element;

    for(int i=2; i<=k; i++) {
        cin >> element;

        add_node(element);

    }

    print();

    int q;
    int p;

    while(1) {
        cin >> q;

        if(q == 2 || q==3 || q==4) {
            cin >> p;
        }

        if(q == 0) {
            break;
        }

        else if(q == 1) {
           clear();
           print();
           cout << -1 << endl;
        }

        else if(q == 2) {
            append(p);
            print();
            cout << -1 << endl;


        }

        else if(q == 3) {
            cout << Search(p) << endl;
        }

        else if(q == 4) {
            cout << Search(p) << endl;
        }

    }


}







