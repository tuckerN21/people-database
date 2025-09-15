/******************************************************************************
Author: Tucker Neikirk
Date: August 29, 2025
Purpose: Declare the Table type, a container for Person records that supports
         loading from file, printing the full set, and field-based searches.
*******************************************************************************/

#ifndef TABLE_H
#define TABLE_H
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
