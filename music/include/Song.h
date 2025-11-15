#ifndef EJERCICIOSCOLABORATIVOS3_SONG_H
#define EJERCICIOSCOLABORATIVOS3_SONG_H

#include <string>

class Song {
private:
    std::string title;

public:
    explicit Song(const std::string& t = "")
        : title(t) {}

    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& t) {
        title = t;
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_SONG_H
