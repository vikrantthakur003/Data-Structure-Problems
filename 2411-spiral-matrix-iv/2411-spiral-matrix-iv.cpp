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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        ListNode* curr = head;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        int direction = 0;

        while (left <= right && top <= bottom) {

            if (direction == 0) {

                for (int i = left; i <= right; i++) {
                    if (curr != nullptr) {
                        matrix[top][i] = curr->val;
                        curr = curr->next;
                    } else {
                        matrix[top][i] = -1;
                    }
                }

                direction = 1;
                top++;
            } else if (direction == 1) {

                for (int i = top; i <= bottom; i++) {
                    if (curr != nullptr) {
                        matrix[i][right] = curr->val;
                        curr = curr->next;
                    } else {
                        matrix[i][right] = -1;
                    }
                }

                direction = 2;
                right--;
            } else if (direction == 2) {

                for (int i = right; i >= left; i--) {
                    if (curr != nullptr) {
                        matrix[bottom][i] = curr->val;
                        curr = curr->next;
                    } else {
                        matrix[bottom][i] = -1;
                    }
                }

                direction = 3;
                bottom--;
            } else if (direction == 3) {

                for (int i = bottom; i >= top; i--) {
                    if (curr != nullptr) {
                        matrix[i][left] = curr->val;
                        curr = curr->next;
                    } else {
                        matrix[i][left] = -1;
                    }
                }

                direction = 0;
                left++;
            }
        }

        return matrix;
    }
};