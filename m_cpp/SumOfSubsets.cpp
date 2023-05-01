#include "bits/stdc++.h"
using namespace std;

void subset_sum(vector<int>& arr, int target, vector<int> temp, int curr_sum, int index,bool& found){
    if(curr_sum == target){
        found = true;
        cout<<"Subset Found: ";
        for(auto num : temp){
            cout<<num<<" ";
        }
        return;
    }
    else if(index == arr.size() || curr_sum>target){
        return;
    }
    temp.push_back(arr[index]);
    subset_sum(arr, target, temp, curr_sum + arr[index], index + 1, found);
    temp.pop_back();
    subset_sum(arr, target, temp, curr_sum, index+1, found);
}

int main(){
    int n, M;
    cout<<"Enter number of elements and target sum: ";
    cin>>n>>M;
    vector<int> arr(n);
    cout<<"Enter "<<n<<" elements; ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> temp;
    bool found = false;
    subset_sum(arr, M, temp, 0, 0, found);
    if(!found){
        cout<<"Subset not found";
    }
    return 0;
}