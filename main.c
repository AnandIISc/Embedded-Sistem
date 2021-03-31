#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.c"

int main(){

    printf("\n----------LINKED LIST DEMO ---------- \n");
    // create the list 
    node * list1 = NULL;
    node * list2 = NULL;

    int list_size;
    printf("\n----------Input List 1---------- \nenter Size =");
    scanf("%d",&list_size);

    while(list_size--){
        int temp;
        printf("Enter %d more numbers : ",list_size + 1);
        scanf("%d",&temp);
        add_node(&list1,temp);
    }
    

    printf("\n----------Input List 2---------- \nenter Size =");
    scanf("%d",&list_size);

    while(list_size--){
        int temp;
        printf("Enter %d more numbers : ",list_size + 1);
        scanf("%d",&temp);
        add_node(&list2,temp);
    }
    

    printf("list 1 : "); print_list(list1);
    printf("list 2 : "); print_list(list2);

    int m;
    printf("\n----------Merge two list ----------\nPress '1' to merge and '0' to skip :");
    scanf("%d",&m);
    
    if(m){
        list1 = merge(list1,list2);
        printf("merged list is : "); print_list(list1);
    }
    else{
        printf("List is not merged");
    }

    int order;
    printf("\n----------Sort list ----------\n(NOTE: the merged list is stored in list 1 if list is not merged, original list 1 is use !)\n\n");
    printf("Press '0' for accending order \nPress '1' for decending order\n"); 
    scanf("%d",&order);

    if(order){sort(list1,'D');}
    else{sort(list1,'A');}

    printf("\nThe sorted list is : ");print_list(list1);

    printf("\n\n----------Delete node ----------\n");
    int n;
    printf("Enter numbet of node to delete : ");
    scanf("%d",&n);

    while(n--){
        int temp;
        printf("\nYou have %d more nodes to delete  \nEnter number to delete : ",n + 1);
        scanf("%d",&temp);
        del_node(&list1,temp);
        printf("\nNow the list is :");print_list(list1);
    }

    printf("Final list is :"); print_list(list1);


    printf("\n----------THANK YOU ----------\n");

}
