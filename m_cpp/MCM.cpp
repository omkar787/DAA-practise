#include<iostream>
using namespace std;

void parenthesize(int s[][5], int i, int j){
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        parenthesize(s, i, s[i][j]);
        parenthesize(s, s[i][j]+1, j);
        cout<<")";
    }
}

int main(){
    int p[] = {5,4,6,2,7};
    int n = 5;
    int m[5][5] = {0};
    int s[5][5] = {0};
    int min, q, j;
    for(int d = 1; d<n-1; d++){
        for(int i = 1; i < n-d; i++){
            j = i + d;
            min = 333333;
            for(int k = i; k < j; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<min){
                    min = q;
                    s[i][j] = k;
                }
                m[i][j]=min;
            }
        }
    }
    cout<<"Optimal Parenthesis: "<<endl;
    parenthesize(s, 1, n-1);
    cout<<endl;
    cout<<"Total Cost: "<<m[1][n-1]<<endl;
}