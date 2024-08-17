#include <bits/stdc++.h>
using namespace std;

void Merge(int arr1[], int low, int mid, int high, int result[]) 
{
    mid = (low + high) / 2;
    int i = low;
    int j = mid + 1;
    int k = low;
    int arr2[high + 1]; 

    while (i <= mid && j <= high) 
    {
        if (arr1[i] > arr1[j]) 
        {
            arr2[k++] = arr1[i++];
        } 
        else 
        {
            arr2[k++] = arr1[j++];
        }
    }
    while (i <= mid) 
    {
        arr2[k++] = arr1[i++];
    }
    while (j <= high) 
    {
        arr2[k++] = arr1[j++];
    }
    for (i = low; i <= high; i++) 
    {
        arr1[i] = arr2[i];
    }

    for (i = low; i <= high; i++) 
    {
        result[i] = arr1[i];
    }
}

int main() 
{
    int n1, n2;

    cin >> n1;
    int arr1[n1];

    for (int i = 0; i < n1; i++) 
    {
        cin >> arr1[i];
    }

    cin >> n2;
    int arr2[n2];

    for (int i = 0; i < n2; i++) 
    {
        cin >> arr2[i];
    }

    int totalArr[n1 + n2];

    for (int i = 0; i < n1; i++) 
    {
        totalArr[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++) 
    {
        totalArr[n1 + i] = arr2[i];
    }

    int result[n1 + n2];

    Merge(totalArr, 0, n1 - 1, (n1 + n2) - 1, result);

    for (int i = 0; i < n1 + n2; i++) 
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
