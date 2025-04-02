#include <bits/stdc++.h>
#include "Task1_using_Arr.h"
using namespace std;


int temp_bar;


void clear() {

    //moveToStart();

    while(length() != 0) {
        remove();

    }

    arr[0] = NULL;
}


int Search(int item) {

    print();

    for(int i=0; i<length(); i++) {
        if( arr[i] == item) {
            return 1;
        }
    }

    return -1;
}

void append(int item) {
    temp_bar = bar;
    bar = length();
    insert(item);
    bar = temp_bar;

}


int main() {

    cin >> k >> x;

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




