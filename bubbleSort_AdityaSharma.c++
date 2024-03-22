#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int i,j,swapped;
    swapped=1;

    for(i=0;i<n-1 && swapped;i++){
        swapped=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swapped=1;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    cout<<"Enter the size of array: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array is :"<<endl;
    print(arr,n);
    bubbleSort(arr,n);
    cout<<endl;
    cout<<"Sorted array is :"<<endl;
    print(arr,n);
}