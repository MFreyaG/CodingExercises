#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head){
    ListNode* current = head;
    unordered_set<ListNode*> hash;

    while(current != nullptr){
        if(hash.find(current) == hash.end()) hash.insert(current);
        else return true;

        current = current->next;
    }

    return false;
}

int main(){
    return 0;
}