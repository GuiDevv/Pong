#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "Players.h"
#include "Ball.h"
#include <math.h>

const float pi = 3.14159265358979323846;
const float piRad = 180.f / 3.14159265358979323846;

class Vector {
    Vector2f _vec;
public:
    Vector() {}
    Vector(Vector2f vec) : _vec(vec) {}
    Vector(float x, float y) : _vec(x, y) {}

    Vector operator+(Vector other) {
        Vector v = *this;
        v._vec.x += other._vec.x;
        v._vec.y += other._vec.y;
        return v;
    }
    Vector operator*(Vector other) {
        Vector v = *this;
        v._vec.x *= other._vec.x;
        v._vec.y *= other._vec.y;
        return v;
    }
    Vector operator*(float other) {
        Vector v = *this;
        v._vec.x *= other;
        v._vec.y *= other;
        return v;
    }
    Vector2f& getVector() {
        return _vec;
    }

    float length() {
        return sqrtf(powf(_vec.x, 2) + powf(_vec.y, 2));
    }

    float angle() {
        return atan2(_vec.y, _vec.x) * piRad;
    }

    Vector makeVectorByAngle(float ang, float siz) {
        return Vector(sinf(ang) * siz, cosf(ang) * siz);
    }

    Vector rotation(float ang) {
        float newAngle = angle() + ang;
        return makeVectorByAngle(newAngle, this->length());
    }

};