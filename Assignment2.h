#ifndef LINKLIST_H   
#define LINKLIST_H




typedef struct node{
    int size; 							//  data 
    struct node *pNode; 			//  pointer to next node 
} Node; 



typedef struct listOfList{
	int indexNum ;								//Superlist node which will store the information of header of lists
	Node* headPtr;										
	struct listOfList *next ;
}SuperList;


//it will create superlist NOde in O(1) with taking as parametre as 
SuperList* createSuperListNode (int index);      

Node* createListNode(int data); //to create list node O(1)

void printList(SuperList * headRef);   //it will display all element present in Supernode list List

								// ****************adding node at front of list in a given list -- O(1)---Operation*******************//
 
void addNode(SuperList *head, int size, int index);   		// to call this we need to pass SuperList address pointers


// ******************delete Node from Given list *************
// *************** we serach in all list before delete the linked list  ***************//
// *************** Operation will be done in O(total Number of node) ***************///

void delNode(SuperList *head, int size, int index);






void removeList (SuperList *head );                  // this function will remove list from SuperList but leave Super Node as it is




/*****************************************it will delete superList Node which doesnot have headpointer*****************/

void deleteSuperNode (SuperList **headRef);

/*************************************it will take O(n1 + N2) where n1 = size of first list, n2 = size of second list***************/ 
 
Node* mergeAtEnd (SuperList *a, SuperList *b);

//Implementation of Selection Sort Time Complexity - O(N^2)
// number is node swapping is zero only changng node data 
void sortAD(Node* head, int c);

#endif

