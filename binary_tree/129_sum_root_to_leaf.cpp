#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* node, TreeNode* father, string curr, int left, int &buffer){
    if(node == nullptr){
        if(father->left == nullptr && father->right == nullptr && left == 1)
            buffer += stoi(curr);
        return;
    }

    curr += to_string(node->val);
    preOrder(node->left, node, curr, 1, buffer);
    preOrder(node->right, node, curr, 0, buffer);
}

int sumNumbers(TreeNode* root) {
    int buffer = 0;
    preOrder(root, nullptr, "", 0, buffer);

    return buffer;
}

int main(){
    TreeNode n2(2), n3(3);
    TreeNode n1(1, &n2, &n3);

    cout << sumNumbers(&n1) << endl;

    TreeNode n4(1), n5(2, &n4, nullptr);

    cout << sumNumbers(&n5) << endl;

    TreeNode n9(5), n10(1);
    TreeNode n7(9, &n9, &n10), n8(0);
    TreeNode n6(4, &n7, &n8);

    cout << sumNumbers(&n6) << endl;

    return 0;
}