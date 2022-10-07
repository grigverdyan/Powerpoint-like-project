#include <iostream>
#include <string>

void parse(std::string command){
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = command.find(delimiter)) != std::string::npos) {
        token = command.substr(0, pos);
        std::cout << token << std::endl;
        command.erase(0, pos + delimiter.length());
    }
    std::cout << command << std::endl;
}

int main()
{
    parse("a b c de d");
    return 0;
}
