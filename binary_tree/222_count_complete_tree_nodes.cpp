#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* node, int& node_number){
    if(node == nullptr)
        return;

    node_number++;
    preOrder(node->left, node_number);
    preOrder(node->right, node_number);
}

int countNodes(TreeNode* root){
    int node_number = 0;
    if(root == nullptr)
        return node_number;

    preOrder(root, node_number);

    return node_number;
}

int main(){
    TreeNode n4(4), n5(5), n6(6);
    TreeNode n2(2, &n4, &n5), n3(3, &n6, nullptr);
    TreeNode n1(1, &n2, &n3);

    cout << countNodes(&n1) << endl;
    
    return 0;
}