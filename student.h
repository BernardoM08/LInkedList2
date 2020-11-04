#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
 public:
  Student();
  ~Student();
  //getters
  char* getName();
  char* getSurname();
  int* getID();
  float* getGPA();
 private:
  //variables 
  char name[10];
  char surname[10];
  int id;
  float gpa;
};
#endif
