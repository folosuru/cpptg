#include "Tokens.hpp"

#include <stack>
#include <array>
#include <algorithm>
#include "TextUtil.hpp"

namespace cpptg {
constexpr std::array<std::string_view, > operator_list {"",""};


void Token_line::tokenize_line() {
}

void Tokens::comply_token(std::size_t& current, std::size_t& now_statement_start, std::string_view file_view) {
    ++current;
    skipBlank(file_view,current, false);
    now_statement_start = current;
    --current;
    new_token();
}

Tokens::Tokens(const PreProcessFile& file) {
    std::string_view file_view = file.text;
    emplace_back().line;
    std::size_t now_statement_start = 0;
    std::stack<char> bracket_pair;
    for (std::size_t current = 0;current <= file_view.length() - 1 ;++current){
        if (now_statement_start == current) {
            //std::cout << "\n";
        }
        if (skipDoubleQuote(file_view, current)) {
            --current;
            continue;
        }
        if (skipBlank(file_view, current, false)) {
            --current;
            add_char(' ');
            continue;
        }

        if (file_view.at(current) == '(') {
            bracket_pair.push('(');
        }
        if (file_view.at(current) == ')') {
            if (!bracket_pair.empty()) {
                bracket_pair.pop();
            }
        }
        if (back().line.empty() && file_view.substr(current, sizeof("public:")-1) == "public:") {
            back().line = "public:";
            current = current + sizeof("public:") - 1;
            comply_token(current,now_statement_start,file_view);
        }
        if (back().line.empty() && file_view.substr(current, sizeof("private:")-1) == "private:") {
            back().line = "private:";
            current = current + sizeof("private:") - 1;
            comply_token(current,now_statement_start,file_view);
        }
        if (back().line.empty() && file_view.substr(current, sizeof("protected:")-1) == "protected:") {
            back().line = "protected:";
            current = current + sizeof("protected:") - 1;
            comply_token(current,now_statement_start,file_view);
        }
        add_char(file_view.at(current));
        if (file_view.at(current) == '{' || file_view.at(current) == '}' || file_view.at(current) == ';') {
            if (bracket_pair.empty()) {
                comply_token(current,now_statement_start,file_view);
                while (!bracket_pair.empty()) bracket_pair.pop();
            }
        }
    }

}

void Tokens::new_token() {
    if (!back().line.empty()) {
        back().tokenize_line();
        emplace_back().line;
    }
}

void Tokens::add_char(char add_char) {
    if (add_char == '(') {
        if (!back().line.empty() && *back().line.rbegin() != ' ') {
            back().line += ' ';
        }
    }
    if (add_char == ' ' && back().line.empty()) {
        return;
    }

    back().line += add_char;
}
} // cpptg