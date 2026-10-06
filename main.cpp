#include <iostream>

#include "Book.hpp"
#include "User.hpp"
#include "Library.hpp"

int main()
{
    bool condition = true;
    int chooice = 0;
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

        switch (chooice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}