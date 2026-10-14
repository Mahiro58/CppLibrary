#include "User.hpp"
#include "Library.hpp"
#include <iostream>

User::User(long id, const std::string& name, const std::string& surname)
    : user_id(id), user_name(name), user_surname(surname)
{
    if(id < 0){
        throw std::invalid_argument("ID musi byc dodatnie.");
    }
    if(name.empty()){
        throw std::invalid_argument("Imie nie moze byc puste.");
    }
    if(surname.empty()){
        throw std::invalid_argument("Nazwisko nie moze byc puste.");
    }

    std::cout<<"Utworzono nowego uzytkownika."<<std::endl;
}

const std::string& User::getUserName() const{
    return user_name;
}

const std::string& User::getUserSurname() const{
    return user_surname;
}

long User::getId() const{
    return user_id;
}