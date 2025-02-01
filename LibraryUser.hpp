#pragma once
#ifndef LIBRARYUSER_HPP
#define LIBRARYUSER_HPP

#include <string>
#include <vector>

class Library; //forward declaration for Library
class Book;    //forward declaration for Book

using namespace std;

class LibraryUser {
protected:
    string name;               //user name
    string user_id;            //user ID
    int borrowed_count;        //number of books borrowed
    int borrow_limit;          //borrow limit

public:
    //default constructor
    LibraryUser();

    //parameterized constructors
    LibraryUser(const string& name, const string& user_id, int borrow_limit);

    //getters
    string get_name() const;
    string get_user_id() const;
    int get_borrowed_count() const;
    int get_borrow_limit() const;

    //borrow and return books
    void borrow();
    void return_();

    //virtual function to print user info
    virtual void print_user() const = 0; //pure virtual function
};

class Student : public LibraryUser {
private:
    static vector<string> valid_genres; //valid genres for students

public:
    //default constructor
    Student();

    //parameterized constructor
    Student(const string& name, const string& user_id, int borrow_limit);

    //getter
    int get_borrow_limit() const;

    //print student details
    void print_user() const override;
};

class Teacher : public LibraryUser {
private:
    vector<string> valid_genres; //valid genres for teachers

public:
    //default constructor
    Teacher();

    //parameterized constructor
    Teacher(const string& name, const string& user_id, int borrow_limit);

    //getter
    int get_borrow_limit() const;

    //add book to the library
    void add_book_to_library(Library& library, Book* book);

    //update book details
    void update_book_details(Library& library, const string& title, const string& new_author, const string& new_genre, int new_year);

    //print teacher details
    void print_user() const override;
};

#endif // LIBRARYUSER_HPP
