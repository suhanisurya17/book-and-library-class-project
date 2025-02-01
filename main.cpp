#include "Book.hpp"
#include "Library.hpp"
#include "LibraryUser.hpp"
#include <iostream>
using namespace std;

int main() {
    Library library;
    Student student;
    Teacher teacher;

    //this is the books part of the library
    Book Book1("A Dog's Purpose", "W. Bruce Cameron", "Fiction", 2010);
    Book Book2("One of Us is Lying", "Karen M. McManus", "Fiction", 2017);
    Book Book3("The Summer I Turned Pretty", "Jenny Han", "Fiction", 2009);
    Book Book4("All the Bright Places", "Jennifer Niven", "Fiction", 2015);
    Book Book5("We Were Liars", "E. Lockhart", "Fiction", 2014);

    //inserting books into the library
    library.insert(&Book1);
    library.insert(&Book2);
    library.insert(&Book3);
    library.insert(&Book4);
    library.insert(&Book5);

    //main menu systems
    int choice = 0;
    while (choice != 6) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Insert a new book in the library\n";
        cout << "2. Book Search tool\n";
        cout << "3. Book borrowing tool\n";
        cout << "4. Book returning tool\n";
        cout << "5. Print all current library books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) //switch statement for choices and actions
        {
        case 1: {
            string title, author, genre;
            int year;
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter genre: ";
            getline(cin, genre);
            cout << "Enter year published: ";
            cin >> year;

            Book* newBook = new Book(title, author, genre, year);
            if (library.insert(newBook)) {
                cout << "Book added successfully.\n";
            } else {
                cout << "Error: Book already exists in the library.\n";
            }
            break;
        }
        case 2: {
            string title, author, genre;
            cin.ignore();
            cout << "Enter the title (or hit enter): ";
            getline(cin, title);
            cout << "Enter the author name (or hit enter): ";
            getline(cin, author);
            cout << "Enter the genre (or hit enter): ";
            getline(cin, genre);

            library.advanced_search(title, author, genre);
            break;
        }
        case 3: {
            string title;
            int userType;
            cin.ignore();
            cout << "Enter the book title you wish to borrow: ";
            getline(cin, title);
            cout << "Who is borrowing the book? (Enter 1 - Student, Enter 2 - Teacher): ";
            cin >> userType;

            if (userType == 1) {
                if (library.borrow(title, student)) {
                    cout << "Book borrowed successfully by the student.\n";
                } else {
                    cout << "Failed to borrow the book.\n";
                }
            } else if (userType == 2) {
                if (library.borrow(title, teacher)) {
                    cout << "Book borrowed successfully by the teacher.\n";
                } else {
                    cout << "Failed to borrow the book.\n";
                }
            } else {
                cout << "Invalid user type.\n";
            }
            break;
        }
        case 4: {
            string title;
            int userType;
            cin.ignore();
            cout << "Enter the title of the book you wish to return: ";
            getline(cin, title);
            cout << "Who is returning the book? (Enter 1 - Student, Enter 2 - Teacher): ";
            cin >> userType;

            if (userType == 1) {
                if (library.return_(title, student)) {
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Error: Book return failed.\n";
                }
            } else if (userType == 2) {
                if (library.return_(title, teacher)) {
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Error: Book return failed.\n";
                }
            } else {
                cout << "Error: Invalid user type.\n";
            }
            break;
        }
        case 5: {
            library.print();
            break;
        }
        case 6:
            cout << "Exited\n";
            break;
        default:
            cout << "Error: Invalid choice.\n";
        }
    }

    return 0;
}
