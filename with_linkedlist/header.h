#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int Titem;
typedef struct node *Pnode;
typedef struct node {
  Titem item;
  Pnode next,prev;
  void* xor;
} Tnode;
typedef Pnode Tdbl;
void initialize_dbl(Tdbl *dbl);
void insert_to_dbl_front (Tdbl *dbl,Titem first);
void print_dbl(Tdbl dbl);
void print_dbl_reverse(Tdbl dbl);
void insert_to_dbl_back(Tdbl *dbl,Titem back);
