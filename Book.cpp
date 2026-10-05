#include "Book.hpp"
#include <iostream>

Book::Book(long id, const std::string& title, const std::string& author, int year)
    : book_id(id), book_title(title), book_author(author), book_year(year), isAvailable(true)
{
    std::cout<<"Utworzono nowa ksiazke."<<std::endl;
}

long Book::getId(){
    return book_id;
}

std::string Book::getTitle(){
    return book_title;
}

std::string Book::getAuthor(){
    return book_author;
}

int Book::getYear(){
    return book_year;
}

bool Book::getStatus(){
    return isAvailable;
}

void Book::changeStatus(){
    if(isAvailable == true){
        isAvailable = false;
        std::cout<<book_title<<" status changed to "<<isAvailable<<std::endl;
    }
    else {
        isAvailable = true;
        std::cout<<book_title<<" status changed to "<<isAvailable<<std::endl;
    }
}