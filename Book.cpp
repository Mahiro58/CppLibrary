#include "Book.hpp"
#include <iostream>

Book::Book(long id, const std::string& title, const std::string& author, int year, int quantity)
    : book_id(id), book_title(title), book_author(author), book_year(year), book_quantity(quantity), isAvailable(true)
{
    if(id < 0){
        throw std::invalid_argument("ID musi byc dodatnie.");
    }
    if(title.empty()){
        throw std::invalid_argument("Tytul nie moze byc pusty.");
    }
    if(author.empty()){
        throw std::invalid_argument("Autor nie moze byc pusty.");
    }
    if(quantity < 0){
        throw std::invalid_argument("Ilosc musi byc dodatnia.");
    }

    std::cout<<"Utworzono nowa ksiazke."<<std::endl;
}

long Book::getId() const{
    return book_id;
}

const std::string& Book::getTitle() const{
    return book_title;
}

const std::string& Book::getAuthor() const{
    return book_author;
}

int Book::getYear() const{
    return book_year;
}

bool Book::getStatus() const{
    return isAvailable;
}

std::string Book::showStatus(){
    if (isAvailable == true){
        return "Dostepna";
    }
    else{
        return "Niedostepna";
    }
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