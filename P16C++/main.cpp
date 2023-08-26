#include<iostream>
#include<unordered_map>
using namespace std;

void rearrange(int elements[], int arraySize) {
    unordered_map<int, int> numberOfOccurences;
    //Fill the map with elements as keys and their frequencies as values
    for (int i = 0; i < arraySize; i++) {
        numberOfOccurences[elements[i]]++;
    }
    //Print each element k times where k is the frequency corresponding to it in the map then remove it from the map
    for (int i = 0; i < arraySize; i++) {
        int k = numberOfOccurences[elements[i]];
        for (k; k > 0; k--) {
            cout << elements[i] << " ";
        }
        numberOfOccurences.erase(elements[i]);
    }
    cout << endl;
}

int main() {
    int elements[] = { 1, 2, 3, 1, 2, 1 };
    int arraySize = sizeof(elements) / sizeof(elements[0]);
    rearrange(elements, arraySize);
    int elements2[] = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };
    int arraySize2 = sizeof(elements2) / sizeof(elements2[0]);
    rearrange(elements2, arraySize2);
}