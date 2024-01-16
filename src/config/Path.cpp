#include "Path.hpp"
#include <utility>
#include <string>
namespace cpptg {
Path::Path(std::filesystem::path config, nlohmann::json json)
  : config_path(std::move(config)),
    output_path(json["output"].get<std::string>()),
    target_path(json["target"].get<std::string>()) {}
} // cpptg