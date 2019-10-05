#include<bits/stdc++.h>

using namespace std; 
  
class Graph 
{ 
    int V;     
    list<int> *adj;    
    void DFSUtil(int v, bool visited[]);
public: 
    Graph(int V);   
    void addEdge(int v, int w);   
    void DFS();    
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);  
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  

void Graph::DFS() 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 
  
/*int main() 
{ 
    int e, i;
    cout<<"Enter the no. of edges:";
    cin>>e;
    Graph g(e);
    cout<<"Enter coordinates:\n";
    for(i=0;i<e;i++){
     for(j=0;j<e;j++){
      
     }
    }*/

int main() 
{ 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "DFS:\n"; 
    g.DFS(); 
  
    return 0; 
}  
   
    
