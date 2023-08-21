#ifndef ROW_HPP
#define ROW_HPP

#include <string>

class Row
{
    friend class Database;
    private:
        size_t ID;
        size_t group_number;
        std::string surname;
        std::string initials;
        std::string sex;
        size_t math;
        size_t geometry;
        size_t informatics;
    public:
        Row() = default;
        Row(const size_t& ID,
            const size_t& group_number,
            const std::string& surname,
            const std::string& initials,
            const std::string& sex,
            const size_t& math,
            const size_t& geometry,
            const size_t& informatics) 
            : 
            ID(ID),
            group_number(group_number),
            surname(surname),
            initials(initials),
            sex(sex),
            math(math),
            geometry(geometry),
            informatics(informatics) {};
        void print() const;
        ~Row() = default;
};

#include "../src/Row.cpp"
#endif // ROW_HPP