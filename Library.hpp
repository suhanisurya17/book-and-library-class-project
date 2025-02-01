#pragma once
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>       
#include <string>       
#include <iostream>     
#include "Book.hpp"     
#include "LibraryUser.hpp" 
using namespace std;    

//Library Class
class Library {
private:
    vector<Book*> Books;       
    vector<bool> is_borrowed;  

public:
    //default constructor
    Library();

    //parameterized constructor
    Library(const vector<Book*>& book_list);

    //inserts a book into the library
    bool insert(Book* new_book);

    //removes a book from the library
    bool remove(Book* book_to_remove);

    //user can search for a book
    void advanced_search(const string& title_substring, const string& author_substring, const string& genre_substring) const;

    //user requests to borrow a book
    bool borrow(const string& title, LibraryUser& user);

    //user returns a book they took out
    bool return_(const string& title, LibraryUser& user);

    //print all library books
    void print() const;

 
    vector<Book*>& get_books();
};

#endif // LIBRARY_HPP
