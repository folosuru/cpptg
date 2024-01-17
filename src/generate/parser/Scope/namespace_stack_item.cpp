#include "namespace_stack_item.hpp"

#include <iostream>
#include <stack>

namespace cpptg {

namespace_stack_item get_namespace(Tokens::iterator& text) {
    std::string name;
    for (std::size_t current = sizeof("namespace ")-1; current < text->length() - 1;++current) {
        if (isspace(text->at(current))) continue;
        if (text->at(current) == '{') {
            if (!name.empty()) {
                return {namespace_stack_type::namespace_, name};
            } else {
                return {namespace_stack_type::noname_namespace, "noname"};
            }
            break;
        }
        name += text->at(current);
    }
    return {};
}
namespace_stack_item get_struct(Tokens::iterator& text) {
    std::vector<std::string> name;
    name.emplace_back();
    for (std::size_t current = sizeof("struct ")-1; current < text->length();++current) {
        if (isspace(text->at(current))) {
            name.emplace_back();
        }
        if (text->at(current) == ':'|| text->at(current) == '{'){
            std::cout << "detect struct:" << *++name.rbegin() << "\n";
            return {namespace_stack_type::class_, {*++name.rbegin()}};
        }
        name.back() += text->at(current);
    }
    return {};
}
namespace_stack_item get_class(Tokens::iterator& text) {
    std::vector<std::string> name;
    name.emplace_back();
    for (std::size_t current = sizeof("class ")-1; current < text->length();++current) {
        if (isspace(text->at(current))) {
            name.emplace_back();
        }
        if (text->at(current) == ':'|| text->at(current) == '{'){
            std::cout << "detect class:" << *++name.rbegin() << "\n";
            return {namespace_stack_type::class_, {*++name.rbegin()}};
        }
        name.back() += text->at(current);
    }
    return {};
}

void skipToBracketClose(Tokens::iterator& iter) {
    int nest_count = 1;
    ++iter;
    while (nest_count != 0) {
        //std::cout <<  nest_count << "skip:" << *iter << "\n";
        for (const auto&i : *iter) {
            if (i == '{') {
                ++nest_count;
            }
            if (i == '}') {
                --nest_count;
            }
        }
        ++iter;
    }
    --iter;
}
}
