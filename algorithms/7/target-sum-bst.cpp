#include<bits/stdc++.h>

using namespace std;

// micro for loop
#define fo(i,v,e) for(v=i;v<e;v++)

// first and second to store ans pair if ans doesn't exist they will be int_min 
int first=-2147483648,second=-2147483648;
// tree node
struct node
{
	int data;
	node *left,*right;
};
// to create a new node dynamically
node* createNode(int data)
{
  node* temp = (node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
// if ans exist it will be stored in to first and second
void getanspair(node* tree1,node* tree2,int required)
{
	if(tree1==NULL or tree2==NULL)return;
//if sum of two elements = target store it and return
	else if(required==tree1->data+tree2->data){first = tree1->data;second = tree2->data;return;}
// if target is less then sum then we need to go  
// in left either in first tree or in second tree
// so we will check for both
    else if(required<tree1->data+tree2->data)
    {
       getanspair(tree1->left,tree2,required);
       getanspair(tree1,tree2->left,required);
      }
// if target is greater then sum then we need to go  
// in right either in first tree or in second tree
// so we will check for both
      else
      {
      getanspair(tree1->right,tree2,required);
      getanspair(tree1,tree2->right,required);	
      }
}
//construct balanced binary search tree from sorted data recursively
node* constructTreeFromSortedData(int start,int end,int *arr)
{ if(start>end)return NULL;

	if(start==end)return createNode(arr[start]);

	int mid = (start+end)/2;

  node* temp = createNode(arr[mid]);

  temp->left = constructTreeFromSortedData(start,mid-1,arr);

  temp->right = constructTreeFromSortedData(mid+1,end,arr);

  return temp;
}
int main()
{ 
// initallize two tree 
  node *tree1=NULL,*tree2=NULL;

  int n1,n2,i,j,required;

  cout<<"enter number of elements in first tree : ";
  
  cin>>n1;int arr1[n1];
  
  cout<<"enter elements of first tree : ";
  
  fo(0,i,n1)cin>>arr1[i];sort(arr1,arr1+n1);
  
  cout<<"enter number of elements in second tree : ";
  
  cin>>n2;int arr2[n2];
  
  cout<<"enter elements of first tree : ";
  
  fo(0,i,n2)cin>>arr2[i];
  
  cout<<"enter the sum to be searched : ";
  
  cin>>required;

// construct first tree fro user input  
  tree1 = constructTreeFromSortedData(0,n1-1,arr1);
  
// construct second tree  
  tree2 = constructTreeFromSortedData(0,n2-1,arr2);
//get answer if exist
  getanspair(tree1,tree2,required);
//if ans doesn't exist
  if(first==-2147483648 and second ==-2147483648){cout<<"cann't get such pair\n";}
//if answer exist
  else {cout<<"ans is "<<first<<' '<<second<<endl;}
}