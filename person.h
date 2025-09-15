/******************************************************************************
Author: Tucker Neikirk
Date: August 29, 2025
Purpose: Declare the Person type, which stores five key attributes about a
         notable individual, along with basic accessors and helpers.
*******************************************************************************/

#ifndef PERSON_H
#define PERSON_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
   // Constructor methods
   Person(); // Constructor
   Person(const Person & person); // Copy constructor
   ~Person(); // Destructor

   // Get and Set methods
   string getFirstName() const; // Get person's first name
   string getLastName() const; // Get person's last name
   int getBirthYear() const; // Get person's birth year
   int getDeathYear() const; // Get person's death year
   string getContribution() const; // Get person's contribution
   
   void setFirstName(string FirstName); // Set person's first name
   void setLastName(string LastName); // Set person's last name
   void setBirthYear(int BirthYear); // Set person's birth year
   void setDeathYear(int DeathYear); // Set person's death year
   void setContribution(string Contribution); // Set person's contribution
   
   // Other methods
   void print() const; // Print person's attributes
   void read(ifstream& din); // Read person from file stream

private:
   // Object attributes
   string firstName;
   string lastName;
   int birthYear;
   int deathYear;
   string contribution;
};
#endif
