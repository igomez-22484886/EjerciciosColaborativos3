//
// Created by Israel on 04/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H
#define EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H

#include "pel/Dynarray.h"
#include "Album.h"
#include <string>

class MusicRepository {
private:
    Dynarray<Album> albums;

public:
    MusicRepository() {}

    void addAlbum(const Album& album) {
        albums.push_back(album);
    }

    void searchBySongTitle(const std::string& query) const;
    void searchByAlbum(const std::string& query) const;
    void searchByGroup(const std::string& query) const;
    void searchByGenre(const std::string& query) const;

    void populateLibrary();
};



#endif //EJERCICIOSCOLABORATIVOS3_MUSICREPOSITORY_H