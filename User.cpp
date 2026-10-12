#include "User.hpp"
#include "Library.hpp"
#include <iostream>

User::User(long id, const std::string& name, const std::string& surname)
    : user_id(id), user_name(name), user_surname(surname)
{
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