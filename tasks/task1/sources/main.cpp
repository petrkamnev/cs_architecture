#include <stdlib.h>
#include <iostream>

#include "container.h"
#include "generator.h"
//------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    container c;
    if (!std::strcmp(argv[1], "-r")) {
        std::ofstream generatedInput("randInput");
        int n = std::atoi(argv[2]);
        generate_input_file(n, generatedInput);
        generatedInput.close();
        std::ifstream input("randInput");

        input_container(c, input);
    } else {
        std::ifstream input(argv[2]);
        container c;
        input_container(c, input);
    }
    std::ofstream output1(argv[3]);
    print_container(c, output1);
    sort_container(c);
    std::ofstream output2(argv[4]);
    print_container(c, output2);
}
