#include "LibraryUser.hpp"
#include "Library.hpp"
#include "Book.hpp"  //added to include the full definition of Book

#include <iostream>
using namespace std;

//static member initialization
const string temp[] = { "Fiction", "Non-Fiction", "Science", "History" };
vector<string> Student::valid_genres(temp, temp + sizeof(temp) / sizeof(temp[0]));

//LibraryUser implementation
LibraryUser::LibraryUser() : name(""), user_id(""), borrowed_count(0), borrow_limit(0) {}

LibraryUser::LibraryUser(const string& name, const string& user_id, int borrow_limit)
    : name(name), user_id(user_id), borrowed_count(0), borrow_limit(borrow_limit) {}

string LibraryUser::get_name() const { return name; }
string LibraryUser::get_user_id() const { return user_id; }
int LibraryUser::get_borrowed_count() const { return borrowed_count; }
int LibraryUser::get_borrow_limit() const { return borrow_limit; }

void LibraryUser::borrow() {
    if (borrowed_count < borrow_limit) {
        ++borrowed_count;
    } else {
        cout << "Borrow limit reached." << endl;
    }
}

void LibraryUser::return_() {
    if (borrowed_count > 0) {
        --borrowed_count;
    } else {
        cout << "No books to return." << endl;
    }
}

//student implementation
Student::Student() : LibraryUser("", "", 2) {}

Student::Student(const string& name, const string& user_id, int borrow_limit)
    : LibraryUser(name, user_id, borrow_limit) {}

int Student::get_borrow_limit() const { return borrow_limit; }

void Student::print_user() const {
    cout << "User Type: Student" << endl;
    cout << "Name: " << name << endl;
    cout << "User ID: " << user_id << endl;
    cout << "Borrow Limit: " << borrow_limit << endl;
    cout << "Valid Genres: ";
    for (const string& genre : valid_genres) {
        cout << genre << " ";
    }
    cout << endl;
}

//teacher implementation
Teacher::Teacher() : LibraryUser("", "", 4) {
    valid_genres = { "All" };
}

Teacher::Teacher(const string& name, const string& user_id, int borrow_limit)
    : LibraryUser(name, user_id, borrow_limit) {
    valid_genres = { "All" };
}

int Teacher::get_borrow_limit() const { return borrow_limit; }

void Teacher::add_book_to_library(Library& library, Book* book) {
    //assuming Library and Book are implemented
    cout << "Book added by Teacher: " << name << endl;
}

void Teacher::update_book_details(Library& library, const string& title, const string& new_author, const string& new_genre, int new_year) {
    //assuming Library and Book are implemented
    cout << "Book details updated by Teacher: " << name << endl;
}

void Teacher::print_user() const {
    cout << "User Type: Teacher" << endl;
    cout << "Name: " << name << endl;
    cout << "User ID: " << user_id << endl;
    cout << "Borrow Limit: " << borrow_limit << endl;
    cout << "Valid Genres: ";
    for (const string& genre : valid_genres) {
        cout << genre << " ";
    }
    cout << endl;
}
