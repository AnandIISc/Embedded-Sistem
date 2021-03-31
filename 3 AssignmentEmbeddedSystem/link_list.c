#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"


int main(argc,argv[])
{
  /* Display the options
   * get user choice
   * Then act on user choice
   * Come back to menu
   * If Exit option is chosen the terminate
   */
   
   for {;;}
   { 
      get_input() ;
      process_input();
      display_status();
      };
   
return 0 ;

}


int add_node(Node *List_head, Value)
{
	/* Add the given node to the list provided */

return 0 ;	
}

int del_node(Node *list_head, int Value)
{
	/* Visit each node and search for the value */
	/* if matching node 
	 * Value == Node->next->value
	 * is found the Node->Next and Node->Next->Next  will 
	 * get manipulated 
	 * tmp = Node->Next  ; Node->Next = tmp -> next 
	 * and deallocated the memory assigned tmp node */
	return 0;
}



int get_input (void)
{
	/* Display the menu options and get user choice */
    int Value = 0 ;	
	
	/* display options */
	// display_options();
	
	/* scanf to read user choice */
	value = read_input();
	// sanity_check() ;
	

 return value ;
	
}

int print_list (Node *)
{
	/* prints the list of nodes that user has selected */
	
	return 0;
}
