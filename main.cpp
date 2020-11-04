/*
Linked List project using Faizan Karim's code
*/
#include <iostream>
#include <cstring>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;
// functions
void addStudent(Node* &head, Node* before, Student* student);
void printStudents(Node* next);
void removeStudent(Node* &head, Node* before, Node* next, int num);
void average(Node* next);

int main() {
 // variables
  bool run = true;
  char input[10];
  Node* head = NULL;
  // program start
  while (run == true)
    {
      cout << "What would you like to do?" << endl;
      cout << "add | print | delete | average | quit" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      // add
      if (strcmp(input, "add") == 0)
	{
	  Student *newStud = new Student;
	  cout << "First name?" << endl;
	  cin.get(newStud->getName(), 10);
          cin.clear();
          cin.ignore(10000, '\n');
	  cout << "Last name?" << endl;
	  cin.get(newStud->getSurname(), 10);
          cin.clear();
          cin.ignore(10000, '\n');
	  cout << "ID?" << endl;
	  cin >> *newStud->getID();
          cin.clear();
          cin.ignore(10000, '\n');
	  cout << "GPA?" << endl;
	  cin >> *newStud->getGPA();
          cin.clear();
          cin.ignore(10000, '\n');
	  addStudent(head, head, newStud);
	  cout << "Student has been added" << endl;
	}
      //print
      if (strcmp(input, "print") == 0)
	{
          cout << "Student Linked List Database Printed" << endl;
          cout << "------------------------------------" << endl;
	  printStudents(head);
	}
      //delete
      if (strcmp(input, "delete") == 0)
	{
	  if (head == NULL)
	    {
	      cout << "There are no students to delete." << endl;
	    }
	  else
	    {             
              int id = 0;
              cout << "Which student do you want to delete: Enter their ID" << endl;
              cin >> id;
              cin.clear();
              cin.ignore(10000, '\n');
	      removeStudent(head, head, NULL, id);
	    }
	}
      //average
      if (strcmp(input, "average") == 0)
	{
	  average(head);
	}
      //quit
      if (strcmp(input, "quit") == 0)
	{
	  run = false;
	}
    }
  
  return 0;
}

// uses iteration to go through each node, and get the student's gpa. Adds the GPA to a float that is the sum of all students, and divides it by another float that was used to keep track of the number of nodes there were.
void average(Node* next)
{
  float all = 0;
  float num = 1;
  all += *next->getStudent()->getGPA();
  while (next->getNext() != NULL)
    {
      all += *next->getNext()->getStudent()->getGPA();
      num++;
      next = next->getNext();
    }
  cout << "The Average GPA for all students is: " << fixed << setprecision(2) << (all/num) << endl;
}

// uses recursion to go through each node, checking if the ID entered is equal to any of the ID in the linked list. If it is, the node will be deleted, along with all of it's data.
void removeStudent(Node* &head, Node* next, Node* before, int num)
{
  char yn;
  // checks the first node.
  if (next == head && num == *next->getStudent()->getID())
    {
      cout << "Are you aure you want to delete this student. 'y' or 'n'" << endl;
      cin >> yn;
      cin.clear();
      cin.ignore(10000, '\n');
      if (yn == 'y')
        {
          cout << "student is now deleted" << endl;
          if (next->getNext() == NULL) 
            {
	      //next->~Node();
	      head = NULL;
            }
          else 
            {
	      head = next->getNext();
	      next->~Node();
	      removeStudent(head, head, NULL, num);
            }
        }
      else if (yn == 'n')
        {
          cout << "Student not deleted." << endl;
          if (next->getNext() != NULL)
            {
	       removeStudent(head, next->getNext(), next, num);
            }
        }
    }
  // checks the rest of the nodes
  else if (num == *next->getStudent()->getID()) 
    {
      cout << next->getStudent()->getName() << " " << next->getStudent()->getSurname() << " " << next->getStudent()->getID() << " " << next->getStudent()->getGPA() << endl << endl;
      cout << "Are you aure you want to delete this student. 'y' or 'n'" << endl;
      cin >> yn;
      cin.clear();
      cin.ignore(10000, '\n');
    if (yn == 'y') {
      cout << "student is now deleted" << endl;
      before->setNext(next->getNext());
      next->~Node();
    }
    else if (yn == 'n') {
      cout << "Student not deleted." << endl;
    }
  }
  if (next->getNext() != NULL) {
    removeStudent(head, next->getNext(), next, num);
  }
}

//will add the new node onto the linked list. Checks the id of the new student, and add thems into the linked linked in the order to low -> high numbered IDs. Uses recursion to go through the entire linked list. 
void addStudent(Node* &head, Node* before, Student* student)
{
  if (head == NULL)
    {
      head = new Node(student);
    }
  else if (*student->getID() < *head->getStudent()->getID())
    {
      Node* blank = new Node(head->getStudent());
      blank->setNext(head->getNext());
      head->setStudent(student);
      head->setNext(blank);
    }
  else if (before->getNext() == NULL)
    {
      Node* blank = new Node(student);
      before->setNext(blank);
    }
  else if (*student->getID() < *before->getNext()->getStudent()->getID())
    {
      Node* blank = new Node(student);
      blank->setNext(before->getNext());
      before->setNext(blank);
    }
  else
    {
      addStudent(head, before->getNext(), student);
    }
}
//uses recursion to go through each of the nodes in the linked list, and outputting all of the data from within.
void printStudents(Node* next)
{
  if (next != NULL)
    {
      cout << next->getStudent()->getName() << " " << next->getStudent()->getSurname() << ", ID:" << *next->getStudent()->getID() << ", GPA:" << fixed << setprecision(2) << *next->getStudent()->getGPA() << endl << endl;
      printStudents(next->getNext());
    }
}
