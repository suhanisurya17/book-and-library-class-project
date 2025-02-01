#pragma once
#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include<string>
using namespace std;

class Book 
{
private:
	string title;
	string author;
	string genre;
	int year_published;
public:
	//constructors
	Book();
	Book(const string& title, const string& author, const string& genre);
	Book(const string& title, const string& author, const string& genre, const int& year_published);

	//getters
	string get_title() const;
	string get_author() const;
	string get_genre() const;
	int get_year_published() const;

	//setters
	void set_author(const string& author);
	void set_genre(const string& genre);
	void set_year_published(const int& year);

	bool operator==(const Book& other) const;

	//printing
	void print() const;

};

#endif 
