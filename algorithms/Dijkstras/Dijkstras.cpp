#include<bits/stdc++.h>
using namespace std;
int mindist(int v,int dist[],bool spset[]){
	int mini=INT_MAX,min_idx;
	for(int i=0;i<v;i++){
		if(spset[i]==false && dist[i]<=mini){
			mini=dist[i];
			min_idx=i;
		}
	}
	return min_idx;
}
void printpath(int parent[],int j,int src){
	if(parent[j]==-1){
		return;
	}
	printpath(parent,parent[j],src);
	cout<<" ---> "<<j;
}
void dijkstras(int v,vector<vector<int> >adj,int src,int dest){
	int dist[v];
	bool spset[v];
	int parent[v];
	for(int i=0;i<v;i++){
		dist[i]=INT_MAX;
		spset[i]=false;
		parent[src]=-1;
	}
	dist[src]=0;
	for(int i=0;i<v-1;i++){
		int u=mindist(v,dist,spset);
		spset[u]=true;
		for(int j=0;j<v;j++){
			if(!spset[j] && adj[i][j]!=0 && dist[i]+adj[i][j]<dist[j]){
				parent[j]=i;
				dist[j]=dist[i]+adj[i][j];
			}
		}
	}
	cout<<"The path from "<<src<<" to "<<dest<<" is: ";
	cout<<src;
	printpath(parent,dest,src);
	cout<<endl;
}
int main(){
	int v,e;
	cout<<"Enter the number of nodes: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	cout<<"Enter the edges in the graph:"<<endl;
	int adj[v][v];
	memset(adj,0,sizeof(adj));
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x][y]=w;
		adj[y][x]=w;
	}
	vector<vector<int> >a;
	for(int i=0;i<v;i++){
		vector<int>x;
		for(int j=0;j<v;j++){
			x.push_back(adj[i][j]);
		}
		a.push_back(x);
	}
	int src,dest;
	cout<<"Enter the source vertex: ";
	cin>>src;
	cout<<"Enter the destination vertex: ";
	cin>>dest;
	dijkstras(v,a,src,dest);
}