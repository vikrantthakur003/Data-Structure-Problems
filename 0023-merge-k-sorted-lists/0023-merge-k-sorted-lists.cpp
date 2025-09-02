    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
    */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int i = 0; i<lists.size(); i++){
            ListNode* tmp = lists[i];

            while(tmp != nullptr){
                minheap.push(tmp->val);
                tmp = tmp->next;
            }
        }

        ListNode* root = new ListNode(-1);
        ListNode* curr = root;

        while(!minheap.empty()){
            ListNode* newNode = new ListNode(minheap.top());
            curr->next = newNode;
            curr = curr->next;
            minheap.pop();
        }

        return root->next;
    }
};