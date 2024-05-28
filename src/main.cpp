#include <iostream>
#include "Index.h"
#include <filesystem>
#include <chrono>

std::set<std::string> brute_search(const std::string& key, const std::vector<std::string>& paths)
{
    std::set<std::string> found_docs; 
    std::string word;
    for(const auto& path: paths)
    {
        std::ifstream file(path);
        while(std::getline(file, word, ' '))
        {
            Index::normalize(word);
            if(word == key)
            {
                found_docs.insert(path);
                continue;
            }
        }
    }
    return found_docs;
}

int main(int, char**){
    Index index_instance;
    std::string folder_path = "C:/Programming/Lab8_alg-main/docs";
    std::vector<std::string> file_paths;
    std::string keyword = "the";
    for(const auto & entry : std::filesystem::directory_iterator(folder_path))
    {
        file_paths.push_back(std::string(entry.path().string()));
    }
    index_instance.add_files(file_paths);

    // Засекаем время для операции Index
    auto start_index = std::chrono::high_resolution_clock::now();
    for(const auto& doc: index_instance[keyword])
    {
        std::cout << keyword << " Contained in:  " << doc << std::endl;
        std::cout << std::endl;
    }
    auto end_index = std::chrono::high_resolution_clock::now();
    auto duration_index = std::chrono::duration_cast<std::chrono::nanoseconds>(end_index - start_index);
    std::cout << "Время выполнения операции Index: " << duration_index.count() << " наносекунд" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Засекаем время для операции brute_search
    auto start_brute = std::chrono::high_resolution_clock::now();
    for(const auto& doc: brute_search(keyword, file_paths))
    {
        std::cout << keyword << " Contained in:  " << doc << std::endl;
        std::cout << std::endl;
    }
    auto end_brute = std::chrono::high_resolution_clock::now();
    auto duration_brute = std::chrono::duration_cast<std::chrono::nanoseconds>(end_brute - start_brute);
    std::cout << "Время выполнения операции brute_search: " << duration_brute.count() << " наносекунд" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}