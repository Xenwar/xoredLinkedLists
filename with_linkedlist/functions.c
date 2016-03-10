#include "header.h"
void initialize_dbl (Tdbl *dbl){
  *dbl=NULL;
}//end of initializing with NULL
void insert_to_dbl_front (Tdbl *dbl,Titem first){
    Pnode temp;
    temp=(Pnode)malloc(sizeof(Tnode));
    temp->item=first;
    if(*dbl==NULL){
      temp->next=NULL;
      temp->prev=NULL;
      *dbl=temp;
    }//ending case: first element to an empty list
    else{
      temp->prev=NULL;
      temp->next=*dbl;
      (*dbl)->prev=temp;
      *dbl=temp;
    }//end of pre-pending to existing nodes
}//end of inserting from the front
void print_dbl(Tdbl dbl){
  int node_counter = 1;//only debugging purpose.
  Pnode so;
  so=dbl;
  printf("\nForward traversing\n");
  while(so!=NULL){
    printf("|Node: %d \tValue: %d |",node_counter,so->item);
    printf("\n");
    node_counter++;
    so=so->next;
  }//end of traversring.
}//end of printing list forward
void insert_to_dbl_back(Tdbl *dbl,Titem back){
  Pnode temp,so;
  temp=(Pnode)malloc(sizeof(Tnode));
  temp->item=back;
  if(*dbl==NULL){
    temp->next=NULL;
    temp->prev=NULL;
    *dbl=temp;
  }//end of case: empty list
  else{
    so=*dbl;
    while(so->next!=NULL){
      so=so->next;
    }//end of traversing to locate entry point
    so->next=temp;
    temp->prev=so;
    temp->next=NULL;

  }//end of appending.
}//end of adding nodes to the "end" of the list
void print_dbl_reverse(Tdbl dbl){
  Pnode so;
  so=dbl;
  if(dbl!=NULL){
    printf("\nBackward");
    while(so->next!=NULL){
      so=so->next;
    }
  while(so->prev!=NULL){
    printf("%d \t",so->item);
    so=so->prev;
  }
  printf("%d \t",so->item);
  }
}//end of printing list in revers order, move to the end, print backward.
void build_xor_values(Tdbl dbl){
    int node_counter = 1;//only debugging purpose.
    Pnode so;
    Pnode test;
    so=dbl;
    printf("Building XOR values based on previous and current nodes.\n");
    while(so!=NULL){
      so->xor = (void *) ((uintptr_t)so->next ^ (uintptr_t)so);
      printf("Node  %d info\n",node_counter);
      printf("Building|previous : %p |\n",so->prev);
      printf("Building|current  : %p |\n",so);
      printf("Building|Next     : %p |\n",so->next);
      printf("Building|xored    : %p |\n",so->xor);
      so=so->next;
      node_counter++;
    }//end of traversring.
}//end of building new indexes
void verify_xor_values(Tdbl dbl){
  int node_counter = 1;//only debugging purpose.
  Pnode next;
  next = dbl;
  while(next!=NULL){
    printf("Node  %d info\n",node_counter);
    printf("N|current  : %p |\n",next);
    printf("B|xored    : %p |\n",next->xor);

    printf("B|Built in Next  : %p |\n",next->next);
    next = (Pnode *) ((uintptr_t)next->xor ^ (uintptr_t)next);
    printf("C|calculated Next: %p |\n",next);
    node_counter++;
  }//end of traversring.
}//end of traversing using xorevalues.
