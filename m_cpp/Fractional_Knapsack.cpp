#include<iostream>
using namespace std;

float knapsack(int n, float w[], float v[], float c){
    int i = 0;
    float total_profit = 0;
    for(i = 0; i < n; i++){
        if(w[i]>c){
            break;
        }
        else{
            total_profit = total_profit + v[i];
            c = c - w[i];
        }
    }
    if(i<n){
        if(c!=0){
            total_profit = total_profit + (v[i] * (c/w[i]));
        }
    }
    return total_profit;
}

int main(){
    //Initialization
    int num;
    float capacity;
    cout<<"Enter number of objects: ";
    cin>>num;
    cout<<endl;
    cout<<"Enter capacity: ";
    cin>>capacity;
    cout<<endl;
    float weight[num] = {0};
    float value[num] = {0};
    float ratio[num] = {0.0};
    //inputting values
    cout<<"Enter "<<num<<" values"<<endl;
    for(int i = 0; i < num; i++){
        cin>>value[i];
    }
    cout<<endl;
    cout<<"Enter "<<num<<" weights"<<endl;
    for(int i = 0; i < num; i++){
        cin>>weight[i];
    }
    for(int i = 0; i < num; i++){
        ratio[i] = value[i]/weight[i];
    }
    cout<<endl;
    //displaying values
    cout<<"Capacity: "<<capacity<<endl;
    cout<<"Values: ";
    for(int i = 0; i < num; i++){
        cout<<value[i]<<" ";
    }
    cout<<endl;
    cout<<"Weights: ";
    for(int i = 0; i < num; i++){
        cout<<weight[i]<<" ";
    }
    cout<<endl;
    cout<<"Ratio: ";
    for(int i = 0; i < num; i++){
        cout<<ratio[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    //swapping and ordering in descending order
    for(int i = 0; i<num-1; i++){
        for(int j = i+1; j<num; j++){
            if(ratio[i]<ratio[j]){
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                
                temp = value[j];
                value[j] = value[i];
                value[i] = temp;
            }
        }
    }
    cout<<"After sorting in descending order: "<<endl;
    cout<<"Values: ";
    for(int i = 0; i < num; i++){
        cout<<value[i]<<" ";
    }
    cout<<endl;
    cout<<"Weights: ";
    for(int i = 0; i < num; i++){
        cout<<weight[i]<<" ";
    }
    cout<<endl;
    cout<<"Ratio: ";
    for(int i = 0; i < num; i++){
        cout<<ratio[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    float tp = knapsack(num, weight, value, capacity);
    cout<<"Total Profit using greedy approach: "<<tp;
}