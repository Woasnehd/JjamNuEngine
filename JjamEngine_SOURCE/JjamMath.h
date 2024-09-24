#pragma once
#include "math.h"

namespace Jjam::math
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2 operator+(Vector2 other) {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(Vector2 other) {
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator/(float value) {
			return Vector2(x / value, y / value);
		}

		Vector2 operator*(float value) {
			return Vector2(x * value, y * value);
		}

		float Length() {
			return sqrtf(x * x + y * y);
		}

		// 벡터를 정규화하는 함수
		void Normalize() {
			float length = Length();

			if (length != 0.0f) {
				x /= length;
				y /= length;
			}
		}
	};
}