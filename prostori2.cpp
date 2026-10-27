#include <iostream>

// prvi imenski prostor
namespace p1 {
    void ispis() {
        std::cout << 1 << '\n';
    } }

// drugi imenski prostor
namespace p2 {
        void ispis() {
        std::cout << 2 << '\n';
    } }

int main() {
    // Pristupamo promenljivama pomoću operatora '::'
    p1::ispis();
    p2::ispis();

    return 0;
}
