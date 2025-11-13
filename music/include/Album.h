#ifndef EJERCICIOSCOLABORATIVOS3_ALBUM_H
#define EJERCICIOSCOLABORATIVOS3_ALBUM_H

#include <string>
#include <iostream>         // Para impresión por consola
#include "pel/Dynarray.h"   // Nuestro contenedor dinámico
#include "Song.h"

// Clase que representa un álbum de música con sus canciones.
class Album {
private:
    std::string title;          // Título del álbum
    std::string group;          // Grupo o artista
    std::string genre;          // Género musical
    Dynarray<Song> songs;       // Lista de canciones del álbum

public:
    // Constructor con valores por defecto
    Album(const std::string& t = "",
          const std::string& g = "",
          const std::string& gen = "")
        : title(t), group(g), genre(gen) {}

    // Getters básicos
    const std::string& getTitle() const { return title; }
    const std::string& getGroup() const { return group; }
    const std::string& getGenre() const { return genre; }

    // Añade una canción al álbum usando nuestro Dynarray
    void addSong(const Song& song) {
        // Usamos el método de inserción del Dynarray (antes usábamos push_back)
        songs.insertAtEnd(song);
    }

    // Devuelve las canciones (solo lectura)
    const Dynarray<Song>& getSongs() const {
        return songs;
    }

    // Imprime la información del álbum y el listado de canciones
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