#include <iostream>
#include <string>
#include "VideoRepository.h"
#include "MusicRepository.h"

void showVideoMenu() {
    std::cout << "==== Video Menu ====\n";
    std::cout << "1. List all titles\n";
    std::cout << "2. Search by title\n";
    std::cout << "3. Search by genre\n";
    std::cout << "4. Search by quality\n";
    std::cout << "5. Rent a title\n";
    std::cout << "0. Back to main menu\n";bomba
}

void showMusicMenu() {
    std::cout << "==== Music Menu ====\n";
    std::cout << "1. List all songs\n";
    std::cout << "2. Search by album\n";
    std::cout << "3. Search by group\n";
    std::cout << "4. Search by genre\n";
    std::cout << "0. Back to main menu\n";
}

int main() {
    // Creamos los objetos almacenandolos en la Free Store
    VideoRepository *videoRepo = new VideoRepository();
    MusicRepository *musicRepo = new MusicRepository();

    // Cargar datos de ejemplo
    videoRepo->seed();
    musicRepo->populateLibrary();

    int mainOption = -1;
    // Generamos un menú
    while (mainOption != 0) {
        std::cout << "\n==== Main Menu ====\n";
        std::cout << "1. Video Repository\n";
        std::cout << "2. Music Repository\n";
        std::cout << "0. Exit\n";
        std::cout << "Select option: ";
        std::cin >> mainOption;

        if (mainOption == 1) {
            int videoOption = -1;
            while (videoOption != 0) {
                showVideoMenu();
                std::cout << "Select option: ";
                std::cin >> videoOption;

                if (videoOption == 1) {
                    auto allTitles = videoRepo->findByTitle(""); // "" devuelve todos
                    for (size_t i = 0; i < allTitles.size(); i++) {
                        std::cout << allTitles[i].getName() << " | "
                                << allTitles[i].getGenre() << "\n";
                    }
                } else if (videoOption == 2) {
                    std::string query;
                    std::cout << "Enter title: ";
                    std::getline(std::cin, query);
                    auto results = videoRepo->findByTitle(query);
                    for (size_t i = 0; i < results.size(); i++) {
                        std::cout << results[i].getName() << " | "
                                << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 3) {
                    std::string genre;
                    std::cout << "Enter genre: ";
                    std::getline(std::cin, genre);
                    auto results = videoRepo->findByGenre(genre);
                    for (size_t i = 0; i < results.size(); i++) {
                        std::cout << results[i].getName() << " | "
                                << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 4) {
                    int q;
                    std::cout << "Enter quality (0 = FHD, 1 = UHD): ";
                    std::cin >> q;
                    auto results = videoRepo->findByQuality(static_cast<Quality>(q));
                    for (size_t i = 0; i < results.size(); i++) {
                        std::cout << results[i].getName() << " | "
                                << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 5) {
                    std::string title;
                    std::cout << "Enter title to rent: ";
                    std::getline(std::cin, title);
                    if (videoRepo->rentByTitle(title)) {
                        std::cout << "Title rented successfully.\n";
                    } else {
                        std::cout << "Cannot rent title (not available or not found).\n";
                    }
                }
            }
        } else if (mainOption == 2) {
            int musicOption = -1;
            while (musicOption != 0) {
                showMusicMenu();
                std::cout << "Select option: ";
                std::cin >> musicOption;

                if (musicOption == 1) {
                    std::string query;
                    std::cout << "Enter song title: ";
                    std::getline(std::cin, query);
                    musicRepo->searchBySongTitle(query);
                } else if (musicOption == 2) {
                    std::string query;
                    std::cout << "Enter album title: ";
                    std::getline(std::cin, query);
                    musicRepo->searchByAlbum(query);
                } else if (musicOption == 3) {
                    std::string query;
                    std::cout << "Enter group name: ";
                    std::getline(std::cin, query);
                    musicRepo->searchByGroup(query);
                } else if (musicOption == 4) {
                    std::string query;
                    std::cout << "Enter genre: ";
                    std::getline(std::cin, query);
                    musicRepo->searchByGenre(query);
                }
            }
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
