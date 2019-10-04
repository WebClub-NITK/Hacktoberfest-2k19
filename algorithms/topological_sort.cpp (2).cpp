#include<bits/stdc++.h>
using namespace std;


//code to implement depth-first-search
void dfs(int i,vector<bool>&visited,vector<int>adj[],stack<int>&st){
    
    visited[i]=true;
    for(auto j=adj[i].begin();j!=adj[i].end();j++){
        
        if(!visited[*j]){
            
            dfs(*j,visited,adj,st);
        }
    }
    st.push(i);
}


//function for topological_sort
//returns a vector containing vertices in sorted order
vector<int>topological_sort(int V,vector<int>adj[]){
    vector<int>v;
    vector<bool>visited(V,false);
    stack<int>st;
    
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
            
            dfs(i,visited,adj,st);
            
        }
    }
    while(!st.empty()){
        
        v.push_back(st.top());
        st.pop();
        
    }
    return v;
}


int main(){
    
    int edges,vertices;
    cout<<"Enter no. of edges and vertices in a graph"<<endl;
    cin>>edges>>vertices;
    
    int u,v;
    vector<int>adj[vertices];
    
    cout<<"Add edges to the graph by giving vertices in order u v if there is an edge from u to v"<<endl;
    for(int i=0;i<edges;i++){
        
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
    vector<int>result=topological_sort(vertices,adj);
    
    cout<<"Topologically sorted verices"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}











