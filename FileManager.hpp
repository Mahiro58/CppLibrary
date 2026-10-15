#pragma once

#include <string>
#include <vector>
#include "Library.hpp"
#include "Book.hpp"

class FileManager{

    public:
        static bool saveBooks(const std::vector<Book>& books, const std::string& file_name); // saves books to file.
        static std::vector<Book> loadBooks(const std::string& file_name); // load books from file.

    private:

};