#pragma once

#include <vector>

#include "Book.hpp"
#include "User.hpp"

// Core business logic implementation

class Library
{
    public:
        void newBook(Book book);
        void newUser(User user);
        void getAllBooks();
        void getAllUsers();
        void findBookWithAuthor(const Book& author);
        void findBookWithTitle(const Book& title);
        void borrowBook();
        void returnBook();

    private:
        std::vector<Book> library_book_storage;
        std::vector<Book> library_borrowed_books;
        std::vector<User> library_user_storage;

};