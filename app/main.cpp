#include <iostream>
#include <string>
#include "VideoRepository.h"
#include "MusicRepository.h"

// Muestra el menú de vídeo
void showVideoMenu() {
    std::cout << "==== Video Menu ====\n";
    std::cout << "1. List all titles\n";
    std::cout << "2. Search by title\n";
    std::cout << "3. Search by genre\n";
    std::cout << "4. Search by quality\n";
    std::cout << "5. Rent a title\n";
    std::cout << "0. Back to main menu\n";
}

// Muestra el menú de música
void showMusicMenu() {
    std::cout << "==== Music Menu ====\n";
    std::cout << "1. Search by song title\n";
    std::cout << "2. Search by album\n";
    std::cout << "3. Search by group\n";
    std::cout << "4. Search by genre\n";
    std::cout << "0. Back to main menu\n";
}

int main() {
    // Repositorios
    VideoRepository videoRepo;
    MusicRepository musicRepo;

    // Cargar datos iniciales
    videoRepo.seed();
    musicRepo.populateLibrary();

    int mainOption = -1;

    while (mainOption != 0) {
        std::cout << "\n==== Main Menu ====\n";
        std::cout << "1. Video repository\n";
        std::cout << "2. Music repository\n";
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
                    // List all titles
                    std::cout << "\nListing all titles:\n";
                    auto allTitles = videoRepo.findByTitle("");
                    for (std::size_t i = 0; i < allTitles.size(); ++i) {
                        std::cout << allTitles[i].getName()
                                  << " | " << allTitles[i].getGenre() << "\n";
                    }
                } else if (videoOption == 2) {
                    // Search by title
                    std::string query;
                    std::cout << "Enter title: ";
                    std::cin.ignore();
                    std::getline(std::cin, query);

                    auto results = videoRepo.findByTitle(query);
                    for (std::size_t i = 0; i < results.size(); ++i) {
                        std::cout << results[i].getName()
                                  << " | " << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 3) {
                    // Search by genre
                    std::string genre;
                    std::cout << "Enter genre: ";
                    std::cin.ignore();
                    std::getline(std::cin, genre);

                    auto results = videoRepo.findByGenre(genre);
                    for (std::size_t i = 0; i < results.size(); ++i) {
                        std::cout << results[i].getName()
                                  << " | " << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 4) {
                    // Search by quality
                    int q;
                    std::cout << "Enter quality (0 = FullHD, 1 = UHD): ";
                    std::cin >> q;

                    auto results = videoRepo.findByQuality(static_cast<Quality>(q));
                    for (std::size_t i = 0; i < results.size(); ++i) {
                        std::cout << results[i].getName()
                                  << " | " << results[i].getGenre() << "\n";
                    }
                } else if (videoOption == 5) {
                    // Rent a title
                    std::string title;
                    std::cout << "Enter title to rent: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);

                    if (videoRepo.rentByTitle(title)) {
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

                if (musicOption >= 1 && musicOption <= 4) {
                    std::string query;
                    std::cout << "Enter search text: ";
                    std::cin.ignore();
                    std::getline(std::cin, query);

                    if (musicOption == 1) {
                        musicRepo.searchBySongTitle(query);
                    } else if (musicOption == 2) {
                        musicRepo.searchByAlbum(query);
                    } else if (musicOption == 3) {
                        musicRepo.searchByGroup(query);
                    } else if (musicOption == 4) {
                        musicRepo.searchByGenre(query);
                    }
                }
            }
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}