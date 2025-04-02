#include <iostream>
#include <cstdlib>
using namespace std;

int **arr;
int total_cars, garages, parking_spots;
int arr_len[100];
int min_ele;
int max_ele;
int index;
int search_garage;

void init() {
    arr = (int**)malloc((garages + 1) * sizeof(int*));

    for (int i = 1; i <= garages; i++) {
        arr[i] = (int*)malloc(parking_spots * sizeof(int));
    }

    for (int i = 1; i <= garages; i++) {
        for (int j = 0; j < parking_spots; j++) {
            arr[i][j] = 0;
        }
    }
}

void print() {

    for(int i=1; i<=garages; i++) {
        for(int j=0; j<arr_len[i]; j++) {

            if(arr[i][j] != 0) {
                cout << arr[i][j] << " ";
            }
        }

        cout << endl;
    }
}

void search() {

    min_ele = arr[search_garage][0];
    index = 0;

    for (int i = 0; i < arr_len[search_garage]; i++)
    {
        if( arr[search_garage][i] < min_ele ) {
            min_ele = arr[search_garage][i] ;
            index = i;
        }

    }


}

void Search() {

    if(arr_len[search_garage] == 0) {
        index = -1;
        return;
    }

    max_ele = arr[search_garage][0];
    index = 0;

    for (int i = 0; i < arr_len[search_garage]; i++)
    {
        if( arr[search_garage][i] > max_ele ) {
            max_ele = arr[search_garage][i] ;
            index = i;
        }

    }


}

void append(int insert_item) {

    arr_len[search_garage]++ ;

    for(int i= parking_spots-1 ; i>= (index+2) ; i-- ) {
        arr[search_garage][i] = arr[search_garage][i-1] ;
    }

    arr[search_garage][index+1] = insert_item ;


}

void remove() {

    int i;

    for ( i = index; i < arr_len[search_garage]-1; i++)
    {
        arr[search_garage][i] = arr[search_garage][i+1];
    }

    arr[search_garage][i+1] = 0;

    arr_len[search_garage]--;

}



int main() {

    cin >> total_cars >> garages >> parking_spots;

    init();


    for (int i = 1; i <= garages; i++) {
        int garage_num;
        cin >> garage_num;

        int cars;
        cin >> cars;
        arr_len[garage_num] = cars;


        for (int j = 0; j < cars; j++) {
            int car_num;
            cin >> car_num;

            arr[garage_num][j] = car_num;
        }
    }


    print();


    while (1)
    {
        string str;
        cin >> str;

        if( str == "end" ) {
            break;
        }

        else if( str == "req" ) {

            int flag = 0;

            for(int i=1; i<=garages; i++) {
                if(arr_len[i] != 0 ) {
                    search_garage = i;
                    flag = 1;
                    break;
                }
            }

            if ( flag == 0)
            {
                cout << "No cars are available." << endl;
                print();
            }

            else {
                search();
                remove();

                print();
            }

        }

        else {
            int append_item = 0;

            for(int i=3; i<str.size() ; i++) {
                append_item = append_item*10 + str[i] - '0' ;
            }

            int flag = 0;

            for(int i=garages; i>=1; i--) {
                if(arr_len[i] != parking_spots ) {
                    search_garage = i;
                    flag = 1;
                    break;
                }
            }

            if ( flag == 0)
            {
                cout << "All garages are full" << endl;
                print();
            }

            else {
                Search();
                append(append_item);

                print();
            }


        }
    }


}
