#ifndef CPPTG_NAMESPACE_STACK_ITEM_HPP
#define CPPTG_NAMESPACE_STACK_ITEM_HPP
#include <string>
#include "../Tokens.hpp"
namespace cpptg {

enum class namespace_stack_type {
    namespace_,
    class_,
    noname_namespace,
    other
};
struct namespace_stack_item {
    namespace_stack_type type;
    std::string name;
};

namespace_stack_item get_namespace(Tokens::iterator&);
namespace_stack_item get_class(Tokens::iterator&);
namespace_stack_item get_struct(Tokens::iterator&);

/*
 * gennzaino goyude simesareteru { ga
 * tozirumade susumeru
 * tozita gyouni iku
if (foo()) {  <- start
//...
//...
}             <- end
//...

 */

void skipToBracketClose(Tokens::iterator&);
}
#endif //CPPTG_NAMESPACE_STACK_ITEM_HPP
