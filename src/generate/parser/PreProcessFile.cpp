#include "PreProcessFile.hpp"
#include <fstream>
cpptg::PreProcessFile::PreProcessFile(const std::filesystem::path& file_path) {
    auto file = std::ifstream(file_path);
    std::string buf;
    std::string file_data;
    while (std::getline(file,buf)) {
        if (buf.starts_with("#")) {
            while (buf.ends_with('\\')) {
                std::getline(file,buf);
            }
            continue;
        }
        file_data += buf + "\n";
    }
    this->text = file_data;
}
