#include "class_Teacher.h"

unsigned int Teacher::teacher_counter = 0;

Teacher::Teacher() : identity(++teacher_counter)  /* Increase the number of teachers and set it as current teacher's identity */
{}