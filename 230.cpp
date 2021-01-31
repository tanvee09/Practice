// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s; 
    TreeNode *curr = root; 
    int i = 0;
    
    while (curr != nullptr || !s.empty()) { 
        while (curr !=  nullptr) { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
        i++;
        if (i == k)
            return curr->val;
        curr = curr->right; 
    } 
    return -1;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    cout << kthSmallest(root, 2) << endl;
    return 0;
}