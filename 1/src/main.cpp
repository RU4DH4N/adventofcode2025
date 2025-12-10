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
        int sign = (line[0] == 'R') ? 1 : -1;
        int amount = std::stoi(&line[1]);
        int remainder = amount;

        while (remainder > 0) {
            int dist;
            if (x == 0) {
                dist = 100; 
            } else {
                dist = (sign == 1) ? (100 - x) : x;
            }

            if (remainder >= dist) {
                count++;
                remainder -= dist;
                x = 0;
            } else {
                x += sign * remainder;            
                if (x < 0) x += 100;
                
                remainder = 0;
            }
        }
    }

    input.close();
    std::cout << count << std::endl;
    return 0;
}