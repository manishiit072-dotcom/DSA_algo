#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    struct TrieNode {
    TrieNode* children[26];
    
    TrieNode(){
       
        for(int i=0;i<26;i++)
            children[i]=nullptr;
    }

    bool containsKey(char ch){
        return children[ch-'a']!=nullptr;
    }
    void put(char ch, TrieNode* node){
        children[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return children[ch-'a'];
    }
    
    

};
    int countSubs(string& s) {
        int n=s.length();
        int cnt=0;
        TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++)
        {
            TrieNode* node=root;
            
            for(int j=i;j<n;j++)
            {
               if(!node->containsKey(s[j]))
               {
                   cnt++;
                   node->put(s[j], new TrieNode());
               }
               node=node->get(s[j]);
            }
        }
        
        return cnt;
        
    }
};