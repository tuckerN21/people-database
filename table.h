#ifndef TABLE_H
#define TABLE_H
//-----------------------------------------------------------
// Purpose: Header file for the Table class.
//          This class is designed to store an array of Person
//          objects that describe a group of famous people.
//          The search methods locate and print information
//          about a specified subset of the famous people.
// Author:  Tucker Neikirk
//-----------------------------------------------------------
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

class Table
{
public:
   // Constructor methods
   Table(); // Constructor
   Table(const Table & t); // Copy constructor
   ~Table(); // Destructor

   // Input and output methods
   void print() const; // Print people in table
   void read(const string& filename); // Open file and add people to table

   // Searching methods
   void searchFirstName(const string& FirstName) const; // Search by first name
   void searchLastName(const string& LastName) const; // Search by last name
   void searchYear(int startYear, int endYear) const; // Search from range of birth years

private:
   // Object attributes
   static const int SIZE = 1000;
   int Count;
   Person table[SIZE];
};
#endif
