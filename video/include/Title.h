//
// Created by Israel on 04/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_TITLE_H
#define EJERCICIOSCOLABORATIVOS3_TITLE_H

#include <string>

enum class Quality { FHD, UHD };

enum class Tariff { Standard, Premium };

class Title {
private:
    std::string name;
    std::string genre;
    Quality quality;
    Tariff tariff;
    double price;
    bool available;

public:
    // Constructor por parámetros
    Title(const std::string &n, const std::string &g, Quality q, Tariff t, double p, bool a);

    // Constructor por defecto
    Title();

    // Getters
    std::string getName() const;

    std::string getGenre() const;

    Quality getQuality() const;

    Tariff getTariff() const;

    double getPrice() const;

    bool isAvailable() const;

    // Setters
    void setName(const std::string &n);

    void setGenre(const std::string &g);

    void setQuality(Quality q);

    void setTariff(Tariff t);

    void setPrice(double p);

    void setAvailable(bool a);
};

#endif //EJERCICIOSCOLABORATIVOS3_TITLE_H
