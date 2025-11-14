//
// Created by Israel on 04/11/2025.
//

#include "VideoRepository.h"

void VideoRepository::add(const Title &t) {
    items_.pushBack(t);
}

void VideoRepository::addMany(std::initializer_list<Title> list) {
    for (auto const &x: list) items_.pushBack(x);
}

Vector<Title> VideoRepository::findByTitle(const std::string &name) const {
    Vector<Title> result;
    for (auto const &x: items_)
        if (x.getName() == name) result.pushBack(x);
    return result;
}

Vector<Title> VideoRepository::findByGenre(const std::string &genre) const {
    Vector<Title> result;
    for (auto const &x: items_)
        if (x.getGenre() == genre) result.pushBack(x);
    return result;
}

Vector<Title> VideoRepository::findByQuality(Quality q) const {
    Vector<Title> result;
    for (auto const &x: items_)
        if (x.getQuality() == q) result.pushBack(x);
    return result;
}

bool VideoRepository::rentByTitle(const std::string &name) {
    for (auto &x: items_) {
        if (x.getName() == name) {
            if (!x.isAvailable()) {
                x.setAvailable(true);
                return true;
            }
            return false; // already available
        }
    }
    return false; // not found
}

void VideoRepository::seed() {
    addMany({
        Title{"Dune: Part Two", "Sci-Fi", Quality::UHD, Tariff::Premium, 3.99, false},
        Title{"Oppenheimer", "Drama", Quality::FHD, Tariff::Standard, 0.0, false},
        Title{"Arcane S1", "Anime", Quality::UHD, Tariff::Premium, 1.99, false},
        Title{"Arcane S2", "Anime", Quality::UHD, Tariff::Premium, 1.99, false},
        Title{"Interstellar", "Sci-Fi", Quality::FHD, Tariff::Standard, 0.0, false},
        Title{"The Matrix", "Action", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"John Wick", "Action", Quality::UHD, Tariff::Premium, 2.99, false},
        Title{"The Godfather", "Crime", Quality::FHD, Tariff::Standard, 0.0, false},
        Title{"The Dark Knight", "Action", Quality::FHD, Tariff::Standard, 0.0, false},
        Title{"Avatar: The Way of Water", "Sci-Fi", Quality::UHD, Tariff::Premium, 3.99, false},
        Title{"Pulp Fiction", "Crime", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Spider-Man: Across the Spider-Verse", "Animation", Quality::UHD, Tariff::Premium, 3.49, false},
        Title{"Toy Story 4", "Animation", Quality::FHD, Tariff::Standard, 0.0, false},
        Title{"Barbie", "Comedy", Quality::FHD, Tariff::Standard, 1.99, false},
        Title{"Shrek 2", "Animation", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Breaking Bad S1", "Drama", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Breaking Bad S2", "Drama", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"The Last of Us S1", "Drama", Quality::UHD, Tariff::Premium, 3.99, false},
        Title{"House of the Dragon S1", "Fantasy", Quality::UHD, Tariff::Premium, 3.99, false},
        Title{"Stranger Things S1", "Sci-Fi", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Stranger Things S2", "Sci-Fi", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"La banda del Peugeot", "Corruption", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Mi primer Segarro", "Crime", Quality::UHD, Tariff::Standard, 0.0, false},
        Title{"Son las 5 y no he comido :(", "Suspense", Quality::UHD, Tariff::Standard, 0.0, false},





});
}
