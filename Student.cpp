#pragma once
#include<iostream>
using namespace std;
class Student
{
private:
    string name;
    string id;
    double gpa;
public:
    Student();
    Student(string name ,string id,double gpa); // constructor
    Student(const Student& other); // copy constructor
    string getId();
    string getName();
    double getGpa();
    void setGpa(double gpa);
    void setName(string name);
    void setId(string id);
    // bool compareGBA(const Student &s );

    // operator overloading
    bool operator <(const Student &s);
    friend ostream& operator <<(ostream& out, const Student& s);
};


Student::Student() : id{}, name{}, gpa{} {
}

Student::Student(string name , string id ,double gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
}

Student::Student(const Student& other)
{
    id = other.id;
    name = other.name;
    gpa = other.gpa;
}

string Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

double Student::getGpa() {
    return gpa;
}

void Student::setGpa(double gpa) {
    this->gpa = gpa;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setId(string id)
{
    this->id = id;
}


bool Student::operator <(const Student &s ) {
    return name < s.name;
}

ostream& operator <<(ostream& out, const Student& s) {
    out << s.name << "\n" << s.id << "\n" <<  s.gpa << "\n";
    return out;
}


// bool Student::compareGBA(const Student &s)
// {
//     return gpa < s.gpa;
// }
