#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m;
    cout<<"Enter number of sets and size of universal set: ";
    cin>>n>>m;
    
    vector<set<int>> sets(n);
    vector<int> cost(n);
    
    for(int i = 0; i < n; i++){
        int size_set;
        cout<<"Enter size of set"<<i+1<<": ";
        cin>>size_set;
        cout<<"Enter elements for set"<<i+1<<": ";
        for(int j = 0; j < size_set; j++){
            int x;
            cin>>x;
            sets[i].insert(x);
        }
    }
    
    cout<<"Enter cost of "<<n<<" sets: ";
    for(int i = 0; i < n; i++){
        cin>>cost[i];        
    }
    
    set<int> universe;
    for(int i = 1; i <= m; i++){
        universe.insert(i);
    }
    
    int total_cost = 0;
    
    set<int> selected_sets;

    while(!universe.empty()){
        int best_set = -1;
        set<int> elementsCovered;
        for(int i = 0; i < n; i++){
            set<int> intersection;
            set_intersection(sets[i].begin(), sets[i].end(), universe.begin(), universe.end(),
            inserter(intersection, intersection.begin()));
            
            if(intersection.size() > elementsCovered.size()){
                elementsCovered = intersection;
                best_set = i;
            }
        }
        if(best_set == -1){
            break;
        }
        total_cost = total_cost + cost[best_set];
        selected_sets.insert(best_set);
        for(auto it : elementsCovered){
            universe.erase(it);
        }
    }
    
    cout<<"The minimum number of sets required: "<<selected_sets.size()<<endl;
    cout<<"The selected_sets are: "<<endl;
    for(auto it : selected_sets){
        cout<<"Set "<<it+1<<endl;
    }
    cout<<"Total cost: "<<total_cost;
}