#pragma once
#include <string>
#include <unordered_map>
#include <any>

struct Metadata {
    std::unordered_map<std::string, std::any> data;
};