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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue;
    if(root == nullptr) return result;

    queue.push(root);

    int curr_level = 0;
    while(!queue.empty()){
        int level_size = queue.size();
        vector<int> new_level;
    
        result.push_back(new_level);
        for(int i = 0; i < level_size; i++){
            TreeNode* current = queue.front();
            queue.pop();
        
            result[curr_level].push_back(current->val);
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
        curr_level++;
    }

    for(int i = 0; i < result.size(); i++){
        vector<int> aux;
        if(i % 2 == 1){
            for(int j = result[i].size() - 1; j >= 0; j--){
                aux.push_back(result[i][j]);
            }
            result[i] = aux;
        }    
    }
    return result;
}

int main(){
    TreeNode n4(15), n5(7);
    TreeNode n2(9), n3(20, &n4, &n5);
    TreeNode n1(3, &n2, &n3);

    vector<vector<int>> result = zigzagLevelOrder(&n1);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}