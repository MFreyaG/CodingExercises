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

void preOrderDFS(int& max, int& local_max, TreeNode* node){
    if(node == nullptr)
        return;

    local_max++;
    if(local_max > max)
        max = local_max;

    preOrderDFS(max, local_max, node->left);
    preOrderDFS(max, local_max, node->right);

    local_max--;
}

int maxDepth(TreeNode* root) {
    int max = 0, local_max = 0;
    preOrderDFS(max, local_max, root);

    return max;
}

int main(){
    TreeNode n4(4), n5(5);
    TreeNode n3(3, &n4, &n5), n2(2);
    TreeNode n1(1, &n2, &n3);

    int max = maxDepth(&n1);

    cout << max << endl;
    return 0;
}