#include <iostream>
#include "WindObject.h"
#include "WindStream.h"

int main(int argc, char const *argv[]) {
        WindNone* foo = new WindNone[1];
        WindStream stream;
        stream << foo;
        std::cout << "Hello\n";
        return 0;
}
