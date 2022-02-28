#ifndef class_Teacher_h
#define class_Teacher_h

class Teacher {
  const unsigned int identity;                        /* Teacher has an identity */
  static unsigned int teacher_counter;  /* Counts the current number of teachers */
  
  public:
    Teacher();
};

#endif
