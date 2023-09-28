#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
class bayan
{
private:
    static std::vector<std::string> files_list(const std::vector<std::string> &include_paths, const std::vector<std::string> &exclude_paths, std::size_t depth);

public:
    bayan() = default;
    ~bayan() = default;

    void run(const std::vector<std::string> &include_paths, const std::vector<std::string> &exclude_paths, std::size_t depth);
};
