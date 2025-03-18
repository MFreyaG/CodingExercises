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

void preOrderDFS(vector<int>& result, TreeNode* node){
    if(node == nullptr){
        result.push_back(-101);
        return;
    }

    result.push_back(node->val);
    preOrderDFS(result, node->left);
    preOrderDFS(result, node->right);
}

void postOrderDFS(vector<int>& result, TreeNode* node){
    if(node == nullptr){
        result.push_back(-101);
        return;
    }

    result.push_back(node->val);
    postOrderDFS(result, node->right);
    postOrderDFS(result, node->left);
}

bool isSymmetric(TreeNode* root) {
    vector<int> result1, result2;

    preOrderDFS(result1, root->left);
    postOrderDFS(result2, root->right);

    if(result1.size() != result2.size())
        return false;

    for(int i = 0; i < result1.size(); i++){
        if(result1[i] != result2[i])
            return false;
    }

    return true;
}

int main(){
    TreeNode n4(3), n5(4), n6(4), n7(3);
    TreeNode n2(2, &n4, &n5), n3(2, &n6, &n7);
    TreeNode n1(1, &n2, &n3);

    cout << isSymmetric(&n1) << endl;

    TreeNode n11(3), n12(3);
    TreeNode n9(2, nullptr, &n11), n10(2, nullptr, &n12);
    TreeNode n8(1, &n9, &n10);

    cout << isSymmetric(&n8) << endl;

    return 0;
}