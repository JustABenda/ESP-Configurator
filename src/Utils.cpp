#include "Utils.hpp"

std::vector<std::string>  Utilities::tokenize(std::string const &str, const char delim)
{
    std::vector<std::string> out;
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out;
}