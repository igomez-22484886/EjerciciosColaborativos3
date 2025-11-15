#include <cassert>
#include <iostream>
#include <sstream>          // Para capturar la salida de std::cout
#include "Song.h"
#include "Album.h"
#include "MusicRepository.h"
#include "../libs/containers/include/pel/Dynarray.h"

// En estos tests probamos las clases del módulo de música:
// - Song: getters y setters.
// - Album: añadir canciones y acceder a ellas.
// - MusicRepository: al menos un caso de búsqueda comprobando la salida.

int main() {
    // Test 1: clase Song
    {
        Song s("Song A");
        assert(s.getTitle() == "Song A");             // El título inicial debe ser el del constructor

        s.setTitle("Song B");
        assert(s.getTitle() == "Song B");             // El título debe cambiar correctamente
    }

    // Test 2: clase Album + Dynarray<Song>
    {
        Album album("Test Album", "Test Group", "Test Genre");
        album.addSong(Song("Track 1"));
        album.addSong(Song("Track 2"));

        const Dynarray<Song>& songs = album.getSongs();
        assert(songs.getSize() == 2);                 // Debe haber dos canciones
        assert(songs[0].getTitle() == "Track 1");     // Primera canción correcta
        assert(songs[1].getTitle() == "Track 2");     // Segunda canción correcta
    }

    // Test 3: MusicRepository + populateLibrary
    {
        MusicRepository repo;
        repo.populateLibrary();                       // Solo comprobamos que no crashea

        // Vamos a probar searchBySongTitle capturando la salida en memoria
        std::streambuf* oldBuf = std::cout.rdbuf();   // Guardamos el buffer original de cout
        std::ostringstream capture;                   // Donde vamos a capturar el texto
        std::cout.rdbuf(capture.rdbuf());             // Redirigimos cout al stringstream

        // En populateLibrary sabemos que existe "Bohemian Rhapsody" en un álbum de Queen
        repo.searchBySongTitle("Bohemian Rhapsody");

        // Restauramos cout
        std::cout.rdbuf(oldBuf);

        std::string output = capture.str();
        // Comprobamos que en la salida aparece el título de la canción
        assert(output.find("Bohemian Rhapsody") != std::string::npos);
        // Y que también aparece el nombre del grupo o el álbum, algo básico
        assert(output.find("Queen") != std::string::npos ||
               output.find("A Night at the Opera") != std::string::npos);
    }

    // Test 4: llamadas básicas a las otras búsquedas (no comprobamos salida, solo que no fallen)
    {
        MusicRepository repo;
        repo.populateLibrary();

        repo.searchByAlbum("Thriller");
        repo.searchByGroup("Nirvana");
        repo.searchByGenre("Rock");
        // Si llegamos aquí sin que el programa termine con error, ya nos vale como test básico.
    }

    std::cout << "All music tests passed.\n";
    return 0;
}