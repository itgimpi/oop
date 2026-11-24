#include <iostream>
// Stek sa dinamickim nizom
class Stek {
private:
    class Cvor {
    public:
        int podatak;
        Cvor * sledeci;

        Cvor( int vrednost, Cvor* sled = nullptr ) {
            podatak = vrednost;
            sledeci = sled;  } };
    Cvor *vrh;
public:
    Stek() {
        vrh = nullptr;} // NULL
    bool empty(){
        return vrh == nullptr;  }
    void push(int vrednost) {
        vrh = new Cvor(vrednost, vrh);  }
    void pop() {
        if (empty()) {
            std::cout << "Stek je prazan!\n";
            return;  }
        Cvor *tmp = vrh;
        vrh = vrh->sledeci;
        delete tmp;  }
    int top(){
        if ( empty() ) {
            std::cout << "Stek je prazan!\n";
            return -1;  }
        return vrh->podatak;   }



};

int main() {
    Stek s;
    s.push(1);s.push(2);s.push(3);
    std::cout << s.top() << '\n';
    s.pop();
    std::cout << s.top() << '\n';
    s.pop();
    std::cout << s.top() << '\n';
    s.pop();
    std::cout << s.top() << '\n';
    s.pop();
    
    
    return 0;
}
