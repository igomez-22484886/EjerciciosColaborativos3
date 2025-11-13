#ifndef EJERCICIOSCOLABORATIVOS3_SONG_H
#define EJERCICIOSCOLABORATIVOS3_SONG_H

#include <string>

// Clase que representa una canción dentro de un álbum.
class Song {
private:
    std::string title;   // Título de la canción

public:
    // Constructor con valor por defecto
    explicit Song(const std::string& t = "")
        : title(t) {}

    // Devuelve el título de la canción
    const std::string& getTitle() const {
        return title;
    }

    // Cambia el título de la canción
    void setTitle(const std::string& t) {
        title = t;
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_SONG_H
