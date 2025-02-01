#include <iostream>     
#include "Book.hpp"    
#include <string>      
using namespace std;    

//default constructor

Book::Book() : title("n/a"), author("n/a"), genre("n/a"), year_published(0) {}

//parameterized constructor

Book::Book(const string& title, const string& author, const string& genre)
	: title(title), author(author), genre(genre), year_published(0) {}

//parameterized constructor with the year published

Book::Book(const string& title, const string& author, const string& genre, const int& year_published)
	: title(title), author(author), genre(genre), year_published(year_published) {}

//here are the getters


string Book::get_title() const 
{
	return title;
}


string Book::get_author() const 
{
	return author;
}

string Book::get_genre() const 
{
	return genre;
}

int Book::get_year_published() const 
{
	return year_published;
}

//here are the setters


void Book::set_author(const string& author)
{
	
}

//this function sets the genre of the book
void Book::set_genre(const string& genre)
{
}
	

//this function sets the year the book was published
void Book::set_year_published(const int& year)
{
	
}

//this is the overloaded equality operator
bool Book::operator==(const Book& other) const {
	return title == other.title && author == other.author &&
		genre == other.genre && year_published == other.year_published;
}

//this is the print method
void Book::print() const {
	cout << "Book's title - " << title << endl;
	cout << "Book's author - " << author << endl;
	cout << "Book's genre - " << genre << endl;
	cout << "Book's Year Published - " << year_published << endl;
    cout << "\n";
}
