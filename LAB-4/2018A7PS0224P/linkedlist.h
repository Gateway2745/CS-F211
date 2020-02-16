typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Linkedlist{   // this structure represents the head of the linked list
    int num;
    Node* first;  // contains 'first' which points to first node in the linked list
}List;

List createList(int);
List createCycle(List);
