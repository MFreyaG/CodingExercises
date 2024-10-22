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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue;

    if(root == nullptr) return result;

    int current_level = 0;
    queue.push(root);
    while(!queue.empty()){
        vector<int> new_level;
        result.push_back(new_level);

        int level_size = queue.size();
        for(int i = 0; i < level_size; i++){
            TreeNode* current = queue.front();
            queue.pop();

            result[current_level].push_back(current->val);
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
        current_level++;
    }

    return result;
}

int main(){
    TreeNode n4(15), n5(7);
    TreeNode n2(9), n3(20, &n4, &n5);
    TreeNode n1(3, &n2, &n3);

    vector<vector<int>> result = levelOrder(&n1);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}