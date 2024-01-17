#ifndef CPPTG_PATH_HPP
#define CPPTG_PATH_HPP
#include <filesystem>
#include <vector>
#include "OutputConfig.hpp"
#include <json.hpp>
#include <optional>

namespace cpptg {

class Path {
public:
    explicit Path(const std::filesystem::path& base_path, nlohmann::json json);

    [[nodiscard]]
    std::filesystem::path output_to(const std::filesystem::path& file) const;

    const std::filesystem::path target_path;
private:
    std::optional<std::filesystem::path> output_path;

};

} // cpptg
#endif // CPPTG_PATH_HPP
