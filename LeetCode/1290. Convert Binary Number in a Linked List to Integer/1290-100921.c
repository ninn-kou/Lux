/**
 * @author Hao Ren
 * 10 September, 2021
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode *head) {
    int sum = 0;
    for (struct ListNode *curr = head; curr != NULL; curr = curr->next) {
        sum = sum << 1 | curr->val;
    }
    return sum;
}
