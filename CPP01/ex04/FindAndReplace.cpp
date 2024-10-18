
#include "FindAndReplace.hpp"

FindAndReplace::FindAndReplace(std::string in_file, std::string find_str, std::string replace_with)
    : _input_file(in_file), _to_replace(find_str), _replacement(replace_with)
{
    this->_output_file = _input_file + ".replace";
};

void FindAndReplace::replace_in_line(std::string &line)
{
    size_t position = 0;
    size_t _to_replace_length = this->_to_replace.length();

    while ((position = line.find(this->_to_replace, position)) != std::string::npos)
    {
        line.erase(position, _to_replace_length);
        line.insert(position, this->_replacement);
        std::cout << "Pos " << position << std::endl;
        position += this->_replacement.length();
    }
};

void FindAndReplace::process_file(std::ifstream &infile, std::ofstream &outfile)
{
    std::string line;
    while (std::getline(infile, line))
    {
        if (!infile.eof())
            line += "\n";
        std::cout << "Before " << line << std::endl;
        replace_in_line(line);
        std::cout << "After " << line << std::endl;
        outfile << line;
    }
};

void FindAndReplace::find_and_replace()
{
    std::ifstream infile(this->_input_file);
    std::ofstream outfile(this->_output_file);

    if (infile.fail())
        std::cerr << "Failed to open file: " << this->_input_file << std::endl;
    if (outfile.fail())
        std::cerr << "Failed to create file: " << this->_output_file << std::endl;
    if (infile && outfile)
        process_file(infile, outfile);
};