#include <iostream>

int main(int argc, char const *argv[]) {
        int* foo = new int[1];
        foo[0] = 5;
        std::cout << *foo << "Hello World!\n";
        delete[] foo;
        return 0;
}
