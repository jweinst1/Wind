#include <iostream>
#include "WindObject.h"
#include "WindStream.h"
#include "WindInt.h"

int main(int argc, char const *argv[]) {
        WindNone* foo = new WindNone[1];
        WindStream stream;
        stream << foo;
        stream << WindInt::create(7);
        stream.removeFront();
        std::cout << "Hello\n";

        return 0;
}
