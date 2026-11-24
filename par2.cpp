#include <iostream>
#include <string>
#include <utility>


int main() {
    std::pair<int, std::string>p1(123,"qwerty");
    std::cout << p1.second;

    
    return 0;
}
