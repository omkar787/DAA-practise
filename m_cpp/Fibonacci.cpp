#include<iostream>
using namespace std;

int fibonacci(int n1, int n2, int n){
    if(n == 0){
        return 0;
    }
    else{
        int n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout<<n3<<" ";
        return fibonacci(n1,n2,n-1);
    }
}

int main(){
    int n1 = 0, n2 = 1, n;
    cout<<"Enter the number for which you want fibonacci sequence: "<<endl;
    cin>>n;
    cout<<n1<<" "<<n2<<" ";
    fibonacci(n1, n2, n);
}  