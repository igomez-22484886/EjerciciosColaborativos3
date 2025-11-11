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
        Title{"Arcane S2", "Anime", Quality::UHD, Tariff::Premium, 1.99, false}
    });
}
