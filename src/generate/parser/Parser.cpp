#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include "PreProcessFile.hpp"
#include "Tokens.hpp"
#include "Scope/Function.hpp"
#include "Scope/namespace_stack_item.hpp"

namespace  {}
namespace cpptg {
namespace {

bool incriment_to(std::string_view start, std::size_t& current, char find) {
    while (current < start.length()) {
        ++current;
        if (start.at(current) == find) return true;
    }
    return false;
}
}
std::string parse(const std::filesystem::path& file_path) {
    PreProcessFile file(file_path);
    Tokens tokens{file};
    std::list<namespace_stack_item> scope_stack;
    for (auto i = tokens.begin(); i!=tokens.end(); ++i) {
        //std::cout << " | "<<  *i << "\n";
        if (i->starts_with("using ")    ||
            i->starts_with("typedef ")  ||
            i->starts_with("continue ") ||
            i->starts_with("break ")    ||
            i->starts_with("delete ")
            ) {
            continue;
        }

        if (i->starts_with("namespace ")) {
            scope_stack.push_back(get_namespace(i));
        } else if (i->starts_with("class ")) {
            scope_stack.push_back(get_class(i));
        } else if (i->starts_with("struct ")) {
            scope_stack.push_back(get_struct(i));
        } else if (i->ends_with('{')) {
            Function::create(i, scope_stack);
            skipToBracketClose(i);
            //std::cout << " | //... \n" << *i << "\n";
        }
    }
    return "";
}
}

namespace {}
namespace a {

}
namespace fop{
}

