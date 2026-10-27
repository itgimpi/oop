#include <iostream>
#include <iomanip>
#include <string>

class Vreme {
public:
    int sat;
    int minut;

    // Помоћна метода за нормализацију времена (нпр. 25:61 постаје 02:01)
    void sredi() {
        if (minut >= 60) {
            sat += minut / 60;
            minut %= 60;         } 

        else if (minut < 0) {
            // Руковање негативним минутима у случају одузимања
            int satiManje = (-minut / 60) + 1;
            sat -= satiManje;
            minut = 60 + (minut % 60);         }

        sat %= 24;
        if (sat < 0) sat += 24;     }


    // Конструктор
    Vreme(int s = 0, int m = 0) : sat(s), minut(m) {
        sredi();     }




    // Приказ у 24-часовном формату (нпр. 22:34)
    void ispis24() const {
        std::cout << std::setfill('0') << std::setw(2) << sat << ":"
                  << std::setfill('0') << std::setw(2) << minut << std::endl;
    }

    // Приказ у 12-часовном формату (нпр. 10:34 PM)
    void ispis12() const {
        int s12 = sat % 12;
        if (s12 == 0) s12 = 12;
        std::string period = (sat < 12) ? "AM" : "PM";
        
        std::cout << std::setfill('0') << std::setw(2) << s12 << ":"
                  << std::setfill('0') << std::setw(2) << minut << " " << period << std::endl;
    }

    // Додавање минута (враћа ново време)
    Vreme dodajMinute(int m) const {
        return Vreme(sat, minut + m);     }

    Vreme oduzmiMinute(int m) const {
        return Vreme(sat, minut - m);     }

    // Упоређивање два времена
    // Враћа: -1 ако је тренутно време мање, 0 ако су једнака, 1 ако је тренутно веће
    int uporedi(const Vreme& drugo) const {
        int t1 = sat * 60 + minut;
        int t2 = drugo.sat * 60 + drugo.minut;
        
        if (t1 < t2) return -1;
        if (t1 > t2) return 1;
        return 0;     }
};


int main() {
    // Тестирање прве верзије
    Vreme v1(22, 34);
    std::cout << "V1 - 24h format: "; v1.ispis24();
    std::cout << "V1 - 12h format: "; v1.ispis12();

    Vreme v2 = v1.dodajMinute(90); // 22:34 + 1h 30min = 00:04 следећег дана
    std::cout << "V1 posle 90 min: "; v2.ispis24();

    v2 = v1.oduzmiMinute(90); // 22:34 + 1h 30min = 00:04 следећег дана
    std::cout << "V1 pre 90 min: "; v2.ispis24();




    // Тестирање друге верзије
    //VremeUkupnoMinuta v3(22, 34);
    //VremeUkupnoMinuta v4(10, 15);
    
    //std::cout << "\nUsporedba V3 i V4: " << v3.uporedi(v4) << " (1 znaci da je V3 vece)";
    
    return 0;
}