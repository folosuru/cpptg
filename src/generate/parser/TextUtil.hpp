#ifndef TEXTUTIL_HPP
#define TEXTUTIL_HPP
#include <string_view>

namespace cpptg {
bool skipComment(const std::string_view& target, std::size_t& pos);
bool skipSpace(const std::string_view& target, std::size_t& pos, bool keep_one);
bool skipDoubleQuote(const std::string_view& target, std::size_t& pos);
bool skipReturning(const std::string_view& target, std::size_t& pos);
bool skipBlank(const std::string_view& target, std::size_t& pos, bool keep_one = false);
char getNextNotSpaceChar(const std::string_view& target, std::size_t pos);
std::string getTypename(std::string_view target, std::size_t pos);
}
#endif //TEXTUTIL_HPP
