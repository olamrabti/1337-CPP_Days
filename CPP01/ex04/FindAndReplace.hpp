#ifndef FIND_AND_REPLACE_HPP
#define FIND_AND_REPLACE_HPP

#define SUCCESS 0
#define FAILURE 1

#include <iostream>
#include <fstream>
#include <string>

class FindAndReplace
{
private:
    std::string _input_file;
    std::string _output_file;
    std::string _to_replace;
    std::string _replacement;

public:
    FindAndReplace(std::string in_file, std::string find_str, std::string replace_with);
    void process_file(std::ifstream &infile, std::ofstream &outfile);
    void replace_in_line(std::string &line);
    void find_and_replace();
};

#endif