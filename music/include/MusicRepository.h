#ifndef EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H
#define EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H

#include <string>
#include "pel/Dynarray.h"
#include "Album.h"

// Repositorio que almacena álbumes y ofrece búsquedas.
class MusicRepository {
private:
    Dynarray<Album> albums;   // Colección de álbumes

public:
    MusicRepository() = default;

    // Añade un álbum al repositorio
    void addAlbum(const Album& album) {
        albums.insertAtEnd(album);
    }

    // Búsquedas pedidas en el enunciado
    void searchBySongTitle(const std::string& query) const;
    void searchByAlbum(const std::string& query) const;
    void searchByGroup(const std::string& query) const;
    void searchByGenre(const std::string& query) const;

    // Rellena la biblioteca con algunos ejemplos
    void populateLibrary();
};


#endif //EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H