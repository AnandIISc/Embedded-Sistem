#include <stdio.h>
#include <stdlib.h>
#include "Assignment2.h"


int indexCount =1;



				
SuperList *headOfSuperList = NULL;
int numberOfList;

SuperList* createSuperListNode (int index){
	
	SuperList * temp = (SuperList *)malloc(sizeof(SuperList));
	temp ->headPtr = NULL;
	temp ->next =NULL;
	temp ->indexNum = index;
	
	return temp;
}

Node* createListNode(int data){
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->size = data;
	temp->pNode = NULL;
	return temp;
} 



void printList(SuperList * headRef){
	
	if (headRef == NULL)
	return ;
	if (headRef->headPtr == NULL){
		printf ("\nThere is no elemet present in list index: %d", headRef->indexNum);
		printf("\n");
		return;
	}
    Node *head = headRef -> headPtr;
    
    
    
    printf("list no. %d data is :",headRef->indexNum);
    while(head!= NULL){ 
    
        printf("%d", head->size);
        
        head = head->pNode; 
        
        if (head != NULL)
        printf ("-> ");
    }
    printf("\n");
}


// ****************adding node at front of list in a given list -- O(1)---Operation*******************//
 
void addNode(SuperList *head, int size, int index){   		// to call this we need to pass SuperList address pointers
	if (head == NULL){
		
		printf("\nError: there is no list in system\n");
		return;
	}
	SuperList *temp = head;
	
	while (temp != NULL){
		if(temp->indexNum == index)     // it will take O(K) where k is number of list are present
		break;
		
		temp = temp->next;
	}
	
	if (temp == NULL)
	{
		printf("\nError: Given %d number List  index not Found\n",index);
		return;
	}
	
    Node *temp1 = createListNode(size); 		//  it will take O(1) ---- time complexity
	 
     
    
    temp1 -> pNode = temp->headPtr; 
    
    temp->headPtr = temp1; 
}


// ******************delete Node from Given list *************
// *************** we serach in all list before delete the linked list  ***************//
// *************** Operation will be done in O(total Number of node) ***************///

void delNode(SuperList *head, int size, int index){

    // check for empty list
    if(head == NULL) { 
	printf("\nError:  Currently Your SuperList is empty \n"); 
	return;
	}
	
	SuperList *temp = head;
	
	while (temp != NULL){
		if(temp->indexNum == index)     // it will take O(K) where k is number of list are present
		break;
		
		temp = temp->next;
	}
	
	if (temp == NULL)
	{
		printf("\nError: Given %d number List  id not Found\n",index);
		return;
	}
	
	
		Node * current = temp->headPtr; 
    	Node * pre = NULL; 
    
     
    	if (current->size == size){
        	temp->headPtr = current->pNode;
        	free(current);
        	return;
        }
    

        
   	 while(current!= NULL)
        {
        	if (current->size == size)
			{
        		break;
			}
        	pre = current;
        	current = current ->pNode;
		}
		
	if (current == NULL){
		printf ("\nError: Your element Not found in %d list\n",index);
		return;
	}
	pre->pNode = current->pNode;
	printf ("\nSuccess: %d is safely deleted from list\n",size);
	free(current);
	return ;
       
     
}

void removeList (SuperList *head ){                     // this function will remove list from SuperList but leave Super Node as it is
//	SuperList *tail = (head)->next;
	
	if (head == NULL)                                    
	{
		printf("\nError not a valid node\n");
		return;
	}
	
	if ((head)->headPtr == NULL){
		printf("\n************ There is No list**************\n");	
		return;
	}
	Node *current= (head)->headPtr;
	Node *next = NULL;
	
/*	while (current != NULL)
   {
       next = current->pNode;
       free(current);
       current = next;
   }*/
  
   (head)->headPtr = NULL;

//   (head)->next = tail;
   
	printf("\n****************%d number whole list deleted************\n",(head)->indexNum);
	return;
			
}

//   if super is empty remove that Node

void deleteSuperNode (SuperList **headRef){
	
	if (*headRef == NULL)
	return;
	SuperList *head = *headRef;
	SuperList *pre = NULL;
	if (head->headPtr == NULL){
		*headRef = head->next;
		free(head);
	}
	
	while(head!=NULL){
		if(head->headPtr == NULL)
		break;
		pre = head;
		head= head->next;
	}
	if(head == NULL)
	return;
	
	pre->next = head->next;
	free(head);
	headOfSuperList =NULL;
	
}

Node* mergeAtEnd (SuperList *a, SuperList *b) {

    if(a == NULL) return b->headPtr;  
    if(b == NULL) return a->headPtr;  

    Node *temp = a->headPtr;
   
    while(temp->pNode != NULL){
        temp = temp->pNode;
    }
    temp->pNode = b->headPtr;
    
	
    
    return a->headPtr;

}
//Implementation of Selection Sort Time Complexity - O(N^2)
// number is node swapping is zero only changng node data 
void sortAD(Node* head, int c)
{
    Node* temp = head;
  
    if (c == 0)
    {
    	while (temp) {
        	Node* min = temp;
        	Node* r = temp ->pNode;
  
       
        	while (r) {
            	if (min ->size > r->size)
                min = r;
  
         	   r = r->pNode;
       		}
  
        
        int x = temp->size;
        temp->size = min->size;
        min->size = x;
        temp = temp->pNode;
    }
	}
	else if (c == 1){
		while (temp) {
        Node* min = temp;
        Node* r = temp ->pNode;
  
       
        while (r) {
            if (min ->size <= r->size)
                min = r;
  
            r = r->pNode;
        }
  
        
        int x = temp->size;
        temp->size = min->size;
        min->size = x;
        temp = temp->pNode;
    }
	}
}

Node* insertNode(){
	Node* temp =NULL;
	int data ;
	printf ("\nOnly permisiible value is +ve integer on negetive integer list will comlete\n");
	//scanf ("%d",&data);
	while(scanf("%d", &data)==0) //if scanf failed to scan an integer
	{
    	printf("Invalid input. Try again\n");
    	int c;
    	while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
	if (data < 0)
		{
			printf("\n***********--------LIST COMPLETED-----------------******\n");
			return NULL;
		}
		
	temp = createListNode(data);
	temp->pNode = insertNode();
	return temp;	
}

SuperList *createMultipleList(int numOfList){
	if (numOfList == 0 )
	{
		return NULL;
	}
	
	SuperList* head = createSuperListNode(indexCount++);
	head->headPtr = insertNode();
	
	head->next = createMultipleList(numOfList-1);
	
	return head;
}

SuperList* findHeadNode (SuperList* head, int i){
		
		if (head == NULL){
			printf ("Error: there is no List in system");
			return NULL;
		}	
		SuperList *temp = head;
		if (temp->indexNum == i){
			return temp;
		}
		while (temp!=NULL){
			if(temp->indexNum == i){
				return temp;
			}
			temp = temp->next;
		}
		printf ("Error: there is no List of %d index in system",i);
		return NULL;
}

void displayAllList (SuperList* head){
	if (head == NULL){
		printf("Error: there is no list in system");
		
	}
	while (head!=NULL){
		printList(head);
		
		if(head->next!=NULL)
		printf("\n*****************Next List*************************\n");
		
		head = head->next;
	}
}
    




void choice1(){
	printf ("\nplease provide the number of list you would like to have in System: ");						// creating multiple list in system
//    scanf("%d",&numberOfList);
	while(scanf("%d", &numberOfList)==0) //if scanf failed to scan an integer
	{
	    printf("\nInvalid input. Try again please enter integer only\n");
	    int c;
	    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
	headOfSuperList= createMultipleList ( numberOfList);
}

void choice2 (){
	SuperList *head;
        
        int fI, lI, i;
        int index, size;
        int count;
        char order;
        SuperList *a, *b;
	
	 printf("\nEnter index value of both list so that merging will perform\n");
    printf("\nFirst index: ");
    //scanf("%d",&fI);
    while(scanf("%d", &fI)==0) //if scanf failed to scan an integer
	{
	    printf("\nInvalid input. Try again and Please enter integer only\n");
	    int c;
	    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
    printf("\nSecond index: ");
//    scanf("%d",&lI);
	while(scanf("%d", &lI)==0) //if scanf failed to scan an integer
	{
	    printf("\nInvalid input. Try again and Please enter integer only\n");
	    int c;
	    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
    a = findHeadNode(headOfSuperList, fI);
    b = findHeadNode(headOfSuperList, lI);
    if (a != NULL && b !=NULL ){
    
        a->headPtr= mergeAtEnd(a,b);
        printList(a);				// need to write such that delet will happen after merge

            	
	}
	removeList(b);
	return;
}

void choice3(){
	printf("\n*********** Currently all list in system is*****************\n");
    displayAllList(headOfSuperList);
	return;
}

void choice4(){
	int count, index, size, i=1;
	printf("\nEnter number of element you want to delete from list");
//        	scanf("%d",&count);
		while(scanf("%d", &count)==0) //if scanf failed to scan an integer
	{
	    printf("\nInvalid input. Try again and make sure you are entering integer only\n");
	    int c;
	    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
        	
        	while(count){
        		printf("\nEneter the index number of list and size of your %d number data for deletion: \n",i);
//        		scanf ("%d %d",&index, &size);
			
				while(scanf("%d", &index)==0) //if scanf failed to scan an integer
				{
				    printf("\nInvalid input. Try again and Please enter integer only\n");
				    int c;
				    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
				}
				while(scanf("%d", &size)==0) //if scanf failed to scan an integer
				{
				    printf("\nInvalid input. Try again and Please enter integer only\n");
				    int c;
				    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
				}
			
			
        		delNode(headOfSuperList, size, index);                // it will delete datd from perticular list
            	count--;
            	i++;
			}
			
			printf("***************After deletion Nodes from list available sytem of list**********");
            displayAllList(headOfSuperList);
            return;
}
void choice5(){
	int i=1, count;
	printf("\nEnter number of element you want to add in list\n");
//    scanf("%d",&count);
	while(scanf("%d", &count)==0) //if scanf failed to scan an integer
	{
	    printf("\nInvalid input. Try again and Please enter integer only\n");
	    int c;
	    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
        	
        	while(count){
        		int index, size;
        		printf("\nEneter the index number of list and size of your %d number data for addition: \n",i);
        		scanf ("%d %d",&index, &size);
        		addNode(headOfSuperList, size, index);
        		count--;
        		i++;
        	}
        	printf("\n**********After addition your List Look like*************\n");
        	displayAllList(headOfSuperList);
        	return;
}
void choice6(int i, char c){
	char order;
	

			
			  
			//a = findHeadNode(headOfSuperList, index);
			SuperList *temp = headOfSuperList;
			while (temp){
				if(temp->indexNum == i)
				break;
				temp = temp->next;
			}
			if (temp == NULL){
				printf("\n %d index not found in Superlist\n",i);
				return;
			}
		
			sortAD(temp->headPtr,order); 
			printf("\n**********After aSorting your List Look like*************\n");
        	displayAllList(headOfSuperList);
        	return;
}


void choice7(){
	deleteSuperNode(&headOfSuperList);
}

int main ( )
{
	
	
	printf("\n--------------------Wellcome to Demonstration of Linked List ---------------------------\n");
	printf("\n*************NOTE : Each List will be terminated by entering negetive number******************\n");
        
	
	char flag, c;
	int order;
	while(1){
		int choice,i;
		printf("Chose one of the following ! to continue the programm \n");
        printf("Press 1: For creating list \nPossible input is only \"positive\" integer \n");
        printf("Press 2: For merging two list of your choice\n");
        printf("Press 3: For displaying all List in the System  \n");
        printf("Press 4: For deleting Nodes perticular from list \n");
        printf("Press 5: For adding a node with data in list with your choice\n");
        printf("Press 6: For sorting list in ascending or descending order with your choice\n");
        printf("Press 7: For remove every list from avalailabe program\n");
        printf("Press 0: For Exist from main programm\n");
        
		scanf("%d",&choice);
        
        	
        while (choice){
		
        switch (choice)
        {
        case 1:	
        	choice1 ( );
			
            break;
        
        case 2:
            choice2();
            
            break;
        
        case 3:
        	choice3();
        	break;
        
        case 4:
        	choice4();
        	break;
        // For adding node with data in list with your choice 
        case 5 : 
        	choice5();
        	break;
        	
        
      //6: For sorting list in ascending or descending order with your choice  
        case 6:
        	printf ("\nEneter index number of list for sorting");
//        	scanf ("%d", &i);
			while(scanf("%d", &i)==0) //if scanf failed to scan an integer
			{
			    printf("\nInvalid input. Try again and Please enter integer only\n");
			    int c;
			    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
			}
			
        	printf ("\nEnter oredr in which sorting you want 0-ascending and 1-descending order [0/1]:");
        	
        	while(scanf ("%d",&order)!=1)
        	{
        		printf("character is not taken please enter the A/D:::");
        		while(getchar()!='\n');
			}
        	printf("character is taken\n");
        	
        	choice6(i,order); 
			break;
		//7: For remove every list from avalailabe program
		
		case 7:
			choice7();
			
			break;  	
        
            
        }
        printf("Enter Next number for operations");
//        scanf("%d",&choice);

			while(scanf("%d", &choice)==0) //if scanf failed to scan an integer
			{
			    printf("\nInvalid input. Try again and Please enter integer only\n");
			    int c;
			    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
			}



    }
        if (choice == 0)
        break;
  }
    
		
//		printf ("\nIf you want to continue programm again press \"y\" else You can leave by pressing \"n\" [y/n] : ");
//		scanf(" %c ",&flag);
//        if(flag != 'y' || flag !='n'){
//        	printf ("\nError: Invalid output\nExit from promgram");
//        	break;
//		}
    
    
    printf("************Thank You*****************");
    
	
}

