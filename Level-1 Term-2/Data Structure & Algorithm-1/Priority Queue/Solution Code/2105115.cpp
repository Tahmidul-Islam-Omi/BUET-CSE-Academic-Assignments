#include <bits/stdc++.h>

using namespace std;

template<typename T>

void Swap(T &x, T &y)
{
    T Temp = x;
    x = y;
    y = Temp;
}

template<typename T>

class PriorityQueue
{
public:
    T *harr;
    int capacity;
    int heap_size;

    PriorityQueue(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new T[cap + 1];
    }

    int parent(int i)
    {
        return i / 2;
    }

    int left(int i)
    {
        return 2 * i;
    }

    int right(int i)
    {
        return 2 * i + 1;
    }

    void getMax(ostream &outstream)
    {

        if (heap_size == 0)
        {
            outstream << "Heap is empty!" << endl;
        }

        else
        {
            outstream << "Max: " << harr[1] << endl;
        }
    }

    void insertKey(T k)
    {

        if (heap_size > capacity)
        {
            capacity = heap_size * 2;
            T *Temp = new T[capacity];
            copy(harr + 1, harr + heap_size + 1, Temp + 1);
            delete[] harr;

            heap_size++;

            Temp[heap_size] = k;

            harr = Temp;

        }

        else {

            harr[++heap_size] = k;
        }

        int i = heap_size;

        while (i > 1 && harr[parent(i)] < harr[i])
        {
            Swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }

    }

    void increaseKey(int i, T new_val, ostream &outstream)
    {
        if(i > heap_size) {
            outstream << "Heap is out of bound!" << endl;
            return;
        }

        if (harr[i] >= new_val)
        {
            outstream << "New key is not larger than the previous key" << endl;
        }

        else
        {

            harr[i] = new_val;
            while (i > 1 && harr[parent(i)] < harr[i])
            {
                Swap(harr[i], harr[parent(i)]);
                i = parent(i);
            }

            outstream << "Key increased!" << endl;
        }

    }

    void decreaseKey(int i, T new_val, ostream &outstream)
    {
        if(i > heap_size) {
            outstream << "Heap is out of bound!" << endl;
            return;
        }

        if (harr[i] <= new_val)
        {
            outstream << "New key is not smaller than the previous key" << endl;
        }

        else
        {

            harr[i] = new_val;
            MaxHeapify(i);

            outstream << "Key decreased!" << endl;
        }

    }

    void extractMax(ostream &outstream)
    {
        if (heap_size == 0)
        {
            outstream << "Heap is empty!" << endl;
        }

        else if (heap_size == 1)
        {
            heap_size--;
            outstream << "Max: " << harr[1] << " has been extracted." << endl;
        }

        else
        {

            T root = harr[1];
            harr[1] = harr[heap_size];
            heap_size--;
            MaxHeapify(1);

            outstream << "Max: " << root << " has been extracted." << endl;
        }
    }

    void HeapSort( ostream &outstream ) {
        int temp_size= heap_size;

        for(int i= heap_size; i>=2; i--) {
            Swap( harr[i] , harr[1] );
            heap_size--;
            MaxHeapify(1);
        }

        outstream << "No of elements: " << temp_size << endl;
        int breakpoint = 1;

        for(int i=1; i<=temp_size; i++) {
            outstream <<  harr[i] << " ";

            if(i == breakpoint) {
                breakpoint = 1 + breakpoint*2;
                outstream << endl;
            }
        }

    }

    void MaxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l <= heap_size && harr[l] > harr[i])
            largest = l;
        if (r <= heap_size && harr[r] > harr[largest])
            largest = r;

        if (largest != i)
        {
            Swap(harr[i], harr[largest]);
            MaxHeapify(largest);
        }
    }



    void print( ostream &outstream ) {
        outstream << "No of elements: " << heap_size << endl;
        int breakpoint = 1;

        for(int i=1; i<=heap_size; i++) {
            outstream <<  harr[i] << " ";

            if(i == breakpoint) {
                breakpoint = 1 + breakpoint*2;
                outstream << endl;
            }
        }
        outstream << endl;
    }

};


int main()
{

    PriorityQueue<int> obj(1000);

    ifstream inputFile("in2.txt");
    ofstream outputFile("out1.txt");

    string line;

    if (!inputFile)
    {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error opening the output file." << endl;
        return 1;
    }

    while (getline(inputFile, line))
    {
        int optionnumber;
        istringstream iss(line);

        const int MAX_NUM_INTEGERS = 10;
        int *integers = new int[MAX_NUM_INTEGERS];

        int num;
        int numCount = 0;

        while (iss >> num && numCount < MAX_NUM_INTEGERS)
        {
            integers[numCount] = num;
            numCount++;
        }

        if (integers[0] == 1)
        {
            obj.insertKey(integers[1]);
        }

        else if (integers[0] == 2)
        {
            obj.getMax(outputFile);
        }

        else if (integers[0] == 3)
        {
            obj.extractMax(outputFile);
        }

        else if (integers[0] == 4)
        {
            obj.increaseKey(integers[1], integers[2], outputFile);
        }

        else if (integers[0] == 5)
        {
            obj.decreaseKey(integers[1], integers[2], outputFile);
        }

        else if (integers[0] == 6)
        {
            obj.print(outputFile);
        }

        else if( integers[0] == 7) {
            obj.HeapSort(outputFile);
        }

        else
        {
            return 0;
        }

        delete[] integers;
    }

    return 0;
}
