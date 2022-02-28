#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class_Parent.h"
#include "class_Parent_List.h"
#include "class_Teacher.h"

using namespace std;

int main(void) {
  unsigned int N, K, L, parent_counter;
  cout << "Insert the number of teachers: ";
 cin >> N;                                                                        /* Get the total number of teachers from standard input */
 Parent::Set_Total_Teachers(N);                            /* Update the number of teachers that parent has the option to get briefied by */
 cout << endl << "Insert the number of parents: ";
 cin >> K;                                                                         /* Get the total number of parents from standard input */
 cout << endl;
 srand(time(NULL));                                                                        /* Initialize the seed using the function time */
 Parent parents[K];                                                        /* Create K parents with random identities and briefing status */
 Parent_List queue;                                                                     /* Parents enter this queue and wait for briefing */
 L = rand() % K + 1;                                                                                 /* Choose a random number of parents */
 for (parent_counter = 1; parent_counter <= L; parent_counter++)
    queue.Enter(parents[parent_counter - 1]);                                                               /* Add these parents to queue */
  Teacher teachers[N];                                                                     /* Create N teachers with 1 to N as identities */
  Parent_List briefing;                                                    /* Parents enter this queue after getting briefed by a teacher */
  while(!queue.Is_Empty()) {                                                            /* Repeat until there are no more parents waiting */
    for (unsigned int teacher_counter = 1; teacher_counter <= N; teacher_counter++) {                                 /* For each teacher */
      if (queue.More_Parents_For_ith_Teacher(teacher_counter)) {        /* Check if there are any parents that need to get briefed by him */
        Parent& parent_with_priority = queue.Exit_Parent_For_ith_Teacher(teacher_counter);  /* The first of these parents exits the queue */
        if (L < K) {                                                        /* If there are more parents that haven't enter the queue yet */
          L += rand() % (K - L) + 1;                                                                    /* Choose a random number of them */
          for (; parent_counter <= L; parent_counter++)
            queue.Enter(parents[parent_counter - 1]);                                                                /* Add them to queue */
        }
        briefing.Enter(parent_with_priority);                                                /* The selected parent is now under briefing */
        parent_with_priority.Briefed_By_ith_Teacher(teacher_counter);                                  /* The teacher briefed this parent */
      }
    }
    while (!briefing.Is_Empty()) {                                               /* Repeat until there are no more parents under briefing */
      Parent& briefed_parent = briefing.Exit();                                                     /* Parent is no longer under briefing */
      if (!briefed_parent.Fully_Briefed())                                  /* If there are more teachers that he needs to get briefed by */
        queue.Return(briefed_parent);                                                                          /* He returns to the queue */
      else                                                                                                              /* Else he leaves */
        cout << "Parent with id " << briefed_parent.Get_Identity() << " is leaving" << endl;
    }
  }
  return 0;
}
