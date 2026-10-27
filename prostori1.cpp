#include <iostream>

// prvi imenski prostor
namespace p1 {
    int x = 1; }

// drugi imenski prostor
namespace p2 {
    int x = 2; }

int main() {
    // Pristupamo promenljivama pomoću operatora '::'
    std::cout << p1::x << std::endl;
    std::cout << p2::x << std::endl;

    return 0;
}
