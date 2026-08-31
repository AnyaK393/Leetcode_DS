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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while(curr->next != nullptr) {

            // Check if curr is a critical point
            if((curr->val > prev->val && curr->val > curr->next->val) ||
               (curr->val < prev->val && curr->val < curr->next->val)) {

                // First critical point
                if(first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }

                // Update last critical point
                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Need at least two critical points
        if(first == last) {
            return ans;
        }

        // Minimum distance
        ans[0] = minDist;

        // Maximum distance
        ans[1] = last - first;

        return ans;
    }
};