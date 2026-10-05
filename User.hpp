#pragma once
#include <vector>
#include <string>

#include "Book.hpp"

// User class to make user objects and store books they borrowed.

class User
{
    public:
        User(long id, const std::string& name, const std::string& surname);
        void addBook(const Book& book);
        void removeBook(const Book& book);
        Book getBorrowedBooks();

    private:
        long user_id;
        std::string user_name;
        std::string user_surname;
        std::vector<long> user_storage;

};