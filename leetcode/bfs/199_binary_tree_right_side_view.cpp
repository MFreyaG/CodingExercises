#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root){
    queue<TreeNode*> queue;
    vector<int> result;

    if(root == nullptr)
        return result;

    queue.push(root);
    while(!queue.empty()){
        int level_size = queue.size();
        for(int i = 0; i < level_size; i++){
            TreeNode* current = queue.front();
            queue.pop();

            if(level_size - 1 == i) result.push_back(current->val);
            if(current->left) queue.push(current->left);
            if(current->right) queue.push(current->right);
        }
    }

    return result;
}

int main(){
    TreeNode n4(5), n5(4);
    TreeNode n2(2, nullptr, &n4), n3(3, nullptr, &n5);
    TreeNode n1(1, &n2, &n3);

    vector<int> result = rightSideView(&n1);
    for(auto num : result)
        cout << num << " ";
    cout << endl;

    TreeNode n8(2);
    TreeNode n7(1, &n8, nullptr);

    result = rightSideView(&n7);
    for(auto num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}