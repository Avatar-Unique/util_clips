#ifndef ARCBALL_H
#define ARCBALL_H

#include "Vectors.h"
#include "Matrices.h"

Vector3 onArcBall(const Vector2& position, const Vector2& center, const float& radius);

Matrix4 getViewMatrix(const Vector2& start, const Vector2& end, const Vector2& center, const float& radius);

#endif // !ARCBALL_H
