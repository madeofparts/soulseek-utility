#pragma once

class ConfigManager {
  private:
    ConfigManager();

  public:
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;
    // Move operator implicitly not generated since copy operator is provided. (C++11)
    static ConfigManager& getInstance();
};
