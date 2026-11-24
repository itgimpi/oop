#include <iostream>
#include <string>

class Par {
public:
    std::string prvi;
    int drugi;
    Par() : prvi(""), drugi(0){}
    Par(std::string p, int d) : prvi(p), drugi(d) {}
};

int main() {
    Par p1;
    std::cout << p1.prvi << ' ' << p1.drugi << '\n';

    p1.prvi = "qwerty"; p1.drugi = 1;
    std::cout << p1.prvi << ' ' << p1.drugi << '\n';

    Par p2("dva", 2);
    std::cout << p2.prvi << ' ' << p2.drugi << '\n';
    
    return 0;
}
