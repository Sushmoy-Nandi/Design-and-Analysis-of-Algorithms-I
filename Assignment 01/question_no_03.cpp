#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int>& arr, int n, int K) 
{
    int low = 0, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == K) 
        {
            result = mid; 
            high = mid - 1;
        } 
        else if (arr[mid] < K) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    
    return result;
}

int findLastOccurrence(vector<int>& arr, int n, int K) 
{
    int low = 0, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == K) {
            result = mid; 
            low = mid + 1;
        } 
        else if (arr[mid] < K) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n, K;
    
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cin >> K;
    int first = findFirstOccurrence(arr, n, K);
    int last = findLastOccurrence(arr, n, K);
    
    if (last > first) 
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
