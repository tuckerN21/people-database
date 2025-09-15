#include "person.h"

using namespace std;

// Constructor methods
Person::Person() { // Constructor
    firstName = "";
    lastName = "";
    birthYear = 0;
    deathYear = 0;
    contribution = "";
}

Person::Person(const Person & person) { // Copy constructor
    firstName = person.firstName;
    lastName = person.lastName;
    birthYear = person.birthYear;
    deathYear = person.deathYear;
    contribution = person.contribution;
}

Person::~Person() { // Destructor
}

// Get and set methods
string Person::getFirstName() const { // Get person's first name
    return firstName;
}

string Person::getLastName() const { // Get person's last name
    return lastName;
}

int Person::getBirthYear() const { // Get person's birth year
    return birthYear;
}

int Person::getDeathYear() const { // Get person's death year
    return deathYear;
}

string Person::getContribution() const { // Get person's contribution
    return contribution;
}
   
void Person::setFirstName(string FirstName) { // Set person's first name
    firstName = FirstName;
}

void Person::setLastName(string LastName) { // Set person's last name
    lastName = LastName;
}

void Person::setBirthYear(int BirthYear) { // Set person's birth year
    birthYear = BirthYear;
}

void Person::setDeathYear(int DeathYear) { // Set person's death year
    deathYear = DeathYear;
}

void Person::setContribution(string Contribution) { // Set person's contribution
    contribution = Contribution;
}

// Other methods   
void Person::print() const { // Print person's attributes
    cout << " First Name: " << firstName << endl
         << "    Last Name: " << lastName << endl
         << "    Birth Year: " << birthYear << endl
         << "    Death Year: " << deathYear << endl 
         << "    Contribution: " << contribution << endl << endl;
}

void Person::read(ifstream& din) { // Read person from file stream
    din >> firstName >> lastName >> birthYear >> deathYear;
    getline(din, contribution);
    if (contribution.size() > 0) {
        contribution = contribution.substr(1);
    }
}
