#pragma once
class Place {
private:
    bool existDalmatian;
public:
    Place() {}
    Place(bool trueORfalse) : existDalmatian(trueORfalse) {}

    bool getExistDalmatian() { return existDalmatian; }
    void setExistDalmatian(bool existDalmatian) {
        this->existDalmatian = existDalmatian;
    }
};
