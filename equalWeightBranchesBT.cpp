// Minimum cost to make all branches of a binary tree equal in weight

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data, left_cost, right_cost;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
        left_cost = right_cost = 0;
    }
};

int iterativeMaxHt(Node *root, int &cost) {
    if (root->left == nullptr && root->right == nullptr) 
        return 0;
    if (root->left == nullptr) 
        return root->right_cost;
    if (root->right == nullptr) 
        return root->left_cost;
    int lh = iterativeMaxHt(root->left, cost) + root->left_cost;
    int rh = iterativeMaxHt(root->right, cost) + root->right_cost;
    cost += abs(lh - rh);
    return max(lh, rh);
};

int minCost(Node *root) {
    int cost = 0;
    iterativeMaxHt(root, cost);
    return cost;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    n1->left = n2, n1->left_cost = 1;
    n1->right = n3, n1->right_cost = 2;
    n2->left = n4, n2->left_cost = 2;
    n2->right = n5, n2->right_cost = 2;
    n3->left = n6, n3->left_cost = 4;
    n3->right = n7, n3->right_cost = 2;
    n4->left = n8, n4->left_cost = 1;
    n4->right = n9, n4->right_cost = 3;
    cout << minCost(n1) << endl;
    return 0;
}