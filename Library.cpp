
#include "LibraryUser.hpp"
#include "Library.hpp"


#include<iostream>
#include <vector>
#include <string>
using namespace std;

Library::Library() {}

Library::Library(const vector <Book*>& book_list) {
    for (Book* book : book_list) {
        Books.push_back(book);
        is_borrowed.push_back(false);
    }
}
//ADDING A NEW BOOK TO THE LIBRARY

//input: user enters the book they wish to add (and author, etc)
//processing: system takes in book information that user adds and adds to the library of existing books
//output: new library list, where the book is now in library.
bool Library::insert(Book* new_book) {
    for (Book* old_books : Books) {
        if (*old_books == *new_book) {
            return false;
        }
    }
    Books.push_back(new_book);
    is_borrowed.push_back(false);
    return true;
}
//REMOVING A BOOK FROM THE LIBRARY

//input: user enters the book they wish to remove (teacher only)
//processing: loop searched for book, deletes it
//output: new library where the book has been removed
bool Library::remove(Book* removed_book) {
    for (int i = 0; i < Books.size(); ++i) {
        if (*Books[i] == *removed_book) {
            delete Books[i];
            Books.erase(Books.begin() + i);
            is_borrowed.erase(is_borrowed.begin() + i);
            return true;
        }
    }
    cout << "Book not removed. This book is not in the library." << endl;
    return false;
}

//ADVANCED SEARCH FEATURE
//input: user enters their search
//processing: loop runs through if either the title, author, or genre is a match
//output: if a match is found, match is shown. if not, no match message appears.
void Library::advanced_search(const string& title_substring, const string& author_substring, const string& genre_substring) const {
    bool found = false;

    for (int i = 0; i < Books.size(); ++i) {
        bool do_titles_match = (title_substring.empty() || Books[i]->get_title().find(title_substring) < Books[i]->get_title().length());
        bool do_authors_match = (author_substring.empty() || Books[i]->get_author().find(author_substring) < Books[i]->get_author().length());
        bool do_genres_match = (genre_substring.empty() || Books[i]->get_genre().find(genre_substring) < Books[i]->get_genre().length());

        if (do_titles_match && do_authors_match && do_genres_match) {
            if (!found) {
                cout << "Your search resulted in a match!" << endl;
            }
            Books[i]->print();
            found = true;
        }
    }
        if (!found) {
            cout << "Sorry, your search did not result in a match." << endl;
        }
    }




//book borrowing

//input: user enters a book title/etc that they want to borrow
//processing: library ensures that user is not over their borrow limit, and finds book
//output: if everything matches from processing, book is borrowed. if not, error message.
bool Library::borrow(const string& title, LibraryUser& user) {
    

    for (int i = 0; i < Books.size(); ++i) {
        if (Books[i]->get_title() == title) {
            if (is_borrowed[i]) {
                cout << "Sorry! This book has already been borrowed." << endl;
                return false;
            }

            if (user.get_borrowed_count() >= user.get_borrow_limit()) {
                cout << "Error: You have reached the borrow limit" << endl;
                return false;
            }
            is_borrowed[i] = true;
            user.borrow();
            cout << user.get_name() << " has successfully borrowed the book " << title << "." << endl;
            return true;
        }
    }
    cout << "Error: Book not found. " << endl;
    return false;
}

//book returning
//input: user enters the book they wish to return
//processing: library ensures that the book exists, has been taken out
//output: book is returned back to the library and is now available for others to take out
bool Library::return_(const string& title, LibraryUser& user) {
    for (int i = 0; i < Books.size(); ++i) {
        if (Books[i]->get_title() == title) {
            if (!is_borrowed[i]) {
                cout << "The book is available to borrow" << endl;
                return false;
            }
            is_borrowed[i] = false;
            user.return_();
            cout << user.get_name() << " has returned the book: " << title << endl;
            //cout << "Debug: User borrowed count after return = " << user.get_borrowed_count() << endl;
            return true;
        }
    }
    cout << "Error: Book not found";
    return false;
}



//print the library
void Library::print() const {
    cout << "All library books: " << endl;
    for (const auto& book : Books) {
        book->print();
    }
}

vector<Book*>& Library::get_books()
{
    return Books;
}
