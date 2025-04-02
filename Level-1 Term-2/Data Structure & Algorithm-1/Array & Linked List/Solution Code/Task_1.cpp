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

        if(q == 1 || q==9) {
            cin >> p;
        }

        if(q == 0) {
            break;
        }

        else if(q == 1) {
           insert(p);
           print();
           cout << -1 << endl;
        }

        else if(q == 2) {
            cout << remove() << endl;
            print();

        }

        else if(q == 3) {
            moveToStart();
            cout << -1 << endl;
        }

        else if(q == 4) {
            moveToEnd();
            cout << -1 << endl;
        }

        else if(q == 5) {
            prev();
            cout << -1 << endl;
        }

        else if(q == 6) {
            next();
            cout << -1 << endl;
        }

        else if(q == 7) {

            print();

            cout << length() << endl;
        }

        else if(q == 8) {

            cout << currPos() << endl;
        }

        else if(q == 9) {
            moveToPos(p);
            cout << -1 << endl;
        }

        else if(q == 10) {

            cout << getValue() << endl;
        }
    }

}

