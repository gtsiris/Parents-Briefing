#ifndef class_Parent_List_h
#define class_Parent_List_h

#include "class_Parent.h"

class Parent_List {
  struct Parent_List_Node {
    Parent& p;                                                                                                          /* Reference to the parent */
    Parent_List_Node* next_parent;                                                               /* Points the next node in the list, if it exists */
    
    Parent_List_Node(Parent& parent);
  };
  
  Parent_List_Node* head;                                                                     /* Points the node of the first parent, if it exists */
  
  public:
    Parent_List();
    
    ~Parent_List();                                                               /* List is not necessary anymore, so release its node one by one */
    
    const bool Is_Empty() const;                                                                          /* Determine if the list is empty or not */
    
    void Enter(Parent& parent);                                                                                     /* This parent enters the list */
    
    Parent& Exit();                                                                                             /* The first parent exits the list */
    
    void Return(Parent& parent);                                                                                /* This parent returns to the list */
    
    const bool More_Parents_For_ith_Teacher(const unsigned int& i);  /* Determine if there are any parents that need to get briefed by ith teacher */
    
    Parent& Exit_Parent_For_ith_Teacher(const unsigned int& i);                  /* Exit the first parent that needs to get briefed by ith teacher */
};

#endif