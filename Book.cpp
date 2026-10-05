#include "Book.hpp"
#include <iostream>

Book::Book(long id, const std::string& title, const std::string& author, int year)
    : book_id(id), book_title(title), book_author(author), book_year(year), isAvailable(true)
{
    std::cout<<"Utworzono nowa ksiazke."<<std::endl;
}