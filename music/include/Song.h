//
// Created by Israel on 04/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_SONG_H
#define EJERCICIOSCOLABORATIVOS3_SONG_H



#include <string>

class Song {
private:
    std::string title;

public:
    Song(const std::string& t = "") : title(t) {}

    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& t) {
        title = t;
    }
};






#endif //EJERCICIOSCOLABORATIVOS3_SONG_H