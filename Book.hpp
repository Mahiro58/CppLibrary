#pragma once

#include <string>

// Book class to make books as a objects, store them and get their values

class Book
{
    public:
        Book(long id, const std::string& title, const std::string& author, int year);
        long getId() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        int getYear() const;
        bool getStatus() const;
        void changeStatus(); //simpe function to change book's available status.

    private:
        long book_id;
        std::string book_title;
        std::string book_author;
        int book_year;
        bool isAvailable;

};