// Hao Ren
// 01 March, 2022
// 203. Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// NOTE: The "free()" function is used to defend memory leaking.
struct ListNode *removeElements(struct ListNode *head, int val) {
    // Remove required elements at the head of the list.
    while (head != NULL && head->val == val) {
        struct ListNode *destory = head;
        head = head->next;
        free(destory);
        destory = NULL;
    }

    // Because we skip all removed starting elements, the new head
    // must be a "NULL" or a node that "head->val != val".
    if (head == NULL) {
        return NULL;
    }

    // Therefore, we could compare elements from the second node.
    struct ListNode *curr = head;
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode *destory = curr->next;
            curr->next = curr->next->next;
            free(destory);
            destory = NULL;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
