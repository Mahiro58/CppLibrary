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

void Library::borrowBook(const Book& book){
    library_borrowed_books.push_back(book);
    std::cout<<"Ksiazka "<<book.getTitle()<<" autora "<<book.getAuthor()<<" zostala wypozyczona.\n";
}

void Library::returnBook(long id){
    int book_index = -1;
    for(int i = 0; Book check_book : library_borrowed_books){
        if(check_book.getId() == id){
            book_index = i;
        }
        i++;
    }
    if(book_index < 0){
        std::cout<<"Nie znaleziono ksiazki.\n";
    }
    else{
        library_borrowed_books.erase(library_borrowed_books.begin() + book_index);
        std::cout<<"Ksiazka zostala oddana.\n";
    }
}

void Library::displayBook(long id){
    int number = 0;
    for (Book book : library_borrowed_books){
        if(id == book.getId()){
            number++;
            std::cout<<"Lp."<<number<<" "<<book.getTitle()<<" "<<book.getAuthor()<<std::endl;
        }
    }
    if(number == 0){
        std::cout<<"Brak wypozyczonych ksiazek.\n";
    }
    else{
        std::cout<<"To wszystkie wypozyczone ksazki.\n";
    }
}

bool Library::checkUserId(long id)
{
    for (const User& user : library_user_storage)
    {
        if (user.getId() == id)
        {
            return true;
        }
    }

    return false;
}

long Library::makeUserId(){
    long current_highest_id = 0;
    if(library_user_storage.size() > 0){
        for(User user : library_user_storage){
            if(user.getId() > current_highest_id){
                current_highest_id = user.getId();
            }
        }
        return current_highest_id++;
    }
    else{
        return 1;
    }
}

void Library::createUser(const std::string& user_name, const std::string& user_surname){
    long user_id = makeUserId();
    User user(user_id, user_name, user_surname);
    library_user_storage.push_back(user);

    std::cout<<"Utworzono nowego uzytkownika: "<<user_name<<" "<<user_surname<<" o ID: "<<user_id<<std::endl;
}

long Library::makeBookId(){
    long current_highest_id;
    if(library_book_storage.size() > 0){
        for(Book book : library_book_storage){
            if(book.getId() > current_highest_id){
                current_highest_id = book.getId();
            }
        }
        return current_highest_id++;
    }
    else{
        return 1;
    }
}

void Library::createBook(const std::string& book_title, const std::string& book_author, int year){
    long book_id = makeBookId();
    Book book (book_id, book_title, book_author, year);
    library_book_storage.push_back(book);

    std::cout<<"Dodano ksiazke "<<book_title<<" autora "<<book_author<<" o ID: "<<book_id<<std::endl;
}