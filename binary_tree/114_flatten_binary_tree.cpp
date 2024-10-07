#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* node, vector<TreeNode*>& nodes){
    if(node == nullptr)
        return;
    
    nodes.push_back(node);
    preOrder(node->left, nodes);
    preOrder(node->right, nodes);
}

void flatten(TreeNode* root){
    vector<TreeNode*> nodes;
    preOrder(root, nodes);

    for(int i = 1; i < nodes.size(); i++){
        nodes[i-1]->right = nodes[i];
        nodes[i-1]->left = nullptr;
    }
}

int main(){
    TreeNode n4(3), n5(4), n6(6);
    TreeNode n2(2, &n4, &n5), n3(5, nullptr, &n6);
    TreeNode n1(1, &n2, &n3);

    flatten(&n1);

    return 0;
}