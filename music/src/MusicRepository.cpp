//
// Created by Israel on 04/11/2025.
//
// music/src/MusicRepository.cpp
#include "MusicRepository.h"
#include <iostream>

void MusicRepository::searchBySongTitle(const std::string& query) const {
    bool found = false;
    for (size_t i = 0; i < albums.size(); ++i) {
        const Album& album = albums[i];
        const Dynarray<Song>& songs = album.getSongs();
        for (size_t j = 0; j < songs.size(); ++j) {
            if (songs[j].getTitle().find(query) != std::string::npos) {
                std::cout << "Canción: " << songs[j].getTitle() << std::endl;
                std::cout << "Álbum: " << album.getTitle() << std::endl;
                std::cout << "Grupo: " << album.getGroup() << std::endl;
                std::cout << "Género: " << album.getGenre() << std::endl;
                std::cout << "------------------------" << std::endl;
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "No se ha podido encontrar la canción con el título proporcionado." << std::endl;
    }
}

void MusicRepository::searchByAlbum(const std::string& query) const {
    bool found = false;
    for (size_t i = 0; i < albums.size(); ++i) {
        if (albums[i].getTitle().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No se ha podido encontrar el álbum." << std::endl;
    }
}

void MusicRepository::searchByGroup(const std::string& query) const {
    bool found = false;
    for (size_t i = 0; i < albums.size(); ++i) {
        if (albums[i].getGroup().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No se ha podido encontrar el grupo." << std::endl;
    }
}

void MusicRepository::searchByGenre(const std::string& query) const {
    bool found = false;
    for (size_t i = 0; i < albums.size(); ++i) {
        if (albums[i].getGenre().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No se ha podido encontrar el género." << std::endl;
    }
}

void MusicRepository::populateLibrary() {
    // Ejemplos
    Album a1("A Night at the Opera", "Queen", "Rock");
    a1.addSong(Song("Bohemian Rhapsody"));
    addAlbum(a1);

    Album a2("Led Zeppelin IV", "Led Zeppelin", "Rock");
    a2.addSong(Song("Stairway to Heaven"));
    addAlbum(a2);

    Album a3("Thriller", "Michael Jackson", "Pop");
    a3.addSong(Song("Billie Jean"));
    a3.addSong(Song("Thriller"));
    addAlbum(a3);

    Album a4("Nevermind", "Nirvana", "Grunge");
    a4.addSong(Song("Smells Like Teen Spirit"));
    addAlbum(a4);

    Album a5("Hotel California", "Eagles", "Rock");
    a5.addSong(Song("Hotel California"));
    addAlbum(a5);

    Album a6("Divide", "Ed Sheeran", "Pop");
    a6.addSong(Song("Shape of You"));
    addAlbum(a6);

    Album a7("21", "Adele", "Soul");
    a7.addSong(Song("Rolling in the Deep"));
    addAlbum(a7);

    Album a8("Imagine", "John Lennon", "Pop");
    a8.addSong(Song("Imagine"));
    addAlbum(a8);

    Album a9("News of the World", "Queen", "Rock");
    a9.addSong(Song("We Will Rock You"));
    addAlbum(a9);
}