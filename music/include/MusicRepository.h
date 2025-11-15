#ifndef EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H
#define EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H

#include <string>
#include "pel/Dynarray.h"
#include "Album.h"

class MusicRepository {
private:
    Dynarray<Album> albums;

public:
    MusicRepository() = default;

    void addAlbum(const Album& album) {
        albums.insertAtEnd(album);
    }

    void searchBySongTitle(const std::string& query) const;
    void searchByAlbum(const std::string& query) const;
    void searchByGroup(const std::string& query) const;
    void searchByGenre(const std::string& query) const;

    void loadData();
};


#endif //EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H