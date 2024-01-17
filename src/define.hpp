#ifndef CPPTG_DEFINE_HPP
#define CPPTG_DEFINE_HPP
#include <string_view>
#include <array>
namespace cpptg {
inline std::string_view config_file_name = "cpptg_conf.json";

inline std::array<std::string_view, 5> header_file_ext {
    ".h",
    ".hpp",
    ".hxx",
    ".h++",
    ".hh",
};
inline std::array<std::string_view, 5> impl_file_ext {
    ".c",
    ".cpp",
    ".cxx",
    ".c++",
    ".cc",
};
}
#endif //CPPTG_DEFINE_HPP
