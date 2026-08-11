#include <cstdio>
#include <iostream>
#include <filesystem>
#include <string>
#include <format>

namespace fs = std::filesystem;

std::string get_input_file_path(std::string purpose = "") {
  fs::path my_path;

  while (!fs::exists(my_path)) {
    std::string input;
    std::string msg;

    if (purpose == "") {
      msg = "Select directory: ";
    } else {
      msg = "Select {} directory: ";
    }
    std::cout << std::vformat(msg, std::make_format_args(purpose));
    std::getline(std::cin, input);
    my_path = input;

    if (fs::exists(my_path)) {
      std::cout << std::format("Path \'{}\' exists.", my_path.string()) << std::endl;
      std::cout << std::format("Confirm path: \'{}\' (\033[32mY\033[0m/\033[31mn\033[0m): ", my_path.string());
      std::string ans;
      std::getline(std::cin, ans);
      
      std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
      if (ans == "y" || ans == "yes" || ans == "") {
        std::cout << "Confirmed." << std::endl;
      } else {
        std::cout << "Cancelled." << std::endl;
        my_path = "";
      }
    } else {
      std::cout << std::format("Path \'{}\' does not exist. Please try again.", my_path.string()) << std::endl; 
    }
  }

  return my_path;
}

int main() {
  get_input_file_path();
  get_input_file_path("test");
  return 0;
}

