#include "FileManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool FileManager::saveBooks(const std::vector<Book>& books, const std::string& file_name){
    std::ofstream file(file_name);

    if(!file){
        std::cerr<<"Nie mozna otworzyc pliku.\n";
        return false;
    }
    for(const Book& book : books){
        file<<book.getId()<<";"<<book.getTitle()<<";"<<book.getAuthor()<<";"<<book.getYear()<<";"<<book.getQuantity()<<"\n";
    }
}

std::vector<Book> FileManager::loadBooks(const std::string& file_name){
    std::vector<Book> books;

    std::ifstream file(file_name);

    if (!file) {
        std::cerr << "Nie mozna otworzyc pliku!\n";
        return books;
    }

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string id;
        std::string title;
        std::string author;
        std::string year;
        std::string quantity;

        std::getline(ss, id, ';');
        std::getline(ss, title, ';');
        std::getline(ss, author, ';');
        std::getline(ss, year, ';');
        std::getline(ss, quantity, ';');

        Book book(
            std::stol(id),
            title,
            author,
            std::stoi(year),
            std::stoi(quantity)
        );

        books.push_back(book);
    }

    return books;

}