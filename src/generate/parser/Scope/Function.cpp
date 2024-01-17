#include "Function.hpp"

#include "../TextUtil.hpp"

namespace cpptg {
std::variant<Function, std::monostate> Function::create(const Tokens::iterator& line_iter, std::list<namespace_stack_item> ns) {
    std::string_view line{*line_iter};
    std::size_t current = 0;
    std::string var_type;
    std::string func_name;
    while (line.at(current) != ' ') {
        var_type += line.at(current);
        ++current;
    }
    std::cout << "type: " << var_type << "\n";
    ++current;
    if (line.at(current) == '(') { // [type] (
        if (getNextNotSpaceChar(line, current+1) == '*') {
            // function ptr
            return std::monostate();
        }
        while (line.at(current) != ')') {
            func_name += line.at(current);
            ++current;
        }
        std::cout << "func: " << func_name << "\n";
        ++current;
    } else {
        while (getNextNotSpaceChar(line, current) == '(') {
            while ('0' <= line.at(current) && line.at(current) <= '9' ||
                   'a' <= line.at(current) && line.at(current) <= 'z' ||
                   'A' <= line.at(current) && line.at(current) <= 'Z' ||
                   line.at(current) == '_') {
                func_name += line.at(current);
                ++current;
            }

        }
        std::cout << "Func: " << func_name << "\n";
    }
    if (getNextNotSpaceChar(line, current) == '(') {
        return Function(func_name);
    } else {
        return std::monostate{};
    }
}



} // cpptg