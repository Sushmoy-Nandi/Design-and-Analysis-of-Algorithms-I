#include <bits/stdc++.h>
using namespace std;

int n, arr[100005], temp[100005];

void merge(int l, int r){
	int mid=(l+r)/2;
	int i1=l, i2=mid+1, j=l;
	while(i1<=mid && i2<=r){
		if(arr[i1]<arr[i2]){
			temp[j]=arr[i1];
			i1++;
		}
		else{
			temp[j]=arr[i2];
			i2++;
		}
		j++;
	}
	while(i1<=mid){
		temp[j]=arr[i1];
		j++, i1++;
	}
	while(i2<=r){
		temp[j]=arr[i2];
		j++, i2++;
	}
	for(int j=l; j<=r; j++){
		arr[j]=temp[j];
	}
}

void mergesort(int l, int r){
    // base case
	if(l==r) return;
	int mid=(l+r)/2;
    cout<<"need to sort"<<endl;
    for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
	//divide
	mergesort(l,mid);
	mergesort(mid+1,r);
	cout<<"left"<<endl;
    for(int i=l;i<=mid;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	cout<<"right"<<endl;
    for(int i=mid+1;i<=r;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

	//conquer
	merge(l,r);
    cout<<"sorted"<<endl;
    for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }
	
    cout<<endl;
}

int main() {
    cin>>n;
	for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	
	mergesort(0,n-1);
    cout<<"Sorted Array"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}
