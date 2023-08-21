#include "../include/Row.hpp"
#include <iostream>
#include <iomanip>

void Row::print() const {
    std::cout << std::setw(10)<< std::left << ID
              << std::setw(10)<< std::left << group_number
              << std::setw(10)<< std::left << surname
              << std::setw(10)<< std::left << initials
              << std::setw(10)<< std::left << sex
              << std::setw(10)<< std::left << math
              << std::setw(10)<< std::left << geometry
              << std::setw(10)<< std::left << informatics;
}