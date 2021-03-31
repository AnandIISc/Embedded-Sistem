#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


// create empty linked list
//node **create_list(){
//    node *head = NULL;
//    return &head;
//
//}

// display the link list
void print_list(node *head){
    
    if(head == NULL){printf("Empty list !"); return;}
    //traverse list until head points to NULL 
    while(head!= NULL){
        printf(" %d ", head->size);
        head = head->pNode; 
    }
    printf("\n");
}


// add node at front of the list 
void add_node(node **ptr2head, int size){
    node *temp = (node *) malloc(sizeof(node)); // allocate the sace for new node in memory 
    temp->size = size; // add data to newly created node
    temp->pNode = *ptr2head; // set the pointer of new node to start node of old list
    *ptr2head = temp; // update the head to point to newly created node
}

// remove the node form list with given size 
void del_node(node **ptr2head, int size){

    // check for empty list
    if(*ptr2head == NULL) { printf("\nError:  List is empty !\n"); return;}

    node * current = *ptr2head; // temporary pointer to traverse the list
    node * pre = NULL; // pointer to previous node of current node

    // special case when size is found at first node 
    if (current->size == size){
        *ptr2head = current->pNode;
        free(current);
        return;
    }

    // traverse link list until node with given size is found or list is ended    
    while(current!= NULL){
        if (current->size == size) break;
        pre = current;
        current = current->pNode ;
    }

    // size not found 
    if(current == NULL) { printf("\n Error: no node found with given size !\n"); return;}

    //delete node pointed by current
    pre->pNode = current->pNode; // drop the current node from link
    free(current); // free the space hold by deleted node 

}


// sort data of linked list

//  helping dunction to swap the data of two node 
void swap(node * a, node *b){
    int temp = a->size;
    a->size = b->size;
    b->size = temp;
}

//  the sort function 
// order = 'A'  ---> Accending 
// order = 'D'  ---> Decending order 

void sort(node *head, char order){

    int swap_flag,i;
    node *ptr1;
    node *lptr = NULL;

    if(head == NULL) {printf("Empty list !"); return;}

    do{
        swap_flag = 0;
        ptr1 = head ;

        while(ptr1->pNode != lptr){

            if (order == 'A'){
                // assending order swap 
                if(ptr1->size > ptr1->pNode->size){
                    swap(ptr1,ptr1->pNode);
                    swap_flag = 1;
                }
            }
            else if (order = 'D'){
                // decending order swap
                if(ptr1->size < ptr1->pNode->size){
                    swap(ptr1,ptr1->pNode);
                    swap_flag = 1;
                }
            }
            else{
                printf("\nWrong order input!\n input 'A' for accending order \n input 'D' for decending order \n");
                return;
            }

            //increment the ptr1 to next node 
            ptr1 = ptr1->pNode;
        }

        lptr = ptr1;
    }
    // swap_flag = 0 indicate list is sorted
    while (swap_flag);
    
}


// merge two list 
// append seond list to dirt list 
// return the head of resultant list
node * merge(node *a, node *b) {

    if(a == NULL) return b; // first list is empty 
    if(b == NULL) return a; // second list is empty 

    node *temp = a;
    // treverse to the last node of the list 'a'
    while(temp->pNode != NULL){
        temp = temp->pNode;
    }
    temp->pNode = b;
    return a;

}
