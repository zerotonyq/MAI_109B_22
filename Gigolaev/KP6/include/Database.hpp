#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <fstream>
#include "./Row.hpp"
#include "../../lab23/include/Vector.hpp"
class Database
{
    public:
        Database();
        Database(const std::string& baseName);
        ~Database();
        void Print();
        bool AddRow(const Row& row);
        Vector<std::string> FindBestGirls();
    private:
        std::string path;
        std::ofstream database;
        std::ifstream database_r;
        Vector<Row> table;
        void create_db();
        bool FindPerson(size_t ID);


};
#include "../src/Database.cpp"
#endif // DATABASE_HPP