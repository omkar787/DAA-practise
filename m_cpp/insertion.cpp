#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout<<"Sorted Array: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int inputArr[10]={19,17,15,13,11,9,7,5,3,1}, n;
    n = sizeof(inputArr)/sizeof(inputArr[0]);
    cout<<"Input Array is: "<<endl;
    for(int i = 0; i<10; i++){
        cout<<inputArr[i]<<" ";
    }
    cout<<endl;
    insertion_sort(inputArr, n);
}