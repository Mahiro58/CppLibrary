#pragma once

#include <string>

// Book class to make books as a objects, store them and get their values

class Book
{
    public:
        Book(long id, const std::string& title, const std::string& author, int year);
        long getId();
        std::string getTitle();
        std::string getAuthor();
        int getYear();
        bool getStatus();
        void changeStatus();

    private:
        long book_id;
        std::string book_title;
        std::string book_author;
        int book_year;
        bool isAvailable;

};