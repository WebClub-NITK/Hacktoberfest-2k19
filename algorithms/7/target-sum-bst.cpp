#include<bits/stdc++.h>
using namespace std;
#define fo(i,v,e) for(v=i;v<e;v++)
int first=-2147483648,second=-2147483648;
struct node
{
	int data;
	node *left,*right;
};
node* createNode(int data)
{
  node* temp = (node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
void getanspair(node* tree1,node* tree2,int required)
{
	if(tree1==NULL or tree2==NULL)return;
	else if(required==tree1->data+tree2->data){first = tree1->data;second = tree2->data;return;}
    else if(required<tree1->data+tree2->data)
    {
       getanspair(tree1->left,tree2,required);
       getanspair(tree1,tree2->left,required);
      }
      else
      {
      getanspair(tree1->right,tree2,required);
       getanspair(tree1,tree2->right,required);	
      }
}
node* constructTreeFromSortedData(int start,int end,int *arr)
{   if(start>end)return NULL;
	if(start==end)return createNode(arr[start]);
	int mid = (start+end)/2;
    node* temp = createNode(arr[mid]);
    temp->left = constructTreeFromSortedData(start,mid-1,arr);
    temp->right = constructTreeFromSortedData(mid+1,end,arr);
    return temp;
}
int main()
{ node *tree1=NULL,*tree2=NULL;
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
  tree1 = constructTreeFromSortedData(0,n1-1,arr1);
  tree2 = constructTreeFromSortedData(0,n2-1,arr2);
  getanspair(tree1,tree2,required);
  if(first==-2147483648 and second ==-2147483648){cout<<"cann't get such pair\n";}
  else {cout<<"ans is "<<first<<' '<<second<<endl;}
}