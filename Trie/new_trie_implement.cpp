#include<bits/stdc++.h> // leetcode 3093
using namespace std;
class TrieNode{
public:
    TrieNode* children[26];
    int smallIdx;
    int smallSize;

    TrieNode()
    {
        for(int i=0;i<26;i++)
          children[i]=nullptr;

          smallIdx=-1;
          smallSize=INT_MAX;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }
    
    void updateNode(TrieNode* node,int size,int idx)
    {
        if(size<node->smallSize)
        {
            node->smallSize=size;
            node->smallIdx=idx;
        }
        else if(size==node->smallSize)
        {
            node->smallIdx=min(idx,node->smallIdx);
        }
    }
    void insert(string& word,int idx)
    {
        TrieNode* node=root;
        updateNode(node,word.size(),idx);
        for(char ch:word)
        {
            if(!node->children[ch-'a'])
            {
                 node->children[ch-'a']=new TrieNode();
            }
            node=node->children[ch-'a'];
            updateNode(node,word.size(),idx);
        }
    }

    int search(string& word)
    {
        TrieNode* node=root;
        for(char ch:word)
        {
            if(node->children[ch-'a'])
            {
                break;
            }
            node=node->children[ch-'a'];
        }
        return node->smallIdx;
    }
};