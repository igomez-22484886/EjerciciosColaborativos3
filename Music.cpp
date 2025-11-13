//
// Created by Aldo on 11/11/25.
//

#include "Music.h"




// DinArray.h
#pragma once
#include <vector>
#include <string>
#include <iostream>

class Cancion {
public:
    std::string titulo;
    std::string album;
    std::string grupo;
    std::string genero;

    Cancion(const std::string& t, const std::string& a, const std::string& g, const std::string& gen)
        : titulo(t), album(a), grupo(g), genero(gen) {}
};

class Dynarray {
private:
    std::vector<Cancion> canciones;
public:
    void agregar(const Cancion& c) {
        canciones.push_back(c);
    }

    void buscarPorTitulo(const std::string& t) const {
        bool encontrado = false;
        for (const auto& c : canciones) {
            if (c.titulo == t) {
                std::cout << "Canción encontrada: " << c.titulo << ", Álbum: " << c.album << ", Grupo: " << c.grupo << ", Género: " << c.genero << std::endl;
                encontrado = true;
            }
        }
        if (!encontrado)
            std::cout << "No se ha podido encontrar la canción." << std::endl;
    }

    void buscarPorAlbum(const std::string& a) const {
        bool encontrado = false;
        for (const auto& c : canciones) {
            if (c.album == a) {
                std::cout << "Canción: " << c.titulo << ", Álbum: " << c.album << ", Grupo: " << c.grupo << ", Género: " << c.genero << std::endl;
                encontrado = true;
            }
        }
        if (!encontrado)
            std::cout << "No se ha podido encontrar el álbum." << std::endl;
    }

    void buscarPorGenero(const std::string& gen) const {
        bool encontrado = false;
        for (const auto& c : canciones) {
            if (c.genero == gen) {
                std::cout << "Canción: " << c.titulo << ", Álbum: " << c.album << ", Grupo: " << c.grupo << ", Género: " << c.genero << std::endl;
                encontrado = true;
            }
        }
        if (!encontrado)
            std::cout << "No se ha podido encontrar el género." << std::endl;
    }

    void buscarPorGrupo(const std::string& g) const {
        bool encontrado = false;
        for (const auto& c : canciones) {
            if (c.grupo == g) {
                std::cout << "Canción: " << c.titulo << ", Álbum: " << c.album << ", Grupo: " << c.grupo << ", Género: " << c.genero << std::endl;
                encontrado = true;
            }
        }
        if (!encontrado)
            std::cout << "No se ha podido encontrar el grupo." << std::endl;
    }
};
