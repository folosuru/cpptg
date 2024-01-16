#ifndef CPPTG_PATH_HPP
#define CPPTG_PATH_HPP
#include <filesystem>
#include <json.hpp>
namespace cpptg {

struct Path {
    explicit Path(std::filesystem::path config, nlohmann::json json);

    std::filesystem::path config_path;

    std::filesystem::path target_path;

    std::filesystem::path output_path;
};

} // cpptg
#endif // CPPTG_PATH_HPP
