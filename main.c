#include <stdio.h>
#include "DLL.c"


int main(){
    LinkedList* list = newLinkedList(newNode(3));
    insertNode(list, newNode(2));
    insertNode(list, newNode(1));

    printf("%d", getNode(list, 0)->v);

    return 0;
}