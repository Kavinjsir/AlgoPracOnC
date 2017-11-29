/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        bool flag = false;
        int len = lists.size();
        do{
            flag = false;
            for(int i = 0; i < len; ++i){
                if(lists[i] == NULL)
                    continue;
                flag = true;
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        } while (flag == true);
        
        while(!pq.empty()){
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        cur = head->next;
        delete head;
        return cur;
    }
};