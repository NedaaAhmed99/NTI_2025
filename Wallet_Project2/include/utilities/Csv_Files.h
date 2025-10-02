#pragma once
#include<string>
#include<vector>
#include<stdexcept>
#include<map>

class bad_file_formate :public std::logic_error
{
    bad_file_formate(const char* err):std::logic_error{err}
    {
        
    }
};
class CSVRow
{
    private:
    std::map <std::string, std::string> m_rowData; //row
    public:
    std::string& operator[](const std::string& column);
    const std::string& operator[] (const std::string& column)const;
    
    void InsertValue(const std::string& column, const std::string& value);
};
class CSVFile
{
private:
    std::vector<CSVRow> m_data; //file of rows
    std::vector<std::string> m_headers; 
public:
CSVFile();
CSVFile(std::vector<std::string> headers);

CSVRow& operator[](int index);
const CSVRow& operator[](int index)const;
std::vector<std::string> GetHeaders()const;
size_t GetNumberOfRows()const;
void DeleteRow(int index);
void AppendRow(CSVRow row);
void InsertRow(CSVRow row, int index);
void Print();  //printfile
};

class CSVReader
{
public:
static CSVFile ReadFile(const std::string& path);
};

class CSVWriter
{
    public:
    static void WriteFile(const std::string& path, const CSVFile& file);
};




