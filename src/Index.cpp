#include "Index.h"

void Index::normalize(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), [](const char& c) {return !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')); }), str.end());
    for(char& c: str)
    {
        c = std::tolower(c);
    }
}

Index::Index()
{
    words_map = new std::map<std::string, std::set<std::string>>;
}

Index::Index(const std::vector<std::string>& paths)
{
    words_map = new std::map<std::string, std::set<std::string>>;
    for(std::string path: paths)
    {
        std::string word;
        std::ifstream file(path);
        while(std::getline(file, word, ' '))
        {
            normalize(word);
            words_map[0][word].insert(path);
        }
        file.close();
    }
}
Index::~Index()
{
    delete words_map; 
}

void Index::add_files(const std::vector<std::string>& paths)
{
    for(std::string path: paths)
    {
        std::string word;
        std::ifstream file;
        file.open(path);
        while(std::getline(file, word, ' '))
        {
            normalize(word);
            if(word != "")
            words_map[0][word].insert(path);
        }
        file.close();
    }
}

std::set<std::string> Index::operator[](const std::string& key)
{
    return words_map[0][key];
}