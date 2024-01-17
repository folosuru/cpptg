#include <iostream>
#include <fstream>
#include "config/initial.hpp"
#include "config/Path.hpp"
#include "generate/generate.hpp"
#include "generate/parser/Parser.hpp"
namespace cpptg {
void test();
}
int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    /* cpptg::test();
    return 0;*/
    if (argc == 1) {
    std::cout << cpptg::parse(R"(C:\Users\folosuru\llbds\tes-money\lib\SQLiteCpp\src\Database.cpp)") << std::endl;
        return 0;
    }
    if (std::string_view("init") == argv[1]) {
        if (argc == 2) {
            cpptg::create_config("./");
        } else if (argc == 3) {
            cpptg::create_config(argv[2]);
        } else {
            std::cout << "invaild agrument" << std::endl;
        }
        return 0;
    }
    if (std::string_view("run") == argv[1]) {
        if (argc == 2) {
            cpptg::generate("./");
        } else if (argc == 3) {
            cpptg::generate(argv[2]);
        } else {
            std::cout << "invaild agrument" << std::endl;
        }
        return 0;
    }
    if (std::string_view("parse") == argv[1]) {
        if (argc == 2) {
            std::cout << cpptg::parse("./main.cpp") << std::endl;
        } else if (argc == 3) {
            std::cout << cpptg::parse(argv[2]) << std::endl;
        } else {
            std::cout << "invaild agrument" << std::endl;
        }
        return 0;
    }
    return 0;
}
