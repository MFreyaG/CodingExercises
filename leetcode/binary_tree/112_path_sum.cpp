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

void preOrder(TreeNode* node, TreeNode* father, int target, int currsum, bool &has_sum){
    if(node == nullptr){
        if(currsum == target && father->left == nullptr && father->right == nullptr)
            has_sum = true;
        return;
    }

    currsum += node->val;
    preOrder(node->left, node, target, currsum, has_sum);
    preOrder(node->right, node, target, currsum, has_sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    bool has_sum = false;
    if(root == nullptr)
        return has_sum;

    preOrder(root, nullptr, targetSum, 0, has_sum);

    return has_sum;
}

int main(){
    TreeNode n7(7), n8(2), n9(1);
    TreeNode n4(11, &n7, &n8), n5(13), n6(4, nullptr, &n9);
    TreeNode n2(4, &n4, nullptr), n3(8, &n5, &n6);
    TreeNode n1(5, &n2, &n3);

    int targetSum = 22;
    cout << hasPathSum(&n1, targetSum) << endl;

    TreeNode n11(2);
    TreeNode n10(1, &n11, nullptr);

    targetSum = 1;
    cout << hasPathSum(&n10, targetSum) << endl;

    return 0;
}