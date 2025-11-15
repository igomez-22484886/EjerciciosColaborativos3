#ifndef EJERCICIOSCOLABORATIVOS3_ALBUM_H
#define EJERCICIOSCOLABORATIVOS3_ALBUM_H

#include <string>
#include <iostream>         // Para impresión por consola
#include "pel/Dynarray.h"
#include "Song.h"

class Album {
private:
    std::string title;
    std::string group;
    std::string genre;
    Dynarray<Song> songs;

public:
    Album(const std::string& t = "",
          const std::string& g = "",
          const std::string& gen = "")
        : title(t), group(g), genre(gen) {}

    const std::string& getTitle() const { return title; }
    const std::string& getGroup() const { return group; }
    const std::string& getGenre() const { return genre; }

    void addSong(const Song& song) {
        // Usamos el método de inserción del Dynarray (antes usábamos push_back)
        songs.insertAtEnd(song);
    }

    const Dynarray<Song>& getSongs() const {
        return songs;
    }

    void print() const {
        std::cout << "Album: "  << title << std::endl;
        std::cout << "Group: "  << group << std::endl;
        std::cout << "Genre: "  << genre << std::endl;
        std::cout << "Songs:" << std::endl;

        for (std::size_t i = 0; i < songs.getSize(); ++i) {
            std::cout << " - " << songs[i].getTitle() << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_ALBUM_H