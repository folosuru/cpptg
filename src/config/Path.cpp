#include "Path.hpp"
#include <utility>
#include <string>
namespace cpptg {
Path::Path(const std::filesystem::path& base_path, nlohmann::json json)
  : target_path(base_path / json["target"].get<std::string>()) {
    if (json.contains("output")) {
        output_path = base_path / json["output"].get<std::string>();
    }  else {
        output_path == std::nullopt;
    }
}

std::filesystem::path Path::output_to(const std::filesystem::path& file) const {
    if (output_path) {
        return output_path.value() / std::filesystem::relative(file, target_path);
    } else {
        return file.parent_path();
    }
}
} // cpptg