#include <iostream>
#include "WindObject.h"
#include "WindStream.h"
#include "WindInt.h"

int main(int argc, char const *argv[]) {
        WindNone* foo = new WindNone[1];
        WindStream stream;
        stream << foo;
        std::cout << "Hello\n";
        WindInt* wint = WindInt::create(8);
        std::cout << wint->getInt() << std::endl;
        delete[] wint;
        return 0;
}
