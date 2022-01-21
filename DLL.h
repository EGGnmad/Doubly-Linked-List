struct node{
    int v;
    struct node *next;
    struct node *previous;
};

struct node* newNode(int value);

typedef struct {
    struct node *head;
    struct node *tail;

    int size;
} LinkedList;

LinkedList* newLinkedList(struct node* head);
void insertNode(LinkedList *list, struct node* node);
void removeNode(LinkedList *list);
struct node* getNode(LinkedList *list, int index);
int containsNode(LinkedList *list, struct node* node);
