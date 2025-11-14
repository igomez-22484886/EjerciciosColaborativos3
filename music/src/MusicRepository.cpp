#include "../include/MusicRepository.h"
#include <iostream>

// Implementación del repositorio de música.
void MusicRepository::searchBySongTitle(const std::string& query) const {
    bool found = false;

    for (std::size_t i = 0; i < albums.getSize(); ++i) {
        const Album& album = albums[i];
        const Dynarray<Song>& songs = album.getSongs();

        for (std::size_t j = 0; j < songs.getSize(); ++j) {
            if (songs[j].getTitle().find(query) != std::string::npos) {
                std::cout << "Song found: " << songs[j].getTitle() << std::endl;
                std::cout << "Album: "     << album.getTitle() << std::endl;
                std::cout << "Group: "     << album.getGroup() << std::endl;
                std::cout << "Genre: "     << album.getGenre() << std::endl;
                std::cout << "------------------------" << std::endl;
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "No song found with the given title." << std::endl;
    }
}

void MusicRepository::searchByAlbum(const std::string& query) const {
    bool found = false;

    for (std::size_t i = 0; i < albums.getSize(); ++i) {
        if (albums[i].getTitle().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No album found with the given title." << std::endl;
    }
}

void MusicRepository::searchByGroup(const std::string& query) const {
    bool found = false;

    for (std::size_t i = 0; i < albums.getSize(); ++i) {
        if (albums[i].getGroup().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No group found with the given name." << std::endl;
    }
}

void MusicRepository::searchByGenre(const std::string& query) const {
    bool found = false;

    for (std::size_t i = 0; i < albums.getSize(); ++i) {
        if (albums[i].getGenre().find(query) != std::string::npos) {
            albums[i].print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No genre found with the given name." << std::endl;
    }
}

void MusicRepository::populateLibrary() {

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
    Album a10("Back in Black", "AC/DC", "Rock");
    a10.addSong(Song("Back in Black"));
    a10.addSong(Song("Hells Bells"));
    addAlbum(a10);

    Album a11("Random Access Memories", "Daft Punk", "Electro");
    a11.addSong(Song("Get Lucky"));
    a11.addSong(Song("Instant Crush"));
    addAlbum(a11);

    Album a12("Born to Die", "Lana Del Rey", "Indie Pop");
    a12.addSong(Song("Born to Die"));
    a12.addSong(Song("Summertime Sadness"));
    addAlbum(a12);

    Album a13("The Eminem Show", "Eminem", "Rap");
    a13.addSong(Song("Without Me"));
    a13.addSong(Song("Sing for the Moment"));
    addAlbum(a13);

    Album a14("Californication", "Red Hot Chili Peppers", "Alternative Rock");
    a14.addSong(Song("Californication"));
    a14.addSong(Song("Otherside"));
    addAlbum(a14);

    Album a15("1989", "Taylor Swift", "Pop");
    a15.addSong(Song("Blank Space"));
    a15.addSong(Song("Shake It Off"));
    addAlbum(a15);

    Album a16("The Dark Side of the Moon", "Pink Floyd", "Progressive Rock");
    a16.addSong(Song("Time"));
    a16.addSong(Song("Money"));
    addAlbum(a16);

    Album a17("Abbey Road", "The Beatles", "Rock");
    a17.addSong(Song("Come Together"));
    a17.addSong(Song("Here Comes the Sun"));
    addAlbum(a17);

    Album a18("Hybrid Theory", "Linkin Park", "Nu Metal");
    a18.addSong(Song("In the End"));
    a18.addSong(Song("Crawling"));
    addAlbum(a18);

    Album a19("Future Nostalgia", "Dua Lipa", "Pop");
    a19.addSong(Song("Don't Start Now"));
    a19.addSong(Song("Levitating"));
    addAlbum(a19);

    Album a20("The College Dropout", "Kanye West", "Hip Hop");
    a20.addSong(Song("Jesus Walks"));
    a20.addSong(Song("All Falls Down"));
    addAlbum(a20);

}