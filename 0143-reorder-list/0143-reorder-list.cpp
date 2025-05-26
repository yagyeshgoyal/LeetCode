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
    void reverselist(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* future = head;

        while(future != NULL){
            prev = curr;
            curr = future;
            future = future->next;
            curr->next = prev;

        }

        head = curr;

        // ListNode* temp = head;
        // cout<<"k"<<endl;
        // while(temp != NULL){
        //     cout<<temp->val<<endl;
        //     temp = temp->next;
        // }

    }
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int k = (count+1)/2;
        ListNode* head2;

        temp = head;
        while(temp != NULL){
            k--;

            if(k == 0){
                head2 = temp->next;
                temp->next = NULL;
                break;
            }
            
            temp = temp->next;
        }

        reverselist(head2);

        ListNode* curr = head;
        temp = head->next;
        
        while(temp != NULL || head2 != NULL){
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
            if(temp != NULL){
                curr->next = temp;
            curr = curr->next;
            temp = temp->next;
            }
            
        }
    }
};