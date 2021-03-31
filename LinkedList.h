#ifndef LINKLIST_H  // avoid including header file multipal times 
#define LINKLIST_H



// define a data strecture for a single node of link list 
typedef struct node{
    int size; //  data 
    struct node *pNode; //  pointer to next node 
} node;


// create an empty list 
// return pointer to head of the empty list
//node **create_list();

// display the link list
void print_list(node *head);

// add node at front
void add_node(node **ptr2head,int size);

// remove node
void del_node(node **ptr2head,int size);

// sort data of two nodes
void swap(node* a, node* b);
// sort the list 
// order = 'A'  for accending
// order = 'D'  for decending
void sort(node *head, char order);

// merge two list 
node * merge(node *a, node *b);



#endif // LINKLIST_H 
