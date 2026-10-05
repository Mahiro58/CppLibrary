#include "User.hpp"
#include <iostream>

User::User(long id, const std::string& name, const std::string& surname)
    : user_id(id), user_name(name), user_surname(surname)
{
    std::cout<<"Utworzono nowego uzytkownika."<<std::endl;
}

void User::addBook(const Book& book){
    long  book_id = book.getId();
    user_storage.push_back(book_id);
    std::string book_title = book.getTitle();
    std::cout<<"Dodano "<<book_title<<" do wypozyczonych ksiazek uzytkownika."<<std::endl;
}

void User::removeBook(const Book& book){
    long book_id = book.getId();
    for (auto it = user_storage.begin(); it != user_storage.end();){
        if (*it == book_id){
            it = user_storage.erase(it);
            std::cout<<"Ksiazka o id: "<<book_id<<" zostala usunieta."<<std::endl;
        }
        else{
            it++;
        }
    }
}