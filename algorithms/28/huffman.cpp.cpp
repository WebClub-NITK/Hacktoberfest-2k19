#include<bits/stdc++.h>
using namespace std;

#define SIZE 100


struct Node{
    int data;
    char symbol;
    struct Node* left;
    struct Node* right;
};
struct Node * newNode(int val,char ch){
    struct Node* node = (Node*)malloc(sizeof(struct Node));
    node->data =val;
    node->symbol=ch;
    node->left=NULL;
    node->right=NULL;
    return node;
    
}
void preorder(struct Node* root,string s){
    if(root->left==NULL && root->right==NULL){
        cout<<root->symbol<<" "<<s<<endl;
        return;
    }
    preorder(root->left,s+'0');
    preorder(root->right,s+'1');
    
    
}
struct comp{
    bool operator()(Node* const &n1 ,Node* const  &n2) 
    {
      return n1->data >n2->data;
    }
};

int main() {
    
        
        string s;
        cin>>s;
        // cout<<s;
        
        int l =s.length();
        vector<int>v;
        vector<char>v1;
        
        int freq[SIZE]={0};
        for(int i=0;i<l;i++){
            freq[s[i]-'!']++;
        }
        
        // for(int i=0;i<26;i++){
        //     cout<<freq[i]<<" ";
        // }
        
        for(int i=0;i<l;i++){
            if(freq[s[i]-'!']!=0){
                v1.push_back(s[i]);
                v.push_back(freq[s[i]-'!']);
                freq[s[i]-'!']=0;
            }
        }
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        //     // cout<<2;
        // }
        
       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        priority_queue<struct Node*, vector<struct Node*>,comp>q;
        
        for(int i=0;i<v.size();i++){
            q.push(newNode(v[i],v1[i]));
        }
        
        
        while(q.size()!=1){
            
            struct Node* node1=q.top();
            q.pop();
            
            struct Node* node2=q.top();
            q.pop();
            
            struct Node* root=newNode(-1,'#');
            root->data =node1->data+node2->data;
            root->left=node1;
            root->right=node2;
            root->symbol='#';
            
            q.push(root);
        }
        
        preorder(q.top(),"");
        cout<<endl;
        
    

	return 0;
}