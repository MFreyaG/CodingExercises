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

void preOrderDFS(TreeNode* node){
    if(node == nullptr) return;

    TreeNode* aux = node->left;
    node->left = node->right;
    node->right = aux;

    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

void printTree(TreeNode* node){
    if(node == nullptr) return;

    cout << node->val << " ";

    printTree(node->left);
    printTree(node->right);    
}

TreeNode* invertTree(TreeNode* root) {
    preOrderDFS(root);
    return root;
}

int main(){
    TreeNode n4(1), n5(3);
    TreeNode n6(6), n7(9);
    TreeNode n2(2, &n4, &n5), n3(7, &n6, &n7);
    TreeNode n1(4, &n2, &n3);

    printTree(&n1);
    cout << endl;

    invertTree(&n1);

    printTree(&n1);
    cout << endl;

    return 0;
}