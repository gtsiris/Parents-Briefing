#include <iostream>
#include <cstdlib>
#include "class_Parent_List.h"

using namespace std;

Parent_List::Parent_List_Node::Parent_List_Node(Parent& parent) : p(parent), next_parent(NULL)  /* Each node is initially separate */
{}

Parent_List::Parent_List() : head(NULL)                                                             /* The list is initially empty */
{}

Parent_List::~Parent_List() {
  Parent_List_Node* temp0 = head;                                                                  /* Starting from the first node */
  while(temp0 != NULL) {                                                                       /* Repeat until the end of the list */
    Parent_List_Node* temp1 = temp0;                                                       /* Save the address of the current node */
    temp0 = temp1->next_parent;                                                                             /* Go to the next node */
    delete temp1;                                                                       /* Delete the content of the saved address */
  }
}

const bool Parent_List::Is_Empty() const {
  return (head == NULL);                                                   /* If there is no parent in this list, then it is empty */
}

void Parent_List::Enter(Parent& parent) {
  if (this->Is_Empty()) {                                                                    /* If there is no parent in this list */
    head = new Parent_List_Node(parent);                                             /* Create a new node at the start of the list */
  }
  else {
    Parent_List_Node* temp = head;                                                                 /* Starting from the first node */
    while(temp->next_parent != NULL)                                              /* Repeat unless it is the last node of the list */
      temp = temp->next_parent;                                                                                 /* Go to next node */
    temp->next_parent = new Parent_List_Node(parent);                                     /* Create a new node after the last node */
  }
}

Parent& Parent_List::Exit() {
  Parent& parent(head->p);                                           /* Keep a reference to the first parent in order to return it */
  Parent_List_Node* temp = head->next_parent;                                               /* Save the address of the second node */
  delete head;                                                                                            /* Delete the first node */
  head = temp;                                                             /* Update the start of the list using the saved address */
  return parent;                                                                                        /* Return the first parent */
}
    
void Parent_List::Return(Parent& parent) {
  const bool appropriate_return = rand() % 2;           /* Choose randomly if the parent returns to the queue appropriately or not */
  if (!appropriate_return)                                                              /* If he attempts to go first in the queue */
    cout << "You should go to the end of the line! " << parent.Get_Identity() << endl;
                                                          /* The rest of the parents complain and send him to the end of the queue */
  else
    cout << "Well done! " << parent.Get_Identity() << endl;                                     /* The rest of the parents approve */
  this->Enter(parent);                                                       /* Either way parents returns to the end of the queue */
}

const bool Parent_List::More_Parents_For_ith_Teacher(const unsigned int& i) {
  Parent_List_Node* temp = head;                                                                   /* Starting from the first node */
  while (temp != NULL) {                                                                       /* Repeat until the end of the list */
    if (temp->p.Get_Status_About_ith_Teacher(i))                             /* If this parent needs to get briefed by ith teacher */
      return 1;                                                     /* Then atleast one parent needs to get briefed by ith teacher */
    temp = temp->next_parent;                                                                               /* Go to the next node */
  }
  return 0;                                               /* No parent found in this list that needs to get briefed by ith teacher */
}

Parent& Parent_List::Exit_Parent_For_ith_Teacher(const unsigned int& i) {
  if (head->p.Get_Status_About_ith_Teacher(i)) {       /* If the parent of the first node needs to get briefied by the ith teacher */
    Parent& parent(head->p);                                              /* Keep a reference to this parent in order to return it */
    Parent_List_Node* temp = head;                                                           /* Save the address of the first node */
    head = head->next_parent;                                                                      /* Update the start of the list */
    delete temp;                                                                  /* Delete the first node using the saved address */
    return parent;                                                                                                /* Return parent */
  }
  Parent_List_Node* temp0 = head;                                                            /* Else, starting from the first node */
  while (!temp0->next_parent->p.Get_Status_About_ith_Teacher(i)) {       /* Find a parent that needs to get briefed by ith teacher */
    temp0 = temp0->next_parent;                                                                             /* Go to the next node */
  }
  Parent_List_Node* temp1 = temp0->next_parent;                                                         /* Save this node's address*/
  temp0->next_parent = temp0->next_parent->next_parent;                                   /* Skip this node using its previous one */
  Parent& parent(temp1->p);                                               /* Keep a reference to this parent in order to return it */
  delete temp1;                                                                                                /* Delete this node */
  return parent;                                                                                             /* Return this parent */
}