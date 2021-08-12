/**
 * Doubly linked list in C programming language.
 *
 * @Date    12 August, 2021
 * @Author  Hao Ren, <haoren.2906@gmail.com>
 * @GitHub  <https://github.com/flying-yogurt>
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} ListNode;

typedef struct list {
    ListNode *head;
    ListNode *tail;
} DoublyList;

/**
 * Initializing.
 */

DoublyList *createDoublyList() {
    DoublyList *list = (DoublyList *)malloc(sizeof(DoublyList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

ListNode *createNode(int value) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = value;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

/**
 * Node inserting.
 */

void insertNodeAfter(DoublyList *linkedList, ListNode *node, ListNode *new) {
    new->prev = node;
    if (node->next != NULL) {
        new->next = node->next;
        new->next->prev = new;
    } else {
        linkedList->tail = new;
    }
    node->next = new;
}

void insertNodeBefore(DoublyList *linkedList, ListNode *node, ListNode *new) {
    new->next = node;
    if (node->prev != NULL) {
        new->prev = node->prev;
        new->prev->next = new;
    } else {
        linkedList->head = new;
    }
    node->prev = new;
}

void insertNodeHead(DoublyList *linkedList, ListNode *new) {
    if (linkedList->head != NULL) {
        insertNodeBefore(linkedList, linkedList->head, new);
    } else {
        linkedList->head = new;
        linkedList->tail = new;
    }
}

void insertNodeTail(DoublyList *linkedList, ListNode *new) {
    if (linkedList->tail != NULL) {
        insertNodeAfter(linkedList, linkedList->tail, new);
    } else {
        insertNodeHead(linkedList, new);
    }
}

/**
 * Node removing.
 */

void removeNode(DoublyList *linkedList, ListNode *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        linkedList->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        linkedList->tail = node->prev;
    }
    free(node);
    node = NULL;
}

/**
 * It returns the number of element occurs in the linked list.
 * If no corrsponding value found, it returns 0.
 */

int search(DoublyList *linkedList, int value) {
    int isFound = 0;
    ListNode *current = linkedList->head;
    while (current != NULL) {
        if (current->val == value) {
            isFound += 1;
        }
        current = current->next;
    }
    return isFound;
}

int size(DoublyList *linkedList) {
    int size = 0;
    ListNode *current = linkedList->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void printDoublyListForwards(DoublyList *linkedList) {
    if (linkedList->head != NULL) {
        ListNode *current = linkedList->head;
        printf("NULL <-> ");
        while (current != NULL) {
            printf("%d <-> ", current->val);
            if (current->next == NULL) {
                printf("NULL\n");
            }
            current = current->next;
        }
    } else {
        printf("printDoublyListForwards(): DNE ERROR\n");
    }
}

void printDoublyListBackwards(DoublyList *linkedList) {
    if (linkedList->tail != NULL) {
        ListNode *current = linkedList->tail;
        printf("NULL <-> ");
        while (current != NULL) {
            printf("%d <-> ", current->val);
            if (current->prev == NULL) {
                printf("NULL\n");
            }
            current = current->prev;
        }
    } else {
        printf("printDoublyListBackwards(): DNE ERROR\n");
    }
}

void freeList(DoublyList *linkedList) {
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
