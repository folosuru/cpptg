#ifndef CPPTG_CONFIG_HPP
#define CPPTG_CONFIG_HPP
#include <filesystem>
#include <vector>

#include "Path.hpp"

namespace cpptg {

class Config {
public:
    explicit Config(const std::filesystem::path&);

    const std::vector<Path>& get_path() {
        return pathes;
    }

private:
    std::vector<Path> pathes;
    std::filesystem::path root;
};

} // cpptg

#endif //CPPTG_CONFIG_HPP
