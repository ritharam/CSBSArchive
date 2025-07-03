#include <iostream>
// #define CSE 1
// #define ECE 2
// #define MECH 3
#define DEPARTMENT CSE

int main() {
    #ifdef DEPARTMENT
    #if DEPARTMENT == CSE || DEPARTMENT == ECE
        const bool is_eligible = true;
    #else
        const bool is_eligible = false;
    #endif
    #else
        const bool is_eligible = false;
    #endif

    std::cout << "The candidate is" << (is_eligible ? " " : " not ") << "eligible." << std::endl;

    return 0;
}