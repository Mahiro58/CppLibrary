#include <iostream>

#include "Library.hpp"

int main()
{
    bool condition = true;
    int chooice = 0;
    Library admin;
    while (condition)
    {
        std::cout<<"Witaj w bibliotece.\n";
        std::cout<<"1. Dodaj uzytkownika.\n";
        std::cout<<"2. Dodaj ksiazke.\n";
        std::cout<<"3. Spis ksiazek.\n";
        std::cout<<"4. Wypozycz ksiazke.\n";
        std::cout<<"5. Oddaj ksiazke.\n";
        std::cout<<"6. Spis wszystkich wypozyczonych ksiazek.\n";
        std::cout<<"7. Spis Twoich wypozyczonych ksiazek.\n";
        std::cout<<"9. Wyjscie.\n";
        std::cin>>chooice;

        switch (chooice)
        {
        case 1: {
            std::string user_name;
            std::string user_surname;
            std::cout<<"Podaj imie: ";
            std::cin>>user_name;
            std::cout<<"Podaj nazwisko: ";
            std::cin>>user_surname;
            admin.createUser(user_name, user_surname);            
            
            break;
        }

        case 2: {
            std::string book_title;
            std::string book_author;
            int year = -1;
            std::cout<<"Podaj tytul ksiazki: ";
            std::cin>>book_title;
            std::cout<<"Podaj autora ksiazki: ";
            std::cin>>book_author;
            std::cout<<"Podaj rok wydania ksiazki: ";
            std::cin>>year;
            admin.createBook(book_title, book_author, year);
        
            break;
        }
        
        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 9:
            std::cout<<"Do zobaczenia.\n";
            condition = false;
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}