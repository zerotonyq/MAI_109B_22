#include "../include/Database.hpp"
#include <iostream>
#include <iomanip>
#include <string>
Database::Database()
{
    path = std::string(getenv("HOME")) + "/Документы/database.csv";
    database.open(path, std::ios::out);
    if(database.is_open())
    {
        create_db();
    }
    else
    {
        std::cerr << "Unable to open/create database file.(base creation)\n";
    }
    database.close();
}
Database::Database(const std::string& fileName)
{
    path = std::string(getenv("HOME")) + "/Документы/" + fileName + ".csv";
    database.open(path, std::ios::out);
    if(database.is_open())
    {
        create_db();
    }
    else
    {
        std::cerr << "Unable to open/create database file.(base creation)\n";
    }
    database.close();
}

void Database::create_db()
{
    if(database.is_open())
    {
        database << "ID, group_number, surname, inits, sex, math, geometry, informatics" << "\n";
    }
    else
    {
        std::cerr << "Unable to open/create database file.(table creation)\n";
    }
}

void Database::Print()
{
    std::cout << "------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(10) << std::left << "ID"
              << std::setw(10) << std::left << "group"
              << std::setw(10) << std::left << "surname"
              << std::setw(10) << std::left << "initials"
              << std::setw(10) << std::left << "sex" 
              << std::setw(10) << std::left << "math"
              << std::setw(10) << std::left << "geometry"
              << std::setw(10) << std::left << "informatics" << "\n";
    std::cout << "------------------------------------------------------------------------------------------\n";
    for(size_t i = 0; i < table.size(); ++i)
    {
        table[i].print();
        std::cout << "------------------------------------------------------------------------------------------\n";
    }
}
bool Database::FindPerson(size_t ID)
{
    database_r.open(path, std::ios::in);
    std::string rowStr = "";
    while(!database_r.eof())
    {
        getline(database_r, rowStr);
        std::string potentialNumber = "";
        for(size_t i = 0; i < rowStr.size(); ++i)
        {
            if(!std::isdigit(rowStr[i]))
                break;
            potentialNumber += rowStr[i];
        }

        //std::cout << cur << std::endl;
        if(potentialNumber.empty())
            continue;
        if(static_cast<size_t>(std::stoi(potentialNumber)) == ID)
        {
            std::cerr << "user with this ID is already in database" << std::endl;
            database_r.close();
            return true;
        }
    }

    database_r.close();
    return false;
}
bool Database::AddRow(const Row& row)
{
    database.open(path, std::ios::out | std::ios::app);
    if(FindPerson(row.ID))
    {
        database.close();
        return false;
    }
        
    table.push_back(row);
    if(database.is_open())
    {
        database << row.ID << ", "
                 << row.group_number << ", "
                 << row.surname << ", "
                 << row.initials << ", "
                 << row.sex << ", "
                 << row.math << ", "
                 << row.geometry << ", "
                 << row.informatics << "\n";
        database.close();
        return true;
    }   
    else
    {
        std::cerr << "Unable to open/create database file.(row adding) \n";
        return false;
    }
    database.close();
}

Vector<std::string> Database::FindBestGirls()
{
    Vector<std::string> girls;
    size_t maxBoysMarkSum = 0;
    for(size_t i = 0; i < table.size(); ++i)
    {
        Row currentPerson = table[i];
        if(currentPerson.sex == "female")
            continue;
        size_t currSum = table[i].math + table[i].geometry + table[i].informatics;
        if(currSum > maxBoysMarkSum)
            maxBoysMarkSum = currSum;
    }
    for(size_t i = 0; i < table.size(); ++i)
    {
        Row currentPerson = table[i];
        if(currentPerson.sex == "male")
            continue;
        if(currentPerson.math + currentPerson.geometry + currentPerson.informatics < maxBoysMarkSum)
            continue;
        if(currentPerson.math < 4 && currentPerson.informatics < 4 && currentPerson.informatics < 4)
            continue;
        girls.push_back(currentPerson.surname);

    }
    return girls;
}

Database::~Database()
{
    if(database.is_open())
        database.close();
}