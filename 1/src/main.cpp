#include <bits/stdc++.h>

int main() {
    std::ifstream input("resources/input.txt");
    if (!input.is_open()) {
        std::cerr << "Error: Could not open resources/input.txt" << std::endl;
        return 1;
    }

    int x = 50; 
    int count = 0; 
    std::string line;

    while (std::getline(input, line)) {
        char direction = line[0];
        int amount = std::stoi(&line[1]); 
        int remainder = amount;

        if (direction == 'L') {
            while (remainder > 0) {
                int distanceToZero = (x == 0) ? 100 : x;

                if (remainder >= distanceToZero) {
                    count++;
                    remainder -= distanceToZero;
                    x = 0; 
                } else {
                    x = (x == 0) ? (100 - remainder) : (x - remainder);
                    remainder = 0;
                }
            }
        } else {
            while (remainder > 0) {
                int distanceToZero = (x == 0) ? 100 : (100 - x);

                if (remainder >= distanceToZero) {
                    count++;
                    remainder -= distanceToZero;
                    x = 0;
                } else {
                    x += remainder;
                    remainder = 0;
                }
            }
        }
    }

    input.close();
    std::cout << count << std::endl;
    return 0;
}