#include <iostream>
#include "WindUnit.h"

int main(int argc, char const *argv[]) {
        char g = 'h';
        WindUnit<char> f(g);
        std::cout << f.getData()[0] << std::endl;
        return 0;
}
