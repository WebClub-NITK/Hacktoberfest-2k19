Dijkstra's algorithm aka the shortest path algorithm is used to find the shortest path in a graph that covers all the vertices.

Given a graph with the starting vertex.

/////////  Algorithm ////////////////

1.Initially Dset contains src
dist[s]=0 dist[v]= ∞

2. Set Dset to initially empty

3. While all the elements in the graph are not added to 'Dset'

A.Let ‘u’ be any vertex not in ‘Dset’ and has minimum label    dist[u]
B.Add ‘u’ to Dset
C.Update the label of the elements adjacent to u
For each vertex ‘v’ adjacent to u
If ‘v’ is not in ‘Dset’ then 
	If dist[u]+weight(u,v)<dist[v] then
		Dist[v]=dist[u]+weight(u,v)  
