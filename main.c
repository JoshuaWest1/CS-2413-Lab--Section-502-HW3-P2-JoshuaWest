/*
AUTHOR: Joshua Wade West
HW #: HW3 Problem 2
SPECIFICATION: create a doubly linked list that you can modify with a menu 
FOR: CS 2413 Lab- Section 502
*/
#include <stdio.h>
#include <stdlib.h>
 
//struct for the DLinked List
struct Node {
    int Integers;//For Values
    struct Node* next;//To move on
    struct Node* prev;//To move back
};
 
//Prototype function statements
void push();//for push
void Place_At();//for placeinga node into a spot
void Replace_Tail();//to replace the tail
void Print();// to print the array
void Reverse();// to revearse the array
void Delete();// to delete the head of the array


int main()
{
  
    struct Node* head = NULL;// set head to a null value
    struct Node* last = NULL;// set tail to a null value
 int choice = 1, spot, value,add = 0, tempnum;// variable declerations
 //choice for the menu, spot for location in function call, value for new int, add for length of list, tempnum for storage



while(choice != 0){//while loop for menu

//menu list
printf("Enter 1 to Create a list\n");
printf("Enter 2 to insert a new node into the list\n");
printf("Enter 3 to print the list\n");
printf("Enter 4 to Reverse the list\n");
printf("Enter 5 to delete node 1\n");
printf("Enter 0 to end menu\n");
printf("Enter your choice : ");

scanf("%d", &choice);//inspects what option the user wants to select

printf("\n");

switch(choice)//switch for menu options
        {
            case 1:
            //creates a list
                for(int i=0; i<5; i++){
                printf("New node an integer for node #%d : ", i+1);
                scanf("%d", &tempnum);//stores the new value
                push(&head, tempnum);//function calls push
                }
                printf("\n");
                break;
            
            case 2:
            //insert a new node anywhere onto list
            printf("\nWhat position do you want the Node? ");
            scanf("%d", &spot);//asks user for desired location
            printf("\nWhat value is the new Node? ");
            scanf("%d", &value);//asks user for desired value of new node
if(spot > (5+add)){Replace_Tail(&head,value);add++;};//if spot is bigger than list, create new node at end
if(spot == 1){push(&head,value);add++;};//if spot is equal to one, create new node at beggining
if(spot <= 5 && spot != 1){Place_At(head->next, value);add++;};//if spot is between 1 and less than max, place at desired location
                
                break;
            case 3:
                Print(head);//function call to print list
                break;
            case 4:
            Reverse(&head);//function call to reverse list
                break;

            case 5:
            Delete(&head,head );//function call to delete head
                break;
            case 0:
            //ends the menu
                break;
            default:
                printf("Insert new option");
        }


}
    return 0;
}

//Function for Push
void push(struct Node** HeadPTR, int new_Integers)
{
    
    struct Node* Node_plugin = (struct Node*)malloc(sizeof(struct Node));//new node is allocated
 
    
    Node_plugin->Integers = new_Integers;//insert new int value into node
 
    //pulls the old node
    Node_plugin->next = (*HeadPTR);
    Node_plugin->prev = NULL;
 
    //old head is added as new node and inserted next
    if ((*HeadPTR) != NULL){(*HeadPTR)->prev = Node_plugin;}
 
    //place new node as head
    (*HeadPTR) = Node_plugin;

    return;
}
 



//function to place new node at a specific location within the list
void Place_At(struct Node* prev_node, int new_Integers)
{
    
    struct Node* Node_plugin= (struct Node*)malloc(sizeof(struct Node));//new node is allocated
 
    
    Node_plugin->Integers = new_Integers;//insert new int value into node
 
    
    Node_plugin->next = prev_node->next;//move prevous node one over
 
    
    prev_node->next = Node_plugin;//makes the emptied location new node
 
    
    Node_plugin->prev = prev_node;
 
    //insert new node
    if (Node_plugin->next != NULL) {Node_plugin->next->prev = Node_plugin;}

    return;
}
 
/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, Replace_Tails a new node at the end  */
void Replace_Tail(struct Node** HeadPTR, int new_Integers)
{
    
    struct Node* Node_plugin = (struct Node*)malloc(sizeof(struct Node));//new node is allocated
 
    struct Node* last = *HeadPTR;// last becomes a pointer of head
 
    Node_plugin->Integers = new_Integers;//insert new int value into node
 
    
    Node_plugin->next = NULL;//create a Null point next to the new node
 
    while (last->next != NULL)//go through all points till at last
        last = last->next;
 
   
    last->next = Node_plugin;//last is the new node
 
    Node_plugin->prev = last;
 
    return;
}
 
// This function prints contents of linked list starting
// from the given node
void Print(struct Node* node)
{
  printf("\n\n");
    struct Node* last;
    while (node != NULL) {//as long as node in not NULL
        printf(" %d ", node->Integers);//output values in list 
        last = node;
        node = node->next;//moves to next node
    }
      printf("\n\n");

      return;
}
 


void Reverse(struct Node **HeadPTR)
{
     struct Node *temp = NULL;  // temp is set to NUll
     struct Node *current = *HeadPTR; // Current is set to head pointer
      
     
     while (current !=  NULL)//swap each value
     {
       temp = current->prev;

       current->prev = current->next;

       current->next = temp;          

       current = current->prev;
     }
      
     
     if(temp != NULL )*HeadPTR = temp->prev;/*makes sure all is valid*/

     return;
}   


void Delete(struct Node** HeadPTR, struct Node* del)
{
        
        *HeadPTR = del->next;//deletes the head

    free(del);//frees up memory

    return;
}

