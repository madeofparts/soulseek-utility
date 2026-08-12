#include "ConfigManager.h"

ConfigManager::ConfigManager() {}

ConfigManager& ConfigManager::getInstance() {
  static ConfigManager instance;
  return instance;
}


