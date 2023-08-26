#include <iostream>
//#include <xhash>

using namespace std;

int n = 6; //item number
int n2 = 17;//table size
int target;
int arr[6] = { 0,0,0,0,0,0 }; //arr of numbers
int h[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//hash table
int s[17][3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //cost size
int sum = 0;
int key;


int hashing(int h[], int s, int key)
{
    int mod = 0;

    for (int i = 0; i < s; i++)
    {
        mod = (key + i) % s;

        if (h[mod] == 0) {
            h[mod] = key; break;
        }
    }
    return mod;
}

void print() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
        {
            sum = arr[i] + arr[j];
            if (sum == target) {
                count++;
            }
            key = hashing(h, n2, sum);
            s[key][0] = sum;
            s[key][1] = arr[i];
            s[key][2] = arr[j];
        }
    }
    int i = 0;
    for (int j = 0; j < n2; j++)
    {
        key = (target + j) % n2;
        if (count == 0) {
            cout << "Pair not found " << endl;
        }
        else if (s[key][0] == target)
        {
            cout << "Pair found" << "(" << s[key][1] << "," << s[key][2] << ")\n";
            i++;
        }
        if (i == count) {
            break;
        }

    }
}

int main()
{
    cout << "input the numbers \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "input target \n";
    cin >> target;
    print();
}