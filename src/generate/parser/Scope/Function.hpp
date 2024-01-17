#ifndef CPPTG_FUNCTION_HPP
#define CPPTG_FUNCTION_HPP
#include <iostream>

#include "../Tokens.hpp"
#include <variant>

#include "namespace_stack_item.hpp"

namespace cpptg {

class Function {
public:
    static std::variant<Function, std::monostate> create(const Tokens::iterator&, std::list<namespace_stack_item>);


    std::string name;
private:
    explicit Function(std::string name) {
        //std::cout << "function!" << name << "\n";
    }
    std::list<namespace_stack_item> namespaces;
};

} // cpptg

#endif //CPPTG_FUNCTION_HPP
