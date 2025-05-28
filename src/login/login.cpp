#include "login.hpp"
bool askEraseCMD() {
    char input{};
    while (true) {
        std::cout << "Clear slash commands? (y/n): ";
        std::cin >> input;

        if (input == 'y' || input == 'Y') return true;
        if (input == 'n' || input == 'N') return false;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
}

uint64_t askGuildID() {
    uint64_t id{};
    while (true) {
        std::cout << "Enter Guild ID: ";
        std::cin >> id;

        if (!std::cin.fail() && id != 0) return id;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Guild ID. Try again.\n";
    }
}

std::string askToken() {
    std::string token;
    std::cout << "Enter Bot Token: ";
    std::cin >> token;
    return token;
}
