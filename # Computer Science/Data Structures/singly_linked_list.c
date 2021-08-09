/**
 * Singly linked list in C programming language.
 *
 * @Date    09 August, 2021
 * @Author  Hao Ren, <haoren.2906@gmail.com>
 * @GitHub  <https://github.com/flying-yogurt>
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *next;
} ListNode;

typedef struct list {
    ListNode *head;
} SinglyList;

// ----------------------------------------------------------------------------

ListNode *createNode(int value) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = value;
    new->next = NULL;
    return new;
}

void insertNodeAfter(ListNode *node, ListNode *insert) {
    insert->next = node->next;
    node->next = insert;
}

void insertNodeHead(SinglyList *linkedList, ListNode *insert) {
    insert->next = linkedList->head;
    linkedList->head = insert;
}

void removeNodeAfter(ListNode *node) {
    if (node->next != NULL) {
        ListNode *destory = node->next;
        node->next = node->next->next;
        free(destory);
        destory = NULL;
    } else {
        printf("The node you want to delete does not exist.\n");
    }
}

void removeNodeHead(SinglyList *linkedList) {
    if (linkedList->head != NULL) {
        ListNode *destory = linkedList->head;
        linkedList->head = linkedList->head->next;
        free(destory);
        destory = NULL;
    } else {
        printf("The node you want to delete does not exist.\n");
    }
}

int findValue(SinglyList *linkedList, int value) {
    int isFound = 0;
    ListNode *current = linkedList->head;
    while (current != NULL) {
        if (current->val == value) {
            isFound = 1;
        }
        current = current->next;
    }
    return isFound;
}

int size(SinglyList *linkedlist) {
    int size = 0;
    ListNode *current = linkedlist->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void printSinglyList(SinglyList *linkedList) {
    if (linkedList->head != NULL) {
        ListNode *current = linkedList->head;
        while (current != NULL) {
            printf("%d -> ", current->val);
            if (current->next == NULL) {
                printf("NULL\n");
            }
            current = current->next;
        }
    } else {
        printf("The linked list does not exist.\n");
    }
}

void freeList(SinglyList *linkedList) {
    ListNode *current = linkedList->head;
    while (current != NULL) {
        ListNode *destory = current;
        current = current->next;
        free(destory);
        destory = NULL;
    }
    free(linkedList);
    linkedList = NULL;
}

// ----------------------------------------------------------------------------

/**
 * To run tests, execute following commands:
 *   $ clang singly_linked_list.c -o singly_linked_list
 *   $ ./singly_linked_list
 * and expected outputs would be showed below each testing part.
 */
void testVisually_SinglyLinkedList() {
    SinglyList *singly = (SinglyList *)malloc(sizeof(SinglyList));
    singly->head = NULL;

    ListNode *one = createNode(1);
    ListNode *two = createNode(2);
    ListNode *four = createNode(4);
    ListNode *five = createNode(5);
    insertNodeHead(singly, one);
    insertNodeAfter(one, two);
    insertNodeAfter(two, four);
    insertNodeAfter(four, five);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 4 -> 5 -> NULL

    printf("\n");

    ListNode *three = createNode(3);
    insertNodeAfter(two, three);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 5
    //   1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    ListNode *zero = createNode(0);
    insertNodeHead(singly, zero);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 6
    //   0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    printf("Find value 3: %d\n", findValue(singly, 3));
    printf("Find value 7: %d\n", findValue(singly, 7));
    // OUTPUT:
    //   Find value 3: 1
    //   Find value 7: 0

    printf("\n");

    removeNodeHead(singly);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 5
    //   1 -> 2 -> 3 -> 4 -> 5 -> NULL

    printf("\n");

    removeNodeAfter(three);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 3 -> 5 -> NULL

    printf("\n");

    removeNodeAfter(five);
    // OUTPUT:
    //   The node you want to delete does not exist.

    printf("\n");

    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 4
    //   1 -> 2 -> 3 -> 5 -> NULL

    printf("\n");

    removeNodeHead(singly);
    removeNodeAfter(two);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 2
    //   2 -> 5 -> NULL

    printf("\n");

    removeNodeHead(singly);
    removeNodeHead(singly);
    printf("Size: %d\n", size(singly));
    printSinglyList(singly);
    // OUTPUT:
    //   Size: 0
    //   The linked list does not exist.

    freeList(singly);
}

// ----------------------------------------------------------------------------

int main(void) {
    testVisually_SinglyLinkedList();
    return 0;
}
