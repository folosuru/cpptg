#include "Config.hpp"
#include <fstream>
namespace cpptg {
Config::Config(const std::filesystem::path& conf) {
    auto data = nlohmann::json::parse(std::ifstream(conf));
    root = data["root"].get<std::filesystem::path>();
    for (const auto& i : data["target"]) {
        pathes.emplace_back(root, i);
    }
}
} // cpptg