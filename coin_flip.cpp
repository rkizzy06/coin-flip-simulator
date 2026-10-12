#include <iostream>
#include <iomanip>
#include <random>
#include <limits>

int main() {
    long long n;
    std::cout << "How many flips? ";
    while (!(std::cin >> n) || n <= 0) {
        if (std::cin.eof()) return 1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a positive integer: ";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution coin(0.5);   // true = heads

    long long heads = 0;
    for (long long i = 0; i < n; ++i) {
        if (coin(gen)) ++heads;
    }
    long long tails = n - heads;

    double headsPct = 100.0 * heads / n;
    double tailsPct = 100.0 * tails / n;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Flips: " << n << '\n';
    std::cout << "Heads: " << heads << " (" << headsPct << "%)\n";
    std::cout << "Tails: " << tails << " (" << tailsPct << "%)\n";
    return 0;
}
