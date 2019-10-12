class disjoint:
	def __init__(self,n):
		self.parent=[]*n
		self.rank=[]*n
		
	def makeset(self,x):
		self.parent.insert(x,x)
		self.rank.insert(x,0)

	def findset(self,x):
		if self.parent[x]!=x:
			self.parent[x]=self.findset(self.parent[x])
		return self.parent[x]

	def union_by_rank(self,a,b):
		x=self.findset(a)
		y=self.findset(b)
		if self.rank[x]>self.rank[y]:
			self.parent[y]=x

		elif self.rank[x]<self.rank[y]:
			self.parent[x]=y

		else:
			self.parent[y]=x

	def kruskal(self,w):
		w.sort(key=lambda w:w[2])
		t=[]
		n=len(w)
		wt=0
		for i in range(n):
			if self.findset(w[i][0])!=self.findset(w[i][1]):
				t.append([w[i][0],w[i][1]])
				wt+=w[i][2]
				self.union_by_rank(w[i][0],w[i][1])
		print()
		print("The MST by kruskal Algorithm is: ",t)
		print()
		print("The total weight of the MST is: ",wt)

def main():
	n=int(input("Enter the number of nodes: "))
	d=disjoint(n)
	for i in range(n):
		d.makeset(i)
	m=int(input("Enter the number of edges: "))
	wt=[]*m
	print("Enter the edges: ")
	for i in range(m):
		u,v,w=input().split()
		u=int(u)
		v=int(v)
		w=int(w)
		wt.append([u,v,w])
	d.kruskal(wt)

if __name__=='__main__':
	main()