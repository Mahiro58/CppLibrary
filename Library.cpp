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
        std::cout<<"Lp."<<number<<" Id: "<<book.getId()<<" "<<book.getTitle()<<" autora "<<book.getAuthor()<<" "<<book.getYear()<<" "<<book.showStatus()<<std::endl;
        number++;
    }
}

void Library::getAllUsers(){
    std::cout<<"Lista uzytkownikow: \n";
    int number = 1;
    for (User user : library_user_storage){
        std::cout<<"Lp."<<number<<" "<<user.getUserName()<<" "<<user.getUserSurname()<<" ID: "<<user.getId()<<std::endl;
        number++;
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

void Library::borrowBook(long user_id, long book_id){
    for(Book book : library_book_storage){
        if(book.getId() == book_id){
            Borrow borrow{user_id, book_id};
            library_borrowed_books.push_back(borrow);
            std::cout<<"Ksiazka "<<book.getTitle()<<" autora "<<book.getAuthor()<<" zostala wypozyczona.\n";
        }
    }
    throw std::runtime_error("Error: Nie znaleziono ksiazki o ID: " + book_id);
}

void Library::returnBook(long book_id){
    int book_index = -1;
    for(int i = 0; Borrow& check_book : library_borrowed_books){
        if(check_book.getBookId() == book_id){
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
    for(Book& book : library_book_storage){
        std::cout<<book.getTitle()<<" "<<book.getAuthor()<<" o ID: "<<book.getId();
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
                current_highest_id++;
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
    long current_highest_id = 0;
    if(library_book_storage.size() > 0){
        for(Book book : library_book_storage){
            if(book.getId() > current_highest_id){
                current_highest_id = book.getId();
                current_highest_id++;
            }
        }
        return current_highest_id;
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

void Library::getAllBorrowedBooks(){
    int number = 1;
    for(Borrow& book : library_borrowed_books){
        displayBook(book.getBookId());
    }
}

User* Library::getUserById(long id){
    for(User& user : library_user_storage){
        if(user.getId() == id){
            return &user;
        }
    }
    return nullptr;
}

void Library::getUserAllBorrowedBooks(long user_id){
    int number = 0;
    for(Borrow& borrow : library_borrowed_books){
        if(borrow.getUserId() == user_id){
            number++;
            std::cout<<"Lp."<<number;
            displayBook(borrow.getBookId());
        }
    }
}