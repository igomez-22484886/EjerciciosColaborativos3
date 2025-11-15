#include <iostream>
#include <string>
#include <limits>           // Para numeric_limits
#include "VideoRepository.h"
#include "MusicRepository.h"

// Muestra el menú de vídeo
void showVideoMenu() {
    std::cout << "\n==== Video Menu ====\n";
    std::cout << "1. List all titles\n";
    std::cout << "2. Search by title\n";
    std::cout << "3. Search by genre\n";
    std::cout << "4. Search by quality\n";
    std::cout << "5. Rent a title\n";
    std::cout << "0. Back to main menu\n";
}

// Muestra el menú de música
void showMusicMenu() {
    std::cout << "\n==== Music Menu ====\n";
    std::cout << "1. List all songs\n";
    std::cout << "2. Search by song title\n";
    std::cout << "3. Search by album\n";
    std::cout << "4. Search by group\n";
    std::cout << "5. Search by genre\n";
    std::cout << "0. Back to main menu\n";
}

// Lee un int desde consola y validación
int readInt(const std::string& stringValue) {
    int value{};
    while (true) {
        std::cout << stringValue;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
}

// Lee una opción de menú dentro de un rango
int readMenuOption(const std::string& value, int min, int max) {
    while (true) {
        int option = readInt(value);
        if (option >= min && option <= max) {
            return option;
        }
        std::cout << "Invalid option. Try again.\n";
    }
}

int main() {
    // Repositorios
    VideoRepository videoRepo;
    MusicRepository musicRepo;

    // Cargar datos iniciales
    videoRepo.loadData();
    musicRepo.loadData();

    int mainOption = -1;

    while (mainOption != 0) {
        std::cout << "\n==== Main Menu ====\n";
        std::cout << "1. Video repository\n";
        std::cout << "2. Music repository\n";
        std::cout << "0. Exit\n";

        mainOption = readMenuOption("Select option: ", 0, 2);

        if (mainOption == 1) {
            int videoOption = -1;

            while (videoOption != 0) {
                showVideoMenu();
                videoOption = readMenuOption("Select option: ", 0, 5);

                if (videoOption == 1) {
                    std::cout << "\nListing all titles:\n";
                    auto allTitles = videoRepo.findByTitle("");

                    if (allTitles.empty()) {
                        std::cout << "No videos in repository.\n";
                    } else {
                        for (const auto& video : allTitles) {
                            std::cout << video.getName()
                                      << " | " << video.getGenre() << "\n";
                        }
                    }

                } else if (videoOption == 2) {
                    std::string query;
                    std::cout << "Enter title: ";
                    std::getline(std::cin, query);

                    auto results = videoRepo.findByTitle(query);

                    if (results.empty()) {
                        std::cout << "No titles found matching: " << query << "\n";
                    } else {
                        std::cout << "Results found:\n";
                        for (const auto& video : results) {
                            std::cout << video.getName()
                                      << " | " << video.getGenre() << "\n";
                        }
                    }

                } else if (videoOption == 3) {
                    std::string genre;
                    std::cout << "Enter genre: ";
                    std::getline(std::cin, genre);

                    auto results = videoRepo.findByGenre(genre);

                    if (results.empty()) {
                        std::cout << "No videos found for genre: " << genre << "\n";
                    } else {
                        for (const auto& video : results) {
                            std::cout << video.getName()
                                      << " | " << video.getGenre() << "\n";
                        }
                    }

                } else if (videoOption == 4) {
                    std::cout << "Enter quality (0 = FullHD, 1 = UHD): ";
                    int q = readInt("");

                    auto results = videoRepo.findByQuality(static_cast<Quality>(q));

                    if (results.empty()) {
                        std::cout << "No videos found with that quality.\n";
                    } else {
                        for (const auto& video : results) {
                            std::cout << video.getName()
                                      << " | " << video.getGenre() << "\n";
                        }
                    }

                } else if (videoOption == 5) {
                    std::string title;
                    std::cout << "Enter title to rent: ";
                    std::getline(std::cin, title);

                    if (videoRepo.rentByTitle(title)) {
                        std::cout << "Title rented successfully.\n";
                    } else {
                        std::cout << "Cannot rent title.\n";
                    }
                }
            }
        } else if (mainOption == 2) {
            int musicOption = -1;

            while (musicOption != 0) {
                showMusicMenu();
                musicOption = readMenuOption("Select option: ", 0, 5);

                if (musicOption == 1) {
                    std::cout << "\nListing all songs:\n";
                    musicRepo.searchBySongTitle("");
                } else if (musicOption >= 2 && musicOption <= 5) {
                    std::string query;

                    if (musicOption == 2) {
                        std::cout << "Enter song title: ";
                    } else if (musicOption == 3) {
                        std::cout << "Enter album name: ";
                    } else if (musicOption == 4) {
                        std::cout << "Enter group name: ";
                    } else if (musicOption == 5) {
                        std::cout << "Enter genre: ";
                    }

                    std::getline(std::cin, query);

                    switch (musicOption) {
                        case 2:
                            musicRepo.searchBySongTitle(query);
                            break;
                        case 3:
                            musicRepo.searchByAlbum(query);
                            break;
                        case 4:
                            musicRepo.searchByGroup(query);
                            break;
                        case 5:
                            musicRepo.searchByGenre(query);
                            break;
                    }
                }
            }
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
