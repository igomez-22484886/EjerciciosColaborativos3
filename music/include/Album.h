//
// Created by Israel on 04/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_ALBUM_H
#define EJERCICIOSCOLABORATIVOS3_ALBUM_H


#include <string>
#include "pel/Dynarray.h"
#include "Song.h"

class Album {
private:
    std::string title;
    std::string group;
    std::string genre;
    Dynarray<Song> songs;

public:
    Album(const std::string& t = "", const std::string& g = "", const std::string& gen = "")
        : title(t), group(g), genre(gen) {}

    const std::string& getTitle() const { return title; }
    const std::string& getGroup() const { return group; }
    const std::string& getGenre() const { return genre; }

    void addSong(const Song& song) {
        songs.push_back(song);
    }

    const Dynarray<Song>& getSongs() const {
        return songs;
    }

    void print() const {
        std::cout << "Álbum: " << title << std::endl;
        std::cout << "Grupo: " << group << std::endl;
        std::cout << "Género: " << genre << std::endl;
        std::cout << "Canciones:" << std::endl;
        for (size_t i = 0; i < songs.size(); ++i) {
            std::cout << " - " << songs[i].getTitle() << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }
};


#endif //EJERCICIOSCOLABORATIVOS3_ALBUM_H