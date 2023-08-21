#include "../include/Database.hpp"
#include <iostream>

int main()
{
    Database* base = new Database();
    Row r1(1, 11, "Bob", "BB", "male", 5, 5, 3);
    Row r2(2, 11, "Morty", "MM", "male", 4, 4, 4);
    Row r3(3, 11, "Rick", "RR", "male", 3, 3, 3);
    Row r4(4, 11, "Angela", "AA", "female", 5, 3, 5);
    Row r5(5, 11, "Milena", "MM", "female", 5, 5, 5);
    Row r6(6, 11, "Kristy", "KK", "female", 4, 4, 5);
    Row r7(7, 11, "Kassedy", "KK", "female", 3, 4, 5);
    base->AddRow(r1);
    base->AddRow(r2);
    base->AddRow(r3);
    base->AddRow(r4);
    base->AddRow(r5);
    base->AddRow(r6);
    base->AddRow(r7);

    base->Print();
    Vector<std::string> girls = base->FindBestGirls();
    std::cout << std::endl << "The best girls are: " << std::endl;
    for(size_t i = 0; i < girls.size(); ++i)
    {
        std::cout << girls[i] << std::endl;
    }
    delete base;
    return 0;
}