#include <iostream>

class Zivotinja {
    public: 
    virtual void zvuk() { std::cout << "Neki zvuk\n"; } };

class Pas : public Zivotinja {
    void zvuk() override { std::cout << "Av!\n"; } };

class Macka : public Zivotinja {
    void zvuk() override { std::cout << "Mjau!\n"; } };

// Funkcija prima bilo koju životinju i kaže joj da pusti zvuk
void zvuk(Zivotinja &z) {
    z.zvuk(); // OVDE se dešava polimorfizam
}

int main() {
    Zivotinja z;
    Pas p;
    Macka m;

    zvuk(z);

    zvuk(p);   // Štampa: Av!
    
    zvuk(m); // Štampa: Mjau!
}
