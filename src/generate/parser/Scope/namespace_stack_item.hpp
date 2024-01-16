#ifndef CPPTG_NAMESPACE_STACK_ITEM_HPP
#define CPPTG_NAMESPACE_STACK_ITEM_HPP
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


}
#endif //CPPTG_NAMESPACE_STACK_ITEM_HPP
