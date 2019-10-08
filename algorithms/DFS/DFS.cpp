#include<bits/stdc++.h> 
using namespace std; 
  
class Graph 
{ 
int V;     
list<int> *adjList;  
public: 
Graph(int V) 
    {
this->V = V; 
adjList = new list<int>[V]; 
    }
void addEdge(int v, int w)  
    {
adjList[v].push_back(w);   
    }
void DFS(); 
  
void DFSUtil
(int s, vector<bool> &visited); 
}; 
  
void Graph::DFSUtil(int s, vector<bool> &visited) 
{  
stack<int> dfsstack;  
dfsstack.push(s); 
  
while (!dfsstack.empty()) 
    { 
        s = dfsstack.top(); 
       dfsstack.pop(); 
  
 if (!visited[s]) 
        { 
cout << s << " "; 
visited[s] = true; 
        } 
  
for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i) 
if (!visited[*i]) 
dfsstack.push(*i); 
    } 
}
void Graph::DFS() 
{ 
vector<bool> visited(V, false); 
  
for (int i = 0; i < V; i++) 
if (!visited[i]) 
DFSUtil(i, visited); 
} 
  
int main() 
{ 
    Graph gidfs(5);   
gidfs.addEdge(0, 1); 
gidfs.addEdge(0, 2); 
gidfs.addEdge(0, 3);
gidfs.addEdge(1, 2); 
gidfs.addEdge(2, 4);
gidfs.addEdge(3, 3); 
gidfs.addEdge(4, 4);
 
cout << "Output of Iterative Depth-first traversal:\n"; 
gidfs.DFS(); 
  
return 0; 
}   