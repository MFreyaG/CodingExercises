#include <iostream>
#include <string>
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

vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<double> result;

    queue.push(root);
    while(!queue.empty()){
        int level_size = queue.size();
        double buffer = 0;

        for(int i = 0; i < level_size; i++){
            TreeNode* current = queue.front();
            buffer += current->val;
            queue.pop();

            if(i == level_size - 1) result.push_back(buffer/level_size);
            if(current->left) queue.push(current->left);
            if(current->right) queue.push(current->right);
        }
    }

    return result;
}

int main(){
    TreeNode n4(15), n5(7);
    TreeNode n2(9), n3(20, &n4, &n5);
    TreeNode n1(3, &n2, &n3);

    vector<double> result = averageOfLevels(&n1);
    for(auto num : result) cout << num << " ";
    cout << endl;

    TreeNode n9(15), n10(7);
    TreeNode n7(9, &n9, &n10), n8(20);
    TreeNode n6(3, &n7, &n8);

    result = averageOfLevels(&n6);
    for(auto num : result) cout << num << " ";
    cout << endl;

    return 0;
}