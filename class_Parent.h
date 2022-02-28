#ifndef class_Parent_h
#define class_Parent_h

class Parent {
  const unsigned int identity;                                                                              /* Parent has an identity */
  bool* status;                                                /* Briefing status shows by which teachers parent needs to get briefed */
  static unsigned int total_teachers;                    /* The total number of teachers that parent has the option to get briefed by */
  
  public:
    Parent();
    
    ~Parent();
    
    static void Set_Total_Teachers(const unsigned int& number_of_teachers);
                                                          /* Set the number of teachers that parent has the option to get briefied by */
    const unsigned int Get_Identity() const;                                                            /* Find the parent's identity */
    
    const bool Get_Status_About_ith_Teacher(const unsigned int& i) const;  /* Find if the parent needs to get briefed by ith teacher  */
    
    void Briefed_By_ith_Teacher(const unsigned int& i);                                         /* The ith teacher briefed the parent */
    
    const bool Fully_Briefed() const;                                              /* Determine if the parent is fully briefed or not */
};

#endif