#include<bits/stdc++.h>
using namespace std;
class Array {
public:
    int A[1000];
    int size;
    int length;

    int BinarySearch(int key) 
    {
        int low = 0;
        int high = length - 1;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (key == A[mid]) 
            {
                return mid;
            }
            else if (key < A[mid]) 
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() 
{
    Array arr;
    arr.size = 1000;
    cin >> arr.length;  
    for (int i = 0; i < arr.length; i++) 
    {
        cin >> arr.A[i];
    }
    int key;
    cin >> key;

    int index = arr.BinarySearch(key);
    if (index == -1) 
    {
        cout << "Not Found" << endl;
    } 
    else 
    {
        cout << index << endl;
    }

    return 0;
}
