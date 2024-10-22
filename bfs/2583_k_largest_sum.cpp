#include <iostream>
#include <queue>
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

vector<long long> bfs(TreeNode* root) {
    vector<long long> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        long long levelSum = 0;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            levelSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(levelSum);
    }

    return result;
}

long long kthLargestLevelSum(TreeNode* root, int k) {
    if (!root) return -1;

    vector<long long> levelSums = bfs(root);
    if (levelSums.size() < k) return -1;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (long long sum : levelSums) {
        minHeap.push(sum);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main(){
    TreeNode n4(2), n5(1), n6(3), n7(7);
    TreeNode n2(8, &n4, &n5), n3(9, &n6, &n7);
    TreeNode n1(5, &n2, &n3);

    int k = 2;
    cout << kthLargestLevelSum(&n1, k) << endl;

    TreeNode n12(3);
    TreeNode n11(2, &n12, nullptr);
    TreeNode n10(1, &n11, nullptr);

    k = 1;
    cout << kthLargestLevelSum(&n10, k) << endl;

    return 0;
}