#pragma once
#ifndef _vector
#define _vector

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>
using namespace sf;
const float pi = 3.14159265358979323846;
const float piRad = 180.f / 3.14159265358979323846;
class Vector {
    Vector2f _vec;
public:
    float &x, &y;
    Vector() :
        _vec(0, 0),
        x(_vec.x),
        y(_vec.y) {}
    Vector(Vector2f vec) :
        _vec(vec),
        x(_vec.x),
        y(_vec.y) {}
    Vector(float x, float y) :
        _vec(x, y),
        x(_vec.x),
        y(_vec.y) {}
    Vector& operator=(Vector other) {
        _vec = other._vec;
        return *this;
    }

    Vector normalize() {
        float l = length();
        if (l == 0)
            return { 1, 0 };
        else
            return *this / l;
    }
    Vector operator+(Vector other) {
        Vector v = *this;
        v._vec.x += other._vec.x;
        v._vec.y += other._vec.y;
        return v;
    }
    Vector operator-(Vector other) {
        Vector v = *this;
        v._vec.x -= other._vec.x;
        v._vec.y -= other._vec.y;
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
    Vector operator/(float other) {
        Vector v = *this;
        v._vec.x /= other;
        v._vec.y /= other;
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
        return Vector(cosf(ang / piRad) * siz, sinf(ang / piRad) * siz);
    }
    Vector rotation(float ang) {
        float newAngle = angle() + ang;
        return makeVectorByAngle(newAngle, this->length());
    }
};

Vector VLerp(Vector a, Vector b, float v);
float FLerp(float a, float b, float v);

#endif _vector