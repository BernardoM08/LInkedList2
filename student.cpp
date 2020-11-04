#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//constuctors
Student::Student()
{

}

Student::~Student()
{
  delete &name;
  delete &surname;
  delete &id;
  delete &gpa;
}

//getters
char* Student::getName()
{
  return name;
}

char* Student::getSurname()
{
  return surname;
}

int* Student::getID()
{
  return &id;
}

float* Student::getGPA()
{
  return &gpa;
}
