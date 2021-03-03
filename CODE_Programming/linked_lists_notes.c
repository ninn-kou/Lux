// Hao Ren
// z5237203@student.edu.au
// November 19, 2019
// It is a functions file for better understanding of linked list.
// Linked List of Names (Maybe use it in "Contacts:)".

// Version 1.0  Notes created. Need to finish the REVERSE & SORTING functions.
//              FINDING_NODE and FINDING_PREV functions could be helpful.
//              In addition, we could also add more data types and test it.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 50

// Declare a linked list which contain two parts:
// the variable (value) and the pointer (address)
// to next node.
struct node {
    // If we want, we could also put other types of
    // variables here, eg: int, double...
    // (Maybe it is the telephone number?)
    char name[MAX_LENGTH];
    struct node *next;
};

// Functions:
struct node *createNode(char newName[], struct node *newNext);
struct node *insertNode(char newName[], struct node *listNode);
struct node *insertAlphabetically(char newName[], struct node *head);
struct node *removeNode(char name[], struct node *head);
void printList(struct node *listNode);
void freeList(struct node *n);

// Main function.
int main(void) {
    printf("Some foundational linked lists functions, including:\n");
    printf("createNode\ninsertNode\ninsertAlphabetically\n"); 
    printf("removeNode\nprintList\nfreeList\n");
    printf("\n");
    printf("Comments in linked_lists_nodes.c\n");
    printf("More applicable program by Marc:\n");
    printf("Battle Royale\n");
    printf("COMP1511/Lectures/Week_8/battle-4.c\n");  
    return 0;
}

// Create a node using the name and next pointer provided.
// Return a pointer to this node.
// In fist row, "*newNode is an address to link the list.
// If this is the first element in the linked list, input "NULL"
// to create this node as the end of linked list.
struct node *createNode(char newName[], struct node *newNext) {
    // If it should be freed? If yes, when?
    struct node *new = malloc(sizeof(struct node));
    // Check if there is enough space in memory.
    // If not, execute the "else" part.
    if (new != NULL) {
        // Copy the string into node.
        strcpy(new->name, newName);
        // Give the address of this new node to connect into
        // the linked list.
        new->next = newNext;
    } else {
        printf("Memory lack.\n");
        exit(1);
    }
    return new;
}

// Create a new node by the above function (createNode), then,
// insert this new node into the list after a given node.
struct node *insertNode(char newName[], struct node *listNode) {
    struct node *n = createNode(newName, NULL);
    // Check if the list is empty, if yes, exit.
    if (listNode == NULL) {
        printf("Empty linked list.\n");
        exit(1);
    } else {
        // Link the inserted node to next one
        //
        //     PREV_NODE            INSERT             NEXT_NODE
        //     listNode               n
        //     --------            --------            --------
        //     |      |            |      |            |      |
        //     |------|    |>>>>>>>|------|    |>>>>>>>|------|
        //     | next>|>>>>|       | next>|>>>>|       |      |
        //     |   |  |            |      |            |      |
        //     --------            --------            --------
        //         |                                       ^
        //         |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
        //
        n->next = listNode->next;
        listNode->next = n;
    }
    return listNode;
}
// Create & insert a new node by the function "insertNode" which
// contains the function "createNode".
// However, this function could find the right place to insert
// a node alphabetically.
struct node *insertAlphabetically(char newName[], struct node *head) {
    // Declare a null pointer.
    struct node *previous = NULL;
    // Start from beginning.
    struct node *n = head;
    // To make sure n is not a empty pointer.
    // Then find right place by the function "strcmp(str1, str2)",
    // which could return negative if str1 < str2;
    //                    positive if str1 > str1;
    //                    0 if they are equal.
    // Using while to skip nodes until return a "<".
    // ASCII Table: ... < A < B < ... < Z < a < b < ... < z < ...
    while (n != NULL && strcmp(newName, n->name) > 0) {
        previous = n;
        n = n->next;
    }
    // Now we find the right location so we insert the node.
    struct node *insertPoint = insertNode(newName, previous);
    // This part is used to return a pointer by the condition.
    // If "previous == NULL", it means we insert the node at
    // beginning of linked list, so we return it because it is
    // the first element.
    // Otherwise, it is not the 1st element so we return "head"
    // as the first element.
    if (previous == NULL) {
        insertPoint->next = n;
        return insertPoint;
    } else {
        return head;
    }
}

// Remove a node from a linked lists. We need 5 steps:
//     1. Loop until we find the right match;
//     2. Check if it equals to NUll, if not, we found the right match;
//     3. Check if this node is the 1st node in linked lists;
//     4. Modify the pointer; (Graph Below)
        //         PREV_NODE            REMOVE             NEXT_NODE
        //         previous               n
        //         --------            --------            --------
        //         |      |            |      | Head>>>>>>>|      |
        // Head>>>>|------|    |>>>>>>>|------|  (1st node)|------|
        //(not 1st)| next>|>>>>|       | next>|>>>>|       |      |
        //         |   |  |            |      |    |>>>>>>>|      |
        //         --------            --------            --------
        //             |                                       ^
        //             |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
//     5. Free the node we do not need anymore.
struct node *removeNode(char name[], struct node *head) {
    struct node *previous = NULL;
    struct node *n = head;
    // Step 1.
    while (n != NULL && strcmp(name, n->name) != 0) {
        previous = n;
        n = n->next;
    }
    // Step 2.
    if (n != NULL) {
        // Step 3 & 4.
        if (previous == NULL) {
            head = n->next;
        } else {
            previous = n->next;
        }
        // ***Step 5!*** (IMPORTANT!)
        free(n);
    }
    return head;
}

// Loop through the list and print out all names.
void printList(struct node *listNode) {
    // Find every node until the last one (NULL).
    while (listNode != NULL) {
        printf("%s\n", listNode->name);
        listNode = listNode->next;
    }
}

// All memory allocated (malloc) needs to be freed.
// "dcc --leak-check" to check if there is any memory leak.
// Free a whole linked list.
void freeList(struct node *head) {
    struct node *n = head;
    // Loop through a list and free all the allocated memory.
    while (n != NULL) {
        // Copy the pointer which points at head.
        // We use it as the start and then we could free nodes one
        // by one.
        struct node *remNode = n;
        // Move the looping pointer (remNode) to the next node.
        n = n->next;
        // Free the current node.
        free(remNode);
    }
}
