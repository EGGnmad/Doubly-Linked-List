#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

struct node* newNode(int value){
    
    struct node *nowNode = malloc(sizeof(struct node*));

    nowNode->v = value;
    nowNode->next = NULL;
    nowNode->previous = NULL;

    return nowNode;
}

LinkedList* newLinkedList(struct node* head){

    LinkedList* list = malloc(sizeof(LinkedList*));

    list->head = head;
    list->tail = head;
    list->size = 1;

    return list;
}

// O(1)
void insertNode(LinkedList *list, struct node* node){
    node->next = list->head;
    list->head = node;
    list->head->next->previous = node;

    // resize
    list->size++;
}

// O(1)
void removeNode(LinkedList *list){

    list->head = list->head->next;
    list->head->previous = NULL;

    // resize
    list->size--;
}

// O(n/2)
struct node* getNode(LinkedList *list, int index){

    int start = ((list->size -1)/2 > index) ? 0 : list->size -1;
    struct node* cnode = (!start) ? list->head : list->tail;
    
    if(!start){
        for(int i = start; i < index; i++)
            cnode = cnode->next;
        return cnode;
    }

    else{
        for(int i = start; i > index; i--)
            cnode = cnode->previous;
        return cnode;
    }
}

// O(n)
int containsNode(LinkedList *list, struct node* node){
    struct node* cnode = list->head;
    for(int i = 0; i < list->size -1; i++){
        if(cnode->v == node->v)
            return 1;
        cnode = cnode->next;
        if(cnode->v == node->v)
            return 1;
    }
    return 0;
}

