#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

class Index
{
private:
    std::map<std::string, std::set<std::string>>* words_map;
public:
    static void normalize(std::string& str); 
    Index(); 
    Index(const std::vector<std::string>& paths);
    ~Index();
    void add_files(const std::vector<std::string>& paths);
    std::set<std::string> operator[](const std::string& key);
};








