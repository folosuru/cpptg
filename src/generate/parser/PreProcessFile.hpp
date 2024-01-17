#ifndef CPPTG_PREPROCESS_HPP
#define CPPTG_PREPROCESS_HPP
#include <string>
#include <filesystem>
namespace cpptg {
class PreProcessFile {
public:
    std::string text;
    explicit PreProcessFile(const std::filesystem::path& file_path);
};
}
#endif  // CPPTG_PREPROCESS_HPP
