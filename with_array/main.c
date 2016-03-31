#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct Node_t {
  void *x; // This is the xor of the address of the previous node and the next node
  int value;
} Node;
Node * findNode(const Node* head, int v){
  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;
  int x;
  int counter = 0;
  do{ // Check if at end of list
    //printf("\n--------start visits----------------\n");
    if(current->value == v)
        break; // implicit return, current node to be retuned.
    if(current == head){//case 1. entry to list.
        /*
          printf("in root: current = %p\n",current);
          printf("in root: Next    = %p\n",current->x);
          printf("in root: value   = %d\n",current->value);
          */
          current = current->x;
     }//end of handling root.
    else{
          next = (Node *) ((uintptr_t)current->x ^ (uintptr_t)current);
          /*
          printf("In Non-head\n");
          printf("prev    = %p\n",prev);
          printf("current = %p\n",current);
          printf("current.x = %p\n",current->x);
          printf("Next    = %p\n",next);
          printf("Value   = %d\n",current->value);
          */
          current = next;
    }//end of cases other than case 1

  }while( current->x != head->x);//terminating guarantee,Circular
  return current;
}//end of findNode function

int main() {
  int test_size = 5;
  Node *result;
  Node nodes[test_size];
  Node *head;
  head = &nodes[0];
  //Link up the nodes
  head->x = (void*)&nodes[1]; //randmly chosen entry point.
  nodes[1].x = (void *)((uintptr_t)head->x  ^ (uintptr_t)&nodes[2]);
  nodes[2].x = (void*)((uintptr_t)&nodes[2] ^ (uintptr_t)&nodes[3]);
  nodes[3].x = (void*)((uintptr_t)&nodes[3] ^ (uintptr_t)&nodes[4]);
  nodes[4].x = &nodes[1];
  /*
  *   View counter, addresses and xored values.
  */
  for(int i=0;i < (sizeof(nodes) / sizeof(nodes[0]));i++){
     printf("\n@%d This = %p | this.x = %p\n",i,&nodes[i],nodes[i].x);
  }//
  // Give them values
  for(int i=0;i < (sizeof(nodes) / sizeof(nodes[0]));i++){
   nodes[i].value = i;
   //i chosen on purpose for validation.
   //possible to add random numbers.
}//end of adding values.
  
  //Even indexes, values not to be found.
  //Odd indexes, values to be found.
  int lookup[] = {10,1,20,3,40};
  int thisValue = -1;
  for(int i =0; i < 5;i++){
    result = findNode(head, lookup[i]);
    thisValue = result->value;
    if(i%2 ==0){//for those that should not exist.
      if(thisValue == lookup[i])
         printf("Wrong positive.\n");
      else
         printf("passed\n");
    }
    else{//odd indices, values exist
      if(thisValue == lookup[i])
         printf("passed.\n");
      else
         printf("Value %d Not found\n",thisValue);
    }
  }//end of Testing
  return 0;
}//end of main method
