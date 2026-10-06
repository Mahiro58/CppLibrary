#pragma once

#include <vector>

#include "Book.hpp"
#include "User.hpp"

// Core business logic implementation

class Library
{
    public:
        void newBook(Book book); // adds new book to database.
        void newUser(User user); // adds new user to database.
        void getAllBooks(); // shows all books in database.
        void getAllUsers(); // shows all users in database.
        void findBookWithAuthor(std::string author); // a function to show author's all books in database.
        void findBookWithTitle(std::string title); // a function to show books with title.
        void borrowBook(const Book& book); // adds Book object to library_borrowed_books database.
        void returnBook(long id); // removes Book object from library_borrowed_books database base on book's id.
        void displayBook(long id);

    private:
        std::vector<Book> library_book_storage;
        std::vector<Book> library_borrowed_books;
        std::vector<User> library_user_storage;

};