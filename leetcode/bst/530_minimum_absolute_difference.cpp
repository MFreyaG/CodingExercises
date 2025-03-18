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

int getMinimumDifference(TreeNode* root) {
    vector<int> inorder;
    inDFS(root, inorder);

    int min = INT_MAX;
    for(int i = 1; i < inorder.size(); i++){
        int difference = inorder[i] - inorder[i-1];
        if(difference < min) min = difference;
    }

    return min;
}

int main(){
    return 0;
}