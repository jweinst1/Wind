#include <iostream>
#include "WindUnit.h"

int main(int argc, char const *argv[]) {
        char g = 'h';
        WindUnit<char> f(g);
        WindUnit<char> a(g);
        f.setNext(&a);
        std::cout << f.getData()[0] << std::endl;
        std::cout << f.hasNext() << std::endl;
        f.debugInfo();
        return 0;
}
