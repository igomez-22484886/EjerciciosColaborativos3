//
// Created by Israel on 04/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_VIDEOREPOSITORY_H
#define EJERCICIOSCOLABORATIVOS3_VIDEOREPOSITORY_H

#pragma once
#include "pel/Vector.h"
#include "Title.h"
#include <string>
#include <initializer_list>

class VideoRepository {
private:
    Vector<Title> items_;

public:
    void add(const Title& t);
    void addMany(std::initializer_list<Title> list);

    Vector<Title> findByTitle(const std::string& name) const;
    Vector<Title> findByGenre(const std::string& genre) const;
    Vector<Title> findByQuality(Quality q) const;

    bool rentByTitle(const std::string& name);

    void loadData();
};


#endif //EJERCICIOSCOLABORATIVOS3_VIDEOREPOSITORY_H