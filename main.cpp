#include <iostream>
#include "Gauss.cpp"

int main() {
    std::vector<std::vector<float>> A = {
        {2, 1},
        {1, 3}
    };

    std::vector<float> b = {5, 6};

    Gauss g(A, b);
    g.iterar();

    std::vector<float> sol = g.get_solucao();

    std::cout << "Solucao:\n";
    for (size_t i = 0; i < sol.size(); i++) {
        std::cout << "x" << i << " = " << sol[i] << '\n';
    }

    return 0;
}
