#include<iostream>
#include<cmath>
using namespace std;

void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int low, int high);

int main(){
    int inputArr[10]={19,17,15,13,11,9,7,5,3,1}, n;
    n = sizeof(inputArr)/sizeof(inputArr[0]);
    cout<<"Input Array is: "<<endl;
    for(int i = 0; i<10; i++){
        cout<<inputArr[i]<<" ";
    }
    cout<<endl;
    merge_sort(inputArr, 0, n-1);
    cout<<"Sorted Array: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<inputArr[i]<<" ";
    }
}

void merge_sort(int arr[], int low, int high){
    if(low<high){
        int mid = floor((low+high)/2);
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1+1], R[n2+1];
    for(int i = 0; i<n1; i++){
        L[i] = arr[low + i];
    }
    for(int j = 0; j<n2; j++){
        R[j] = arr[mid+j+1]; 
    }
    L[n1] = 3333333;
    R[n2] = 3333333;
    int i = 0;
    int j = 0;
    for(int k = low; k<(high+1); k++){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
    }
}