#include "bits/stdc++.h"
using namespace std;

const int inf = 1e7;

int main(){
    int n, m; //n-vertices, m-edges
    cout<<"Enter number of vertices and edges respectively: ";
    cin>>n>>m;
    vector<int> dist(n, inf);
    vector<vector<pair<int,int>>> graph(n+1);
    cout<<"Enter u and v vertices of an edge and give edge's weight: "<<endl;
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cout<<"Enter source: ";
    cin>>source;
    set<pair<int,int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(x);
        for(auto it : graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(dist[i] < inf){
            cout<<"Dist of vertex "<<i<<" is "<<dist[i]<<endl;
        }
        else{
            cout<<"Dist of vertex "<<i<<" is "<<-1<<endl;
        }
    }
}