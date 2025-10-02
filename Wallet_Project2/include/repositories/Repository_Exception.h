#pragma once
#include <stdexcept>
#include <string>

class RepositoryException : public std::runtime_error {
public:
    RepositoryException(std::string msg) : std::runtime_error(msg) {}
};
