#include <iostream>
#include <string>
#include <vector>

class Djak {
private:
    // Privatni atributi - dostupni samo unutar klase
    std::string ime;
    std::string prezime;
    int razred;
    std::vector<int> ocene;
    //double prosek;
/*
    // Privatna pomoćna metoda za računanje proseka
    void izracunajProsek() {
        if (ocene.empty()) {
            prosek = 0.0;
            return;
        }
        double suma = 0;
        for (int ocena : ocene) {
            suma += ocena;
        }
        prosek = suma / ocene.size();
    } */

public:
    // Konstruktor - postavlja početne vrednosti
    /* Klasičan način (unutar zagrada): 
    Kompajler prvo napravi promenljive razred i prosek sa nasumičnim vrednostima iz memorije, 
    pa tek onda ulazi u telo konstruktora i naknadno im dodeljuje vrednosti 0 i 0.0. 
    To su praktično dva koraka.*/
    
    Djak() {
    razred = 0;
}

    // Metoda za unos podataka
    void unos() {
        std::cout << "Unesite ime djaka: ";        std::cin >> ime;
        std::cout << "Unesite prezime djaka: ";        std::cin >> prezime;
        std::cout << "Unesite razred: ";        std::cin >> razred;
        int brojOcena;        std::cout << "Koliko ocena zelite da unesete? ";        std::cin >> brojOcena;
        
        ocene.resize(brojOcena);
        for (int i = 0; i < brojOcena; i++) {            std::cin >> ocene[i];        }

    }

    // Metoda za ispis podataka (const označava da metoda ne menja objekat)
    void ispis() const {
        std::cout << "\n===== PODACI O DJAKU (KLASA) =====\n";
        std::cout << "Ime i prezime: " << ime << " " << prezime << "\n";
        std::cout << "Razred: " << razred << "\n";
        
        std::cout << "Ocene: ";
        for (int ocena : ocene) {
            std::cout << ocena << " ";
        }

    }
};

int main() {
    // Pravljenje objekta klase Djak
    Djak ucenik;

    // Pozivanje metoda nad objektom
    ucenik.unos();
    ucenik.ispis();

    //ucenik.ime = "Neko_Drugo_Ime"; // NE Menjamo ime bez ikakve kontrole

    return 0;
}
