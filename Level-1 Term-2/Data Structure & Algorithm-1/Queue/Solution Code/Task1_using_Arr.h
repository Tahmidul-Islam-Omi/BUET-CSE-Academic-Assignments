#include <bits/stdc++.h>
using namespace std;

int x;
int k;

int bar = 2;

int *arr;

int idx = 0;

int first_element;

void init() {
    arr = (int*)malloc(x*sizeof(int));
    arr[idx++] = first_element;
}

void add_node(int element) {
    arr[idx++] = element;
}



void print() {


    cout << "<";



    if(bar == 0) {
        cout << " | ";
    }

    if(arr[0] != NULL ) {

        cout << arr[0];
    }


    for(int i=1; i<k; i++) {

        if(bar == i) {
            cout << " | ";
            cout << arr[i];
            continue;
        }
        cout << ", ";
        cout << arr[i];
    }


    cout << ">";
    cout << endl;
}




void insert(int item) {


    arr = (int*)realloc(arr , 2*x*sizeof(int));

    k++;
    idx++;

    for(int i=k; i>=bar+1 ; i--) {
        arr[i] = arr[i-1] ;
    }

    arr[bar] = item;

}

int length() {

    return idx;

}

int remove() {

    if(bar == 0) {
        arr[0] = NULL;
    }


    int temp = arr[bar];

    for(int i=bar; i<k-1; i++) {
        arr[i] = arr[i+1];
    }
    k--;
    idx--;


    if(bar == length()) {
        bar = 0;
    }

    return temp;

}


void moveToStart() {
    bar = 0;
    print();
}

void moveToEnd() {

    bar = length()-1;
    print();
}


void prev() {
    bar--;

    if(bar < 0) {
        bar = length() - 1;
    }

    print();
}

void next() {
    bar++;

    if(bar > length() - 1) {
        bar = 0;
    }
    print();
}

int currPos() {
    print();
    return bar;
}

void moveToPos(int pos) {
    bar = pos;
    print();
}

int getValue() {

    print();
    return arr[bar];
}




