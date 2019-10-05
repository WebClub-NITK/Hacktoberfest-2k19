#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct TrieNode{
    struct TrieNode* children[26];
    bool isEndChar ;
};

struct TrieNode* getNode(){
    struct TrieNode * node =NULL;
    node = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if(node){
        int i;
        node->isEndChar = false;
        for(i=0;i<26;i++){
            node->children[i]= NULL;
        }
    }
    return node;
}

void insert(struct TrieNode* root,const char* key){
    int level;
    int len = strlen(key);
    int index;

    struct TrieNode* current = root;

    for(level =0;level<len;level++){

        index = key[level] - 'a';
        if(!current->children[index]){
            current->children[index] = getNode();
        }

        current = current->children[index];
    }

    current->isEndChar = true;
}

bool find(struct TrieNode* root, const char* key){

    int level;
    int len = strlen(key);
    int index;

    struct TrieNode* current = root;

    for(level =0;level<len;level++){

        index = key[level] - 'a';
        if(!current->children[index]){
            return false;
        }
        current = current->children[index];
    }

    return (current!=NULL && current->isEndChar);    
}

int main(){

    struct TrieNode* root = getNode();

    insert(root,"hello");
    insert(root,"world");
    insert(root,"this");
    insert(root,"is");
    insert(root,"awesome");
    insert(root,"wow");

    printf(find(root,"hello") ?"found hello\n":"didn't find hello\n");    
    printf(find(root,"wowi") ?"found wowi\n":"didn't find wowi\n");
    printf(find(root,"wow") ?"found wow\n":"didn't find wow\n");
    printf(find(root,"aweful") ?"found aweful\n":"didn't find aweful\n");
    printf(find(root,"awesome") ?"found awesome\n":"didn't find awesome\n");
    printf(find(root,"world") ?"found world\n":"didn't find world\n");

    return 0;
}