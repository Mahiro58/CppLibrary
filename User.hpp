#pragma once
#include <vector>

#include "Book.hpp"

// User class to make user objects and store books they borrowed.

class User
{
    public:
        User(long id, std::string name, std::string surname);
        void addBook();
        void removeBook();
        Book getBorrowedBooks();

    private:
        long user_id;
        std::string user_name;
        std::string user_surname;
        std::vector<long> user_storage;

};