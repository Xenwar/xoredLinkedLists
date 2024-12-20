# xoredLinkedLists
The first part solves specific task, searching. 
The second part solves more generic problem, building the next pointer and comparing it with reference values. 
i.e. Searching is a specific problem of calculating pointers. 

As discussed above, the are two versions. 

1. using values in an array.
2. using doubly linked list.

#Objectives.
- With version I, values are searched.
- With version II, Pointers are constructed and compared with reference values.

#Terminating conditions:
- In version I: There is link between the last node and the first node after the head, "loop detection" serves as a terminating
              guarantee.
-In version II: NULL pointer at the end of the list will result in NULL next value.


#Verification:
- In version I, values are searched
- In version II, newly constructed next pointers are compared with pre-build (existing) next pointers.

#common to both:
- Each node in the linked list is visited by calculating its pointer value from the previous node and itself.
- The starting point for both is a single node with NO previous node. 
- In both cases, there is no need of keeping memory of past events. 
