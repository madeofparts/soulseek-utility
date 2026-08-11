#include <iostream>
#include <filesystem>
#include <string>
#include <format>

namespace fs = std::filesystem;

// TODO: automatically insert / at start if missing
std::string get_input_file_path() {
  fs::path my_path;

  while (!fs::exists(my_path)) {
    std::string input;
    std::cout << "Select downloads directory: ";
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
  get_input_file_path();  
  return 0;
}

