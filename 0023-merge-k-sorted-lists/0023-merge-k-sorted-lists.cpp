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
struct camp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, camp> minheap;

        for(int i = 0; i<lists.size(); i++){
            ListNode* tmp = lists[i];

            if(tmp){
                minheap.push(tmp);
            }
        }

        ListNode* root = new ListNode(-1);
        ListNode* curr = root;

        while(!minheap.empty()){
            ListNode* newNode = minheap.top();
            minheap.pop();
            
            curr->next = newNode;
            curr = curr->next;

            if(newNode->next){
                minheap.push(newNode->next);
            }
        }

        return root->next;
    }
};