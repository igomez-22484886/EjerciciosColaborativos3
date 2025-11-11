//
// Created by Israel on 04/11/2025.
//

#include "Title.h"

// Constructor por parámetros
Title::Title(const std::string &n, const std::string &g, Quality q, Tariff t, double p, bool a) : name(n), genre(g),
    quality(q), tariff(t), price(p), available(a) {
}

// Constructor por defecto
Title::Title() : name(""), genre(""), quality(Quality::FHD), tariff(Tariff::Standard), price(0.0), available(false) {
}

// Getters
std::string Title::getName() const { return name; }
std::string Title::getGenre() const { return genre; }
Quality Title::getQuality() const { return quality; }
Tariff Title::getTariff() const { return tariff; }
double Title::getPrice() const { return price; }
bool Title::isAvailable() const { return available; }

// Setters
void Title::setName(const std::string &n) { name = n; }
void Title::setGenre(const std::string &g) { genre = g; }
void Title::setQuality(Quality q) { quality = q; }
void Title::setTariff(Tariff t) { tariff = t; }
void Title::setPrice(double p) { price = p; }
void Title::setAvailable(bool a) { available = a; }
