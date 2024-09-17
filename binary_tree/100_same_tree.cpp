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

void preOrderDFS(vector<int>& vec, TreeNode* node){
    if(node == nullptr){
        vec.push_back(-1001);
        return;
    }

    vec.push_back(node->val);
    preOrderDFS(vec, node->left);
    preOrderDFS(vec, node->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int> p_val, q_val;
    preOrderDFS(p_val, p);
    preOrderDFS(q_val, q);

    if(p_val.size() != q_val.size())
        return false;
    
    for(int i = 0; i < q_val.size(); i++){
        if(p_val[i] != q_val[i])
            return false;
    }

    return true;
}

int main(){
    TreeNode n2(2);
    TreeNode n1(1, &n2, nullptr);

    TreeNode n4(2);
    TreeNode n3(1, nullptr, &n4);

    cout << isSameTree(&n1, &n3) << endl;
    return 0;
}