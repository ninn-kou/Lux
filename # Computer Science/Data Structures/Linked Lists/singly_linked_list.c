/**
 * Singly linked list in C programming language.
 *
 * @Date    09 August, 2021
 * @Author  Hao Ren, <haoren.2906@gmail.com>
 * @GitHub  <https://github.com/flying-yogurt>
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * The singly linked list data structure.
 */

typedef struct node {
    int val;
    struct node *next;
} ListNode;

typedef struct list {
    ListNode *head;
} SinglyList;

/**
 * Initializing.
 */

SinglyList *createSinglyList() {
    SinglyList *list = (SinglyList *)malloc(sizeof(SinglyList));
    list->head = NULL;
    return list;
}

ListNode *createNode(int value) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = value;
    new->next = NULL;
    return new;
}

/**
 * Node inserting.
 */

void insertNodeAfter(ListNode *node, ListNode *insert) {
    insert->next = node->next;
    node->next = insert;
}

void insertNodeHead(SinglyList *linkedList, ListNode *insert) {
    insert->next = linkedList->head;
    linkedList->head = insert;
}

/**
 * Node removing.
 */

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

/**
 * Other singly linked list related functions.
 */

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

int size(SinglyList *linkedList) {
    int size = 0;
    ListNode *current = linkedList->head;
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
