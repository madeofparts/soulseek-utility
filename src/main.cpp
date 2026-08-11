#include <iostream>
#include <filesystem>
#include <string>
#include <format>

namespace fs = std::filesystem;

// TODO: 
// - automatically insert / at start if missing
// - add confirm message
std::string get_input_file_path(std::string purpose) {
  fs::path my_path; //

  while (!fs::exists(my_path)) {
    std::string input;
    std::cout << std::format("Select {} directory: ", purpose);
    std::getline(std::cin, input);
    my_path = input;

    if (fs::exists(my_path)) {
      std::cout << std::format("Path \'{}\' exists.", my_path.string()) << std::endl;
    } else {
      std::cout << std::format("Path \'{}\' does not exist. Please try again.", my_path.string()) << std::endl; 
    }
  }

  return my_path;
}

int main() {
  get_input_file_path("test");  
  return 0;
}

