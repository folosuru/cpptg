#include "initial.hpp"
#include <fstream>
#include <json.hpp>

#include "../define.hpp"

void cpptg::create_config(std::filesystem::path path) {
    nlohmann::json data;
    data = {
        {"root", "./"},
        {"target", {
                {
                    {"target", "src/"}
                },
                {
                    {"target", "include/"},
                    {"output", "test/"}
                }
            }
        }
    };
    std::ofstream(path / config_file_name) << std::setw(4) << data << std::endl;
}
