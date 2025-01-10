#include "randomline.hpp"

std::string ranl(const std::string& path){
    std::string line;
    std::ifstream inputFile(path);
    std::vector<std::string> randomline;

    if(!inputFile.is_open()){
        std::cerr << "Could not open the file!" << std::endl;
        return ""; 
    }
    while (std::getline(inputFile, line)) {
        randomline.push_back(line); // Store each line in the vector
    }
    inputFile.close();
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomIndex = std::rand() % randomline.size();
    return randomline[randomIndex];

}