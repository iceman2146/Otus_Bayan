#include "bayan.h"

#include <iostream>
#include <vector>
#include <string>

#include <boost/program_options.hpp>

/**
 * @file main.cpp
 *
 */

/**
 * @brief ??????? main
 * ???????? ??????? main
 * @return ?????????? ??? ??????
 */

int main(int argc, char **argv)
{
    setlocale(LC_CTYPE, "rus");

    std::vector<std::string> input_paths_list,exclude_paths_list;
    std::size_t level, size_minimal, block_size;
    boost::program_options::options_description opt_deskription("��������� ��������� ��������� ������");
    opt_deskription.add_options()     ("include-path,i", boost::program_options::value<std::vector<std::string>>(),                          "���������� ��� ������������")
                                      ("exclude-path,e", boost::program_options::value<std::vector<std::string>>(),                          "���������� ��� ���������� �� ������������ ")
                                      ("mask,m",         boost::program_options::value<std::string>(),                                       "����� ���� ������ ����������� ��� ���������")
                                      ("level,l",        boost::program_options::value<std::size_t>(&level)->default_value(0),          "������� ������������(1 ��� ���������) ")
                                      ("min-size,s",     boost::program_options::value<std::size_t>(&size_minimal)->default_value(1),   "����������� ������ �����")
                                      ("block-size,b",   boost::program_options::value<std::size_t>(&block_size)->default_value(1),     "������ �����, ������� ������������ ������ ������")
                                      ("hash",           boost::program_options::value<std::string>(),                                       "���� �� ��������� ���������� �����������")
                                      ("help,h", "�������");

    boost::program_options::variables_map options_map;

        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, opt_deskription), options_map);
        boost::program_options::notify(options_map);

        if (options_map.count("help"))
        {
            std::cout << opt_deskription << "\n";
            return 1;
        }

        if (options_map.count("include-path"))
        {
            input_paths_list = options_map["include-path"].as<std::vector<std::string>>();
        }

        if (options_map.count("exclude-path"))
        {
           exclude_paths_list = options_map["exclude-path"].as<std::vector<std::string>>();
        }
    
    bayan bayan;
    bayan.run(input_paths_list,exclude_paths_list, level);
    return 0;
}