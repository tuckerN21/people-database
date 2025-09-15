#include "table.h"

using namespace std;

// Constructor methods
Table::Table() { // Constructor
    Count = 0;
}

Table::Table(const Table & t) { // Copy constructor
    Count = t.Count;
    for (int i = 0; i < SIZE; i++) { // For loop to iterate through table and copy its data
        table[i] = t.table[i];
    }
}

Table::~Table() { // Destructor
}

// Input/output methods
void Table::print() const { // Print people in table
    for (int i = 0; i < Count; i++) { // For loop to iterate through table and print all people
        // If statements for proper formatting when printing people
        if (i + 1 < 10) {
            cout << i + 1 << ". ";
        }
        else if (i + 1 >= 10) {
            cout << i + 1 << ".";
        }
        table[i].print();
        cout << endl;
    }
}

void Table::read(const string& filename) { // Open file and add people to table
   ifstream din(filename); // Open file

   if (din.fail()) { // If the file fails to open
      cout << "Error opening file " << filename << endl;
      return;
   }

   Count = 0;
   while (Count < SIZE && !din.eof()) { // While loop to iterate through all text in the file
      table[Count].read(din); // Read person from text using the person class read function
      if (din.fail()) { // If reading from the file fails
          break;
      }
      Count++;
   }

   din.close();
}


// Searching methods
void Table::searchFirstName(const string& FirstName) const { // Search by first name
    int num = 1;
    bool found = false;

    for (int i = 0; i < Count; i++) { // For loop to iterate through table array
        if (table[i].getFirstName() == FirstName) { // If person's first name equals the first name from input
            // Print person and set found boolean to true
            if (num < 10) { // If statements for proper formatting when printing people
                cout << num << ". ";
            }
            else if (num >= 10) {
                cout << num << ".";
            }
            table[i].print();
            cout << endl;
            num++;
            found = true;
        }
    }

    if (!found) { // If no one with that first name is found
        cout << "No people found with first name " << FirstName << "." << endl;
    }
}

void Table::searchLastName(const string& LastName) const { // Search by last name
    int num = 1;
    bool found = false;

    for (int i = 0; i < Count; i++) { // For loop to iterate through table array
        if (table[i].getLastName() == LastName) { // If person's last name equals the last name from input
            // Print person and set found boolean to true
            if (num < 10) { // If statements for proper formatting when printing people
                cout << num << ". ";
            }
            else if (num >= 10) {
                cout << num << ".";
            }
            table[i].print();
            cout << endl;
            num++;
            found = true;
        }
    }

    if (!found) { // If no one with that last name is found
        cout << "No people found with last name " << LastName << endl;
    }
}

void Table::searchYear(int startYear, int endYear) const { // Search from range of birth years
    int num = 1;
    bool found = false;

    for (int i = 0; i < Count; i++) { // For loop to iterate through table array
        if (table[i].getBirthYear() >= startYear && table[i].getBirthYear() <= endYear) { // If person's birth year is in the range of birth years
            // Print person and set found boolean to true
            if (num < 10) { // If statements for proper formatting when printing people
                cout << num << ". ";
            }
            else if (num >= 10) {
                cout << num << ".";
            }
            table[i].print();
            cout << endl;
            num++;
            found = true;
        }
    }

    if (!found) { // If no one born between those years is found
        cout << "No people found born between " << startYear << " and " << endYear << "." << endl;
    }
}
