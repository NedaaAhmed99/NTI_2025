#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>
#include <map>
#include "Csv_Files.h"

/*
 * The std::ios::truc flag indicates that we want
 * to overwrite the file if it already exists
 *
 * This is to make sure that we write to an empty
 * file each time
 */


std::string &CSVRow::operator[](const std::string &column)
{
    return m_rowData.at(column);
}

const std::string &CSVRow::operator[](const std::string &column) const
{
    return m_rowData.at(column);
}

void CSVRow::InsertValue(const std::string &column, const std::string &value)
{
    m_rowData[column] = value;
}

//////////////////////////////////////////////////////////////////
CSVFile::CSVFile() {}
CSVFile::CSVFile(std::vector<std::string> headers)
{
    m_headers = headers;
}

CSVRow &CSVFile::operator[](int index)
{
    return m_data[index];
}
const CSVRow &CSVFile::operator[](int index) const
{
    return m_data[index];
}
std::vector<std::string> CSVFile::GetHeaders() const
{
    return m_headers;
}
size_t CSVFile::GetNumberOfRows() const
{

    return m_data.size();
}
void CSVFile::DeleteRow(int index)
{
    m_data.erase(m_data.begin() + index); // delete any row
}
void CSVFile::AppendRow(CSVRow row)
{
    m_data.push_back(row);
}
void CSVFile::InsertRow(CSVRow row, int index)
{

    m_data.insert(m_data.begin() + index, row);
}
void CSVFile::Print() // printfile
{
    for (auto header : m_headers)
    {
        std::cout << std::setw(10) << header;
    }
    std::cout << std::endl;
    for (auto row : m_data)
    {
        for (auto header : m_headers)
        {
            std::cout << std::setw(10) << row[header];
        }
        std::cout << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////
CSVFile CSVReader::ReadFile(const std::string &path)
{
    std::ifstream filestream(path);
    if (!filestream.is_open())
        throw std::ios_base::failure{"failed to open the file"};

    std::string linestring;
    if (!std::getline(filestream, linestring))
        std::cout << "file is empety\n";
    // throw bad_file_formate{"file is empty"};

    std::istringstream linestream(linestring);
    std::vector<std::string> headers;
    std::string header;
    while (std::getline(linestream, header,','))
    {
        headers.push_back(header);
        std::cout << header << "\n";
    }
   std::cout << "Headers loaded:\n";


    CSVFile out{headers};
    for (auto &h : headers) std::cout << "[" << h << "]\n";

    std::cout << "reading headers done\n";
    while (std::getline(filestream, linestring))
    {
        std::istringstream rowstream(linestring);
        CSVRow row;
        for (size_t i = 0; i < headers.size(); i++)
        {
            std::string value;
           if (!std::getline(rowstream, value, ','))
    throw std::runtime_error{"Row does not contain all columns"};

            // throw bad_file_formate{"row does not contain all columns"};
            row.InsertValue(headers[i], value);
            std::cout << value << "\n";
        }
        out.AppendRow(row);
        std::cout << "file done \n";
    }

    return out;
}

/////////////////////////////////////////////////////////////
void CSVWriter::WriteFile(const std::string &path, const CSVFile &file)
{
    std::ofstream filestream{path, std::ios::trunc};
    if (filestream.fail())
        throw std::ios_base::failure{"failed to open the file"};

    if (filestream.bad())
        throw std::bad_exception{};

    auto headers = file.GetHeaders();
    for (size_t i=0; i < headers.size(); i++)
    {

        filestream << headers[i];
        if (i == headers.size() - 1)
            filestream << '\n';
        else
            filestream << ',';
    }

    for (size_t r=0; r < file.GetNumberOfRows(); r++)
    {
        for (size_t c=0; c < headers.size(); c++)
        {
            filestream << file[r][headers[c]];
            if (c == headers.size() - 1)
                filestream << '\n';
            else
                filestream << ',';
        }
    }

    if (filestream.fail() || filestream.bad())
        throw std::runtime_error{"error while saving the file ,maybe data corrupted"};
}
