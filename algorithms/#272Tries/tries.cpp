#include <iostream>
#include <string.h>
using namespace std;

const int _alphabetSize_=26;

struct TrieNode{
    //A Trie can have at most 26 nodes for children, in English
    struct TrieNode *children[_alphabetSize_];
    //The node can be a word as well as part of a word, like Hand and Hands
    bool isEndOfWord;
};

//search for nodes
bool search(struct TrieNode* root, string key){
  cout<<"searching for word \""<<key<<"\"\n";
  struct TrieNode *traversal = root;
  int idx;
  for(int i=0;i<key.length();i++){
    idx=key[i]-'a';
    if(!traversal->children[idx])
      return false;
    traversal=traversal->children[idx];
  }
  if(traversal!=NULL && traversal->isEndOfWord)
    return true;
  else
    return false;
}


//function declaration for making new blank node
struct TrieNode* newNode(){
  struct TrieNode *node = new TrieNode;
  node->isEndOfWord = false;
  for(int i=0;i<_alphabetSize_;i++)
    node->children[i] = NULL;

  return(node);
}

//insert node
void insert(struct TrieNode *root, string path){
  //We'll build a traversal along the path, and place isEndOfWord to true at end.
  struct TrieNode *traversal = root;
  int idx;
  //consider forcibly converting every string to lowercase to increase robustness
  for(int i=0;i<path.length();i++){
    idx=path[i]-'a';
    if(!traversal->children[idx])
      traversal->children[idx]=newNode();
    traversal=traversal->children[idx];
  }
  traversal->isEndOfWord = true;
  cout<<"Inserted word \""<<path<<"\"\n";
  return;
}

//delete node
void deleteNode(struct TrieNode* root, string word){
  struct TrieNode *traversal = root;
  cout<<"Deleting word \""<<word<<"\"\n";
  int idx;
  for(int i=0;i<word.length();i++){
    idx=word[i]-'a';
    if(!traversal->children[idx])
      return;
    traversal=traversal->children[idx];
  }
  if(traversal!=NULL && traversal->isEndOfWord)
    traversal->isEndOfWord = false;
  return;
}

int main(){
  string word[] = {"hello",
                    "howdy",
                    "hola",
                    "bottle",
                    "pen",
                    "pens",
                    "penstand"};
  int n = sizeof(word)/sizeof(word[0]);
  struct TrieNode *root = newNode();

  for(int i=0;i<n;i++)
    insert(root, word[i]);
  cout<<">>Expecting O/P 1,0\n";
  cout<<search(root, "hello")<<"\n";
  cout<<search(root, "yankee")<<"\n";
  deleteNode(root, "hello");
  insert(root, "yankee");
  cout<<">>Expecting O/P 0,1\n";
  cout<<search(root, "hello")<<"\n";
  cout<<search(root, "yankee")<<"\n";
  return(0);
}
