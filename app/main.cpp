#include <iostream>
// #include "../include/VideoRepository.h"
#include <string>
#include "../music/include/MusicRepository.h"
int main() {
    MusicRepository repo;
    repo.populateLibrary();

    int option;
    std::string query;

    do {
        std::cout << "\nSistema de Búsqueda de Música\n";
        std::cout << "1. Buscar por título de canción\n";
        std::cout << "2. Buscar por álbum\n";
        std::cout << "3. Buscar por grupo\n";
        std::cout << "4. Buscar por género\n";
        std::cout << "0. Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> option;
        std::cin.ignore();

        if (option != 0) {
            std::cout << "Introduce el término de búsqueda: ";
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
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (option != 0);

    return 0;
}