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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = 0;

       
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }

        vector<int> sum(cnt, 0);

       
        ListNode* temp = head;
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++) {
            sum[i] += temp->val;
            sum[cnt - i - 1] += slow->val;
            temp = temp->next;
            slow = slow->next;
        }
        for(auto i:sum){
            cout << i << " ";
        }
        cout << endl;

        // Return the maximum value in the sum vector
        return *max_element(sum.begin(), sum.end());
    }
};
