#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <vector>
#include <string>

#include "PreProcessFile.hpp"

namespace cpptg {

struct Token_line {
    std::string line;
    std::vector<std::string_view> tokens;
    void tokenize_line();
};


/**
 * \brief hold token and format
 */
class Tokens : public std::vector<Token_line> {
public:
    explicit Tokens(const PreProcessFile&);

    void new_token();

    void add_char(char);
private:
    void comply_token(std::size_t& current, std::size_t& now_statement_start, std::string_view file_view);
};

} // cpptg

#endif //TOKENS_HPP
