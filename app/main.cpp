#include <iostream>
#include <string>
#include "MusicRepository.h"

int main() {
    MusicRepository repo;
    repo.populateLibrary();

    int option{};
    std::string query;

    do {
        std::cout << "\nMusic Search System\n";
        std::cout << "1. Search by song title\n";
        std::cout << "2. Search by album\n";
        std::cout << "3. Search by group\n";
        std::cout << "4. Search by genre\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cin.ignore();

        if (option != 0) {
            std::cout << "Enter your search term: ";
            std::getline(std::cin, query);
        }

        switch (option) {
            case 1:
                repo.searchBySongTitle(query);
                break;
            case 2:
                repo.searchByAlbum(query);
                break;
            case 3:
                repo.searchByGroup(query);
                break;
            case 4:
                repo.searchByGenre(query);
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (option != 0);

    return 0;
}