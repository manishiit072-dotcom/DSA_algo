#include<bits/stdc++.h>
using namespace std;

// TC-> O(N*32)+O(N*32)
// SC-> O(N*32)
struct TrieNode{
    vector<TrieNode*> links[2];
    bool containsKey(int bit)
    {
          return links[bit]!=nullptr;
    }

    TrieNode* get(int bit)
    {
        return links[bit];
    }

    void put(int bit,TrieNode* node)
    {
        links[bit]=node;
    }
}

class Trie{
    private:
       TrieNode* root;

    public:
      void insert(int num)
      {
        TrieNode* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new TrieNode());
            }
            node=node->get(bit);
        }
      }
      int getMax(int num)
      {
          TrieNode* node=root;
          int maxNum=0;
          for(int i=31;i>=0;i--)
          {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum=maxNum|(1<<i);
                node=node->get(1-bit);

            }
            else
            {
                node=node->get(bit);
            }
          }

          return maxNum;
      }
}

int main()
{
    vector<int> nums={3,10,5,25,2,8};
    Trie trie;
    for(int num:nums)
    {
        trie.insert(num);
    }
    int maxXor=0;
    for(int num:nums)
    {
        maxXor=max(maxXor,trie.getMax(num));
    }
    cout<<maxXor<<"\n";
    return 0;
}