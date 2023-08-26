#include <iostream>
#include <list>
using namespace std;

class HashTable
{

    int table_size;
    list<int> *table;
    int minIndex;

public:
    HashTable(int ts){
        table_size = ts;
        table = new list<int>[table_size];
        minIndex = ts;
    }

    int hashFunction(int key) {
        return (key % table_size);
    }


    void insertElement(int key, int arrIndex){
        int index = hashFunction(key);
        table[index].push_back(arrIndex);


        if(table[index].size() > 1){
            list<int>::iterator it = table[index].begin();
            if (*it< minIndex) {
                minIndex = *it;
            }
        }
    }

    void displayHashTable(){
        for (int i = 0; i<table_size; i++) {
            cout<<i;
            for (auto j : table[i])
                cout<< " ==> " << j;
            cout<<endl;
        }
    }

    int getMinIndex(){
        return minIndex;
    }

};


int main()
{
    int N,x;
    cout << "Enter the size of the array:" << endl;
    cin >> N;

    int arr[N];

    cout << "Enter your array elements:" << endl;
    for (int i = 0 ; i < N ; i++){
        cin >> x;
        arr[i] = x;
    }



    HashTable ht(N);
    for (int i = 0; i< N; i++){
        ht.insertElement(arr[i],  i);
    }

    // Uncomment the below line to display the whole hash table
    // ht.displayHashTable();
    cout << endl;

    if(ht.getMinIndex() == N){
        cout << "Invalid Input" << endl;
    }
    else {
        cout << "The minimum index of the repeating element is " << ht.getMinIndex() << endl;
    }

}