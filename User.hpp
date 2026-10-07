#pragma once
#include <vector>
#include <string>

#include "Book.hpp"

// User class to make user objects and store books they borrowed.

class Library;

class User
{
    public:
        User(long id, const std::string& name, const std::string& surname);
        void addBook(const Book& book); // function add book's id to user_storage.
        void removeBook(const Book& book); // function removes book's id from user_storage.
        void getBorrowedBooks(Library& display, const std::vector<long>& user_storage); // function shows user's all borrowed books.
        std::string getUserName() const;
        std::string getUserSurname() const;
        long getId() const;

    private:
        long user_id;
        std::string user_name;
        std::string user_surname;
        std::vector<long> user_storage;

};