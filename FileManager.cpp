#include "FileManager.hpp"
#include <iostream>
#include <fstream>

bool FileManager::saveBooks(const std::vector<Book>& books, const std::string& file_name){
    std::ofstream file(file_name);

    if(!file){
        std::cerr<<"Nie mozna otworzyc pliku.\n";
        return false;
    }
    for(const Book& book : books){
        file<<book.getId()<<";"<<book.getTitle()<<";"<<book.getAuthor()<<";"<<book.getYear()<<";"<<book.getQuantity()<<";"<<book.getStatus()<<"\n";
    }
}

std::vector<Book> FileManager::loadBooks(const std::string& file_name){

}