#include <cstdlib>
#include "class_Parent.h"

unsigned int Parent::total_teachers = 0;

Parent::Parent() :
identity(rand())                                                                            /* Parent's identity is random */
{
  status = new bool[total_teachers];                            /* Allocate that many bits as the total number of teachers */
  for(unsigned int teacher_number = 1; teacher_number <= total_teachers; teacher_number++)  /* For each availiable teacher */
    status[teacher_number - 1] = rand() % 2;           /* randomly choose if the parent needs to get briefed by him or not */
  status[rand() % total_teachers] = 1;                   /* Secure that parent needs to get briefed by atleast one teacher */
}

Parent::~Parent() {
  delete[] status;                                           /* Release the allocated memory that is not necessary anymore */
}

void Parent::Set_Total_Teachers(const unsigned int& number_of_teachers) {
  total_teachers = number_of_teachers;         /* Set the number of teachers that parent has the option to get briefied by */
}

const unsigned int Parent::Get_Identity() const {
  return identity;                                                                             /* Return parent's identity */
}

const bool Parent::Get_Status_About_ith_Teacher(const unsigned int& i) const {
  return status[i - 1];                                                    /* Return the parent's status about ith teacher */
}

void Parent::Briefed_By_ith_Teacher(const unsigned int& i) {
  status[i - 1] = 0;                                         /* Parent doesn't need to get briefed by this teacher anymore */
}

const bool Parent::Fully_Briefed() const {
  for(unsigned int teacher_number = 1; teacher_number <= total_teachers; teacher_number++)  /* For each availiable teacher */
    if(status[teacher_number - 1])
      return 0;                                     /* If parent needs to get briefed by him, then he is not fully briefed */
  return 1;                                   /* If parent doesn't need to get briefed by anyone, then he is fully briefed */
}