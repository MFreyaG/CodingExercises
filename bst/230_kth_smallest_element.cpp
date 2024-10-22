#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inDFS(TreeNode* node, vector<int>& inorder){
    if(node == nullptr) return;

    inDFS(node->left, inorder);
    inorder.push_back(node->val);
    inDFS(node->right, inorder);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;
    inDFS(root, inorder);

    return inorder[k-1];
}

int main(){
    return 0;
}