#include "generate.hpp"
#include "../define.hpp"
#include "../config/Config.hpp"
#include "parser/Parser.hpp"
namespace cpptg {
void generate(const std::filesystem::path& config_file_dir) {
    Config conf{config_file_dir/config_file_name};

}
} // cpptg