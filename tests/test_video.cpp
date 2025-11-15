#include <cassert>
#include <iostream>
#include "VideoRepository.h"

// En estos tests comprobamos el comportamiento básico del repositorio de vídeo.
// Usamos assert para verificar que los resultados son los esperados.

int main() {
    // Creamos el repositorio y cargamos los datos de ejemplo
    VideoRepository repo;
    repo.seed();

    // Test 1: búsqueda por título existente
    {
        // Buscamos un título que sabemos que existe en seed()
        auto dune = repo.findByTitle("Dune: Part Two");
        assert(dune.size() == 1);                      // Debe haber exactamente un resultado
        assert(dune[0].getGenre() == "Sci-Fi");        // El género debe ser el esperado
    }

    // Test 2: búsqueda por título inexistente
    {
        auto notFound = repo.findByTitle("This title does not exist");
        assert(notFound.size() == 0);                  // No debería devolver resultados
    }

    // Test 3: búsqueda por género
    {
        auto scifi = repo.findByGenre("Sci-Fi");
        assert(scifi.size() > 0);                      // Debe haber varios Sci-Fi

        // Comprobamos que todos los elementos devueltos tienen el género correcto
        for (std::size_t i = 0; i < scifi.size(); ++i) {
            assert(scifi[i].getGenre() == "Sci-Fi");
        }
    }

    // Test 4: búsqueda por calidad
    {
        auto uhd = repo.findByQuality(Quality::UHD);
        assert(uhd.size() > 0);                        // Debe haber títulos UHD

        for (std::size_t i = 0; i < uhd.size(); ++i) {
            assert(uhd[i].getQuality() == Quality::UHD);
        }
    }

    // Test 5: alquiler de un título
    {
        // Primero alquilamos un título que existe y está marcado como no disponible al principio
        bool rented = repo.rentByTitle("Dune: Part Two");
        assert(rented == true);                        // El primer alquiler debería tener éxito

        auto dune = repo.findByTitle("Dune: Part Two");
        assert(dune.size() == 1);
        assert(dune[0].isAvailable() == true);         // Después de alquilar, debe estar disponible

        // Si intentamos alquilarlo de nuevo, debe devolver false
        bool rentedAgain = repo.rentByTitle("Dune: Part Two");
        assert(rentedAgain == false);

        // Si intentamos alquilar un título inexistente, también debe devolver false
        bool rentedUnknown = repo.rentByTitle("Some random movie");
        assert(rentedUnknown == false);
    }

    std::cout << "All video repository tests passed.\n";
    return 0;
}