#include "TextUtil.hpp"

#include <string_view>


class hoge {
public:
    enum class my_enum {
        a,
        foo
    };
};
hoge::my_enum foo();



namespace cpptg {
hoge :: my_enum foo() {
    return hoge::my_enum::a;
}

bool skipComment(const std::string_view& target, std::size_t& pos) {
    if (target.length() <= pos ) return false;
    if (target.at(pos) != '/') return false;
    ++pos;
    if (target.at(pos) == '*') {
        for (;target.length() > pos;++pos) {
            if (target.at(pos) == '*') {
                ++pos;
                if (target.at(pos) == '/') {
                    ++pos;
                    return true;
                }
            }
        }
        return true;
    }
    if (target.at(pos) == '/') {
        for (;target.length() > pos ;++pos) {
            if (target.at(pos) == '\n') {
                ++pos;
                return true;
            }
        }
        return true;
    }
    --pos;
    return false;
}

bool skipSpace(const std::string_view& target, std::size_t& pos, bool keep_one) {
    if (target.length() <= pos ) return false;
    if (target.at(pos) != ' ') return false;
    for (;target.length() > pos ;++pos) {
        if (target.at(pos) != ' ') {
            if (keep_one) {
            }
            return true;
        }
    }
    --pos;
    return true;
}

bool skipDoubleQuote(const std::string_view& target, std::size_t& pos) {
    if (target.length() <= pos ) return false;
    if (target.at(pos) != '\"' && target.at(pos) != '\'') {
        return {false};
    }
    if (target.at(pos) == '\'') {
        ++pos;
        if (target.at(pos) == '\\') {
            ++pos;
        }
        ++pos;
        ++pos;
        return true;
    }
    ++pos;
    for (;target.length() > pos;++pos) {
        if (target.at(pos) == '\\') {
            ++pos;
            if (target.at(pos) == '\"') {
                continue;
            }
        }
        if (target.at(pos) == '\"') {
            ++pos;
            break;
        }
    }
    return true;
}

bool skipReturning(const std::string_view& target, std::size_t& pos) {
    if (target.length() <= pos) return false;
    if (target.at(pos) != '\n' && target.at(pos) != '\r') {
        return false;
    }
    for (;target.length() > pos ;++pos) {
        if (target.at(pos) != '\n' && target.at(pos) != '\r') {
            break;
        }
    }
    return true;
}

bool skipBlank(const std::string_view& target, std::size_t& pos, bool keep_one) {
    if (!skipComment(target,pos) && !skipSpace(target,pos, keep_one) && !skipReturning(target, pos)) {
        return false;
    }
    for (std::size_t count = pos;target.length() > count; ++count) {
        if (skipSpace(target,pos, keep_one) || skipComment(target,pos) || skipReturning(target, pos)) {
            continue;
        }
        return true;
    }
    return true;
}

char getNextNotSpaceChar(const std::string_view& target, std::size_t pos) {
    while (pos < target.length()) {
        if (target.at(pos) == ' ') {
            ++pos;
            continue;
        }
        return target.at(pos);
    }
    return ' ';
}

std::string getTypename(std::string_view target, std::size_t pos) {
    "constexpr";
    "const";
    "consteval";
    "*";
}
}
