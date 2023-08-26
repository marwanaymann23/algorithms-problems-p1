
// Count Inversions Problem


#include<iostream>
using namespace std;

int merge(int arr[], int median, int left, int right)
{
    int i, j, k;
    int firstSubArrSize = median - left + 1;
    int secondSubArrSize = right - median;
    int *leftSubArr = new int[firstSubArrSize];
    int *rightSubArr = new int[secondSubArrSize];
    int sumOfInversions = 0;

    for (i = 0; i < firstSubArrSize; i++){
        leftSubArr[i] = arr[left + i];
    }
    for (j = 0; j < secondSubArrSize; j++){
        rightSubArr[j] = arr[median + 1 + j];
    }
    i = j = 0;
    k = left;
    while (i < firstSubArrSize && j < secondSubArrSize)
    {
        if (leftSubArr[i] <= rightSubArr[j])
        {
            arr[k] = leftSubArr[i];
            i++;
        }
        else
        {
            arr[k] = rightSubArr[j];
            //
            sumOfInversions += (median - i + 1);
            j++;
        }
        k++;
    }
    while (i < firstSubArrSize)
    {
        arr[k] = leftSubArr[i];
        i++;
        k++;
    }
    while (j < secondSubArrSize)
    {
        arr[k] = rightSubArr[j];
        j++;
        k++;
    }
    return sumOfInversions;
}

int mergeSort(int arr[], int left, int right)
{
    int result = 0;
    if (left < right)
    {
        int median = left + (right - left) / 2;

        result += mergeSort(arr, left, median);
        result += mergeSort(arr, median + 1, right);

        result += merge(arr, median, left, right);
    }
    return result;
}

int main()
{

    /*
    * Test Cases
    * Case1        3 5 6 7 1 2 4 = 11
    * Case2        1 2 3 4       = 0
    * Case3        3 2 1 4       = 3
    * */

    int n, elem;
    cout << "Enter X if you want to terminate the program!" << endl << endl;
    while(cin>>n && (n!= ' ' || n!='X')){
        int arr[n];
        for(int i =0; i < n; i++){
            cin >> elem;
            arr[i] = elem;
        }
        cout << mergeSort(arr, 0, n-1) << endl;
    }

    return 0;
}
