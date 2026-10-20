// C++ program to print diagonal view
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to print diagonal view
void diagonalRecur(Node *root, int level, 
                   unordered_map<int, vector<int>> &levelData) {

    // Base case
    if (root == nullptr)
        return;

    // Append the current node into hash map.
    levelData[level].push_back(root->data);

    // Recursively traverse the left subtree.
    diagonalRecur(root->left, level + 1, levelData);

    // Recursively traverse the right subtree.
    diagonalRecur(root->right, level, levelData);
}

// function to print diagonal view
vector<int> diagonal(Node *root) {
    vector<int> ans;

    // Create a hash map to store each
    // node at its respective level.
    unordered_map<int, vector<int>> levelData;
    diagonalRecur(root, 0, levelData);

    int level = 0;

    // Insert into answer level by level.
    while (levelData.find(level) != levelData.end()) {
        vector<int> v = levelData[level];
        for (int j = 0; j < v.size(); j++) {
            ans.push_back(v[j]);
        }
        level++;
    }

    return ans;
}

void printList(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    // Create a hard coded tree
    //         8
    //       /   \
    //     3      10
    //    /      /  \
    //   1      6    14
    //         / \   /
    //        4   7 13
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    vector<int> ans = diagonal(root);
    printList(ans);
}