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
        int amount = std::stoi(line.substr(1));
        
        if (direction == 'L') {
            x = (x + amount) % 100;
        } else {
            x = (x - amount) % 100;
        }
        
        if (x == 0) ++count;
    }
    
    input.close();
    std::cout << count << std::endl;
    
    return 0;
}