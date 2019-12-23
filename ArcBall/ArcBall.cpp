#include "ArcBall.h"

#include <math.h>

#define EPSILON 0.0001
#define DEG2RAD 3.14159/180

Vector3 onArcBall(const Vector2& position, const Vector2& center, const float& radius)
{
	if (center.distance(position) > radius)
	{
		return Vector3(radius * (position.x - center.x) / center.distance(position), radius * (position.y - center.y) / center.distance(position), 0);
	}
	else
	{
		return Vector3(position.x - center.x, position.y - center.y, sqrtf(radius * radius - center.distance(position) * center.distance(position)));
	}
}

Matrix4 getViewMatrix(const Vector2& start, const Vector2& end, const Vector2& center, const float& radius)
{
	Vector3 start3(onArcBall(start));
	Vector3 end3(onArcBall(end));
	Matrix4 view_matrix;
	if (!start3.equal(end3, EPSILON))
	{
		Vector3 axis(start3.cross(end3).normalize());
		float angle(DEG2RAD * acosf(start3.dot(end3) / (radius * radius)));
		view_matrix.rotate(angle, axis);
	}
	return view_matrix;
}
