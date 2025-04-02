#include <bits/stdc++.h>
using namespace std;

class node{

    public:

    int data;
    node* next;

    node(int value) {
        data = value;
        next = NULL;
    }

};

int first_element;
node* head = NULL;
node* tail = NULL;
int bar = 2;
int k;

void init() {

    node* node1 = new node(first_element);

    head = node1;
    tail = node1;
}


void add_node(int d) {
    node* new_node = new node(d);
    tail->next = new_node;
    tail = new_node;

}


void print() {

    node* temp = head;
    cout << "<";

    int cnt = 0;

    if(bar == cnt) {
        cout << " | ";
    }

    if(temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        cnt++;
    }

    while (temp != NULL)
    {

        if(bar == cnt) {
            cout << " | ";
            cout << temp->data;
            temp = temp->next;
            cnt++;
            continue;
        }

        cout << ", " << temp->data;
        temp = temp->next;
        cnt++;
    }

    cout << ">";
    cout << endl;

}

void InsertAthead (int insert_item) {
    k++;
    node* temp = new node(insert_item);
    temp->next = head;
    head = temp;
}


void insert(int insert_item) {

    if(bar == 0) {
        InsertAthead(insert_item);
        return;
    }
    k++;

    node* insert_node = new node(insert_item);

    int cnt = 0;

    node* temp = head;

    while (cnt < bar-1)
    {
        temp = temp->next ;
        cnt++;
    }

    insert_node->next = temp->next;
    temp->next = insert_node;


}


int remove_head() {

    k--;
    node* temp = head;
    head = head->next;

    int d = temp->data;

    temp->next = NULL;

    delete temp;

    print();

    return d;


}


int remove() {


    if(bar == 0) {
        remove_head();
    }

    else {


     node* curr = head;
     node* prev = NULL;

     int cnt = 0;

    while (cnt < bar)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;
    curr->next = NULL;

    if(bar == k-1) {
        bar = 0;
    }

    k--;

    return curr->data;


    }

}

int length() {

    node* temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }


    return cnt;

}

void moveToStart() {
    bar = 0;
    print();
}

void moveToEnd() {

    int d = length();
    bar = --d;
    print();
}



void prev() {
    bar--;
    if(bar < 0 ) {
        bar = k-1 ;
    }
    print();
}

void next() {
    bar++;
    if(bar > (k-1)) {
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

    int cnt = 0;
    node* temp = head;

    while (cnt < bar)
    {
        temp = temp->next;
        cnt++;
    }

     print();

    return temp->data;

}




