#include "Library.hpp"
#include <iostream>

void Library::newBook(Book book){
    library_book_storage.push_back(book);
    std::cout<<book.getTitle()<<" dodano do bazy danych.\n";
}

void Library::newUser(User user){
    library_user_storage.push_back(user);
    std::cout<<"Utworzono nowego uzytkownika. Witaj "<<user.getUserName()<<std::endl;
}

void Library::getAllBooks(){
    std::cout<<"Lista ksiazek: \n";
    int number = 1;
    for (Book book : library_book_storage){
        std::cout<<"Lp."<<number<<" Id: "<<book.getId()<<" "<<book.getTitle()<<" "<<book.getAuthor()<<" "<<book.getYear()<<" "<<book.showStatus()<<std::endl;
    }
}

void Library::getAllUsers(){
    std::cout<<"Lista uzytkownikow: \n";
    int number = 1;
    for (User user : library_user_storage){
        std::cout<<"Lp."<<number<<" "<<user.getUserName()<<" "<<user.getUserSurname()<<std::endl;
    }
}

void Library::findBookWithAuthor(std::string author){
    std::cout<<"Lista ksiazek autora "<<author<<":\n";
    int number = 0;
    for (Book check_book : library_book_storage){
        if(author == check_book.getAuthor()){
            number++;
            std::cout<<"Lp."<<number<<" "<<check_book.getTitle()<<std::endl;
        }
    }
    if(number == 0){
        std::cout<<"Nie znaleziono zadnych ksiazek.\n";
    }
    else{
        std::cout<<"To wszystkie znalezione ksiazki.\n";
    }
}

void Library::findBookWithTitle(std::string title){
    std::cout<<"Lista ksiazek o tytule "<<title<<":\n";
    int number = 0;
    for (Book check_book : library_book_storage){
        if(check_book.getTitle() == title){
            number++;
            std::cout<<"Lp."<<number<<" "<<check_book.getTitle()<<" "<<check_book.getAuthor()<<std::endl;
        }
    }
    if(number == 0){
        std::cout<<"Nie znaleziono zadnych ksiazek.\n";
    }
    else{
        std::cout<<"To wszystkie znalezione ksiazki.\n";
    }
}