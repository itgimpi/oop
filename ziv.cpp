#include <iostream>

struct Pas { void zvuk() { std::cout << "Av!\n"; } };
struct Macka { void zvuk() { std::cout << "Mjau!\n"; } };

// dve različite funkcije:
void zvuk(Pas& p) { p.zvuk(); }
void zvuk(Macka& m) { m.zvuk(); }

int main() {
    Pas p;
    Macka m;
    
    zvuk(p);   // Štampa: Av!
    zvuk(m); // Štampa: Mjau!
}
