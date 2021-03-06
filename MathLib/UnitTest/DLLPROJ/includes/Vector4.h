#pragma once
#include "Vector3.h"

#ifdef STATIC_LIB
#define DLL_MATH
#else 
#ifdef DLL_EXPORT
#define DLL_MATH __declspec(dllexport)
#else
#define DLL_MATH __declspec(dllimport)
#endif	
#endif

class Vector4
{
public:
	DLL_MATH Vector4();
	DLL_MATH Vector4(float newX, float newY, float newZ, float newW);
	DLL_MATH ~Vector4();

	float x, y, z, w;

	DLL_MATH Vector4 operator+(const Vector4 & pos);
	DLL_MATH Vector4 operator+=(const Vector4 & add);
	DLL_MATH Vector4 operator-(const Vector4 & pos);
	DLL_MATH Vector4 operator-();
	DLL_MATH Vector4 operator-=(const Vector4 & sub);
	DLL_MATH Vector4 operator*(const float & Scalarb);
	DLL_MATH Vector4 operator*=(const float & Multi);
	DLL_MATH Vector4 operator/(const float & Scalar);
	DLL_MATH Vector4 operator/=(const float & Div);
	DLL_MATH bool operator==(const Vector4 & pos);
	DLL_MATH bool operator!=(const Vector4 & pos);
	DLL_MATH bool operator>=(const Vector4 & pos);
	DLL_MATH bool operator<=(const Vector4 & pos);

	DLL_MATH Vector4 Max(Vector4 max);
	DLL_MATH Vector4 Min(Vector4 Min);

	DLL_MATH float dot(Vector4 pos);
	DLL_MATH void Clamp(Vector4 min, Vector4 max);
	DLL_MATH Vector4 CalcNormal(Vector4 pos1, Vector4 pos2);
	DLL_MATH float magnitude();
	DLL_MATH float sqrMagnitude();
	DLL_MATH void normalise();
	DLL_MATH Vector4 cross(Vector4 pos);
	DLL_MATH float Distance(Vector4 pos);
	
	DLL_MATH Vector4 Lerp(Vector4 A, Vector4 B, float Percentage);
	DLL_MATH Vector4 BeizerCurve(Vector4 pt1, Vector4 pt2, Vector4 pt3, float percentage);
	DLL_MATH Vector4 hermiteCurve(Vector4 pt1, Vector4 tan1, Vector4 pt2, Vector4 tan2, float percentage);
	DLL_MATH Vector4 CardinalSpline(Vector4 pt1, Vector4 pt2, float percentage);
	DLL_MATH Vector4 Catmull_RomSplines(Vector4 pt1, Vector4 pt2, float percentage);

	DLL_MATH operator float*();

	DLL_MATH Vector4 swizzlingWWWW();
	DLL_MATH Vector4 swizzlingWWWX();
	DLL_MATH Vector4 swizzlingWWWY();
	DLL_MATH Vector4 swizzlingWWWZ();
	DLL_MATH Vector4 swizzlingWWXW();
	DLL_MATH Vector4 swizzlingWWXX();
	DLL_MATH Vector4 swizzlingWWXY();
	DLL_MATH Vector4 swizzlingWWXZ();
	DLL_MATH Vector4 swizzlingWWYW();
	DLL_MATH Vector4 swizzlingWWYX();
	DLL_MATH Vector4 swizzlingWWYY();
	DLL_MATH Vector4 swizzlingWWYZ();
	DLL_MATH Vector4 swizzlingWWZW();
	DLL_MATH Vector4 swizzlingWWZX();
	DLL_MATH Vector4 swizzlingWWZY();
	DLL_MATH Vector4 swizzlingWWZZ();
	DLL_MATH Vector4 swizzlingWXWW();
	DLL_MATH Vector4 swizzlingWXWX();
	DLL_MATH Vector4 swizzlingWXWY();
	DLL_MATH Vector4 swizzlingWXWZ();
	DLL_MATH Vector4 swizzlingWXXW();
	DLL_MATH Vector4 swizzlingWXXX();
	DLL_MATH Vector4 swizzlingWXXY();
	DLL_MATH Vector4 swizzlingWXXZ();
	DLL_MATH Vector4 swizzlingWXYW();
	DLL_MATH Vector4 swizzlingWXYX();
	DLL_MATH Vector4 swizzlingWXYY();
	DLL_MATH Vector4 swizzlingWXYZ();
	DLL_MATH Vector4 swizzlingWXZW();
	DLL_MATH Vector4 swizzlingWXZX();
	DLL_MATH Vector4 swizzlingWXZY();
	DLL_MATH Vector4 swizzlingWXZZ();
	DLL_MATH Vector4 swizzlingWYWW();
	DLL_MATH Vector4 swizzlingWYWX();
	DLL_MATH Vector4 swizzlingWYWY();
	DLL_MATH Vector4 swizzlingWYWZ();
	DLL_MATH Vector4 swizzlingWYXW();
	DLL_MATH Vector4 swizzlingWYXX();
	DLL_MATH Vector4 swizzlingWYXY();
	DLL_MATH Vector4 swizzlingWYXZ();
	DLL_MATH Vector4 swizzlingWYYW();
	DLL_MATH Vector4 swizzlingWYYX();
	DLL_MATH Vector4 swizzlingWYYY();
	DLL_MATH Vector4 swizzlingWYYZ();
	DLL_MATH Vector4 swizzlingWYZW();
	DLL_MATH Vector4 swizzlingWYZX();
	DLL_MATH Vector4 swizzlingWYZY();
	DLL_MATH Vector4 swizzlingWYZZ();
	DLL_MATH Vector4 swizzlingWZWW();
	DLL_MATH Vector4 swizzlingWZWX();
	DLL_MATH Vector4 swizzlingWZWY();
	DLL_MATH Vector4 swizzlingWZWZ();
	DLL_MATH Vector4 swizzlingWZXW();
	DLL_MATH Vector4 swizzlingWZXX();
	DLL_MATH Vector4 swizzlingWZXY();
	DLL_MATH Vector4 swizzlingWZXZ();
	DLL_MATH Vector4 swizzlingWZYW();
	DLL_MATH Vector4 swizzlingWZYX();
	DLL_MATH Vector4 swizzlingWZYY();
	DLL_MATH Vector4 swizzlingWZYZ();
	DLL_MATH Vector4 swizzlingWZZW();
	DLL_MATH Vector4 swizzlingWZZX();
	DLL_MATH Vector4 swizzlingWZZY();
	DLL_MATH Vector4 swizzlingWZZZ();
	DLL_MATH Vector4 swizzlingXWWW();
	DLL_MATH Vector4 swizzlingXWWX();
	DLL_MATH Vector4 swizzlingXWWY();
	DLL_MATH Vector4 swizzlingXWWZ();
	DLL_MATH Vector4 swizzlingXWXW();
	DLL_MATH Vector4 swizzlingXWXX();
	DLL_MATH Vector4 swizzlingXWXY();
	DLL_MATH Vector4 swizzlingXWXZ();
	DLL_MATH Vector4 swizzlingXWYW();
	DLL_MATH Vector4 swizzlingXWYX();
	DLL_MATH Vector4 swizzlingXWYY();
	DLL_MATH Vector4 swizzlingXWYZ();
	DLL_MATH Vector4 swizzlingXWZW();
	DLL_MATH Vector4 swizzlingXWZX();
	DLL_MATH Vector4 swizzlingXWZY();
	DLL_MATH Vector4 swizzlingXWZZ();
	DLL_MATH Vector4 swizzlingXXWW();
	DLL_MATH Vector4 swizzlingXXWX();
	DLL_MATH Vector4 swizzlingXXWY();
	DLL_MATH Vector4 swizzlingXXWZ();
	DLL_MATH Vector4 swizzlingXXXW();
	DLL_MATH Vector4 swizzlingXXXX();
	DLL_MATH Vector4 swizzlingXXXY();
	DLL_MATH Vector4 swizzlingXXXZ();
	DLL_MATH Vector4 swizzlingXXYW();
	DLL_MATH Vector4 swizzlingXXYX();
	DLL_MATH Vector4 swizzlingXXYY();
	DLL_MATH Vector4 swizzlingXXYZ();
	DLL_MATH Vector4 swizzlingXXZW();
	DLL_MATH Vector4 swizzlingXXZX();
	DLL_MATH Vector4 swizzlingXXZY();
	DLL_MATH Vector4 swizzlingXXZZ();
	DLL_MATH Vector4 swizzlingXYWW();
	DLL_MATH Vector4 swizzlingXYWX();
	DLL_MATH Vector4 swizzlingXYWY();
	DLL_MATH Vector4 swizzlingXYWZ();
	DLL_MATH Vector4 swizzlingXYXW();
	DLL_MATH Vector4 swizzlingXYXX();
	DLL_MATH Vector4 swizzlingXYXY();
	DLL_MATH Vector4 swizzlingXYXZ();
	DLL_MATH Vector4 swizzlingXYYW();
	DLL_MATH Vector4 swizzlingXYYX();
	DLL_MATH Vector4 swizzlingXYYY();
	DLL_MATH Vector4 swizzlingXYYZ();
	DLL_MATH Vector4 swizzlingXYZX();
	DLL_MATH Vector4 swizzlingXYZY();
	DLL_MATH Vector4 swizzlingXYZZ();
	DLL_MATH Vector4 swizzlingXZWW();
	DLL_MATH Vector4 swizzlingXZWX();
	DLL_MATH Vector4 swizzlingXZWY();
	DLL_MATH Vector4 swizzlingXZWZ();
	DLL_MATH Vector4 swizzlingXZXW();
	DLL_MATH Vector4 swizzlingXZXX();
	DLL_MATH Vector4 swizzlingXZXY();
	DLL_MATH Vector4 swizzlingXZXZ();
	DLL_MATH Vector4 swizzlingXZYW();
	DLL_MATH Vector4 swizzlingXZYX();
	DLL_MATH Vector4 swizzlingXZYY();
	DLL_MATH Vector4 swizzlingXZYZ();
	DLL_MATH Vector4 swizzlingXZZW();
	DLL_MATH Vector4 swizzlingXZZX();
	DLL_MATH Vector4 swizzlingXZZY();
	DLL_MATH Vector4 swizzlingXZZZ();
	DLL_MATH Vector4 swizzlingYWWW();
	DLL_MATH Vector4 swizzlingYWWX();
	DLL_MATH Vector4 swizzlingYWWY();
	DLL_MATH Vector4 swizzlingYWWZ();
	DLL_MATH Vector4 swizzlingYWXW();
	DLL_MATH Vector4 swizzlingYWXX();
	DLL_MATH Vector4 swizzlingYWXY();
	DLL_MATH Vector4 swizzlingYWXZ();
	DLL_MATH Vector4 swizzlingYWYW();
	DLL_MATH Vector4 swizzlingYWYX();
	DLL_MATH Vector4 swizzlingYWYY();
	DLL_MATH Vector4 swizzlingYWYZ();
	DLL_MATH Vector4 swizzlingYWZW();
	DLL_MATH Vector4 swizzlingYWZX();
	DLL_MATH Vector4 swizzlingYWZY();
	DLL_MATH Vector4 swizzlingYWZZ();
	DLL_MATH Vector4 swizzlingYXWW();
	DLL_MATH Vector4 swizzlingYXWX();
	DLL_MATH Vector4 swizzlingYXWY();
	DLL_MATH Vector4 swizzlingYXWZ();
	DLL_MATH Vector4 swizzlingYXXW();
	DLL_MATH Vector4 swizzlingYXXX();
	DLL_MATH Vector4 swizzlingYXXY();
	DLL_MATH Vector4 swizzlingYXXZ();
	DLL_MATH Vector4 swizzlingYXYW();
	DLL_MATH Vector4 swizzlingYXYX();
	DLL_MATH Vector4 swizzlingYXYY();
	DLL_MATH Vector4 swizzlingYXYZ();
	DLL_MATH Vector4 swizzlingYXZW();
	DLL_MATH Vector4 swizzlingYXZX();
	DLL_MATH Vector4 swizzlingYXZY();
	DLL_MATH Vector4 swizzlingYXZZ();
	DLL_MATH Vector4 swizzlingYYWW();
	DLL_MATH Vector4 swizzlingYYWX();
	DLL_MATH Vector4 swizzlingYYWY();
	DLL_MATH Vector4 swizzlingYYWZ();
	DLL_MATH Vector4 swizzlingYYXW();
	DLL_MATH Vector4 swizzlingYYXX();
	DLL_MATH Vector4 swizzlingYYXY();
	DLL_MATH Vector4 swizzlingYYXZ();
	DLL_MATH Vector4 swizzlingYYYW();
	DLL_MATH Vector4 swizzlingYYYX();
	DLL_MATH Vector4 swizzlingYYYY();
	DLL_MATH Vector4 swizzlingYYYZ();
	DLL_MATH Vector4 swizzlingYYZW();
	DLL_MATH Vector4 swizzlingYYZX();
	DLL_MATH Vector4 swizzlingYYZY();
	DLL_MATH Vector4 swizzlingYYZZ();
	DLL_MATH Vector4 swizzlingYZWW();
	DLL_MATH Vector4 swizzlingYZWX();
	DLL_MATH Vector4 swizzlingYZWY();
	DLL_MATH Vector4 swizzlingYZWZ();
	DLL_MATH Vector4 swizzlingYZXW();
	DLL_MATH Vector4 swizzlingYZXX();
	DLL_MATH Vector4 swizzlingYZXY();
	DLL_MATH Vector4 swizzlingYZXZ();
	DLL_MATH Vector4 swizzlingYZYW();
	DLL_MATH Vector4 swizzlingYZYX();
	DLL_MATH Vector4 swizzlingYZYY();
	DLL_MATH Vector4 swizzlingYZYZ();
	DLL_MATH Vector4 swizzlingYZZW();
	DLL_MATH Vector4 swizzlingYZZX();
	DLL_MATH Vector4 swizzlingYZZY();
	DLL_MATH Vector4 swizzlingYZZZ();
	DLL_MATH Vector4 swizzlingZWWW();
	DLL_MATH Vector4 swizzlingZWWX();
	DLL_MATH Vector4 swizzlingZWWY();
	DLL_MATH Vector4 swizzlingZWWZ();
	DLL_MATH Vector4 swizzlingZWXW();
	DLL_MATH Vector4 swizzlingZWXX();
	DLL_MATH Vector4 swizzlingZWXY();
	DLL_MATH Vector4 swizzlingZWXZ();
	DLL_MATH Vector4 swizzlingZWYW();
	DLL_MATH Vector4 swizzlingZWYX();
	DLL_MATH Vector4 swizzlingZWYY();
	DLL_MATH Vector4 swizzlingZWYZ();
	DLL_MATH Vector4 swizzlingZWZW();
	DLL_MATH Vector4 swizzlingZWZX();
	DLL_MATH Vector4 swizzlingZWZY();
	DLL_MATH Vector4 swizzlingZWZZ();
	DLL_MATH Vector4 swizzlingZXWW();
	DLL_MATH Vector4 swizzlingZXWX();
	DLL_MATH Vector4 swizzlingZXWY();
	DLL_MATH Vector4 swizzlingZXWZ();
	DLL_MATH Vector4 swizzlingZXXW();
	DLL_MATH Vector4 swizzlingZXXX();
	DLL_MATH Vector4 swizzlingZXXY();
	DLL_MATH Vector4 swizzlingZXXZ();
	DLL_MATH Vector4 swizzlingZXYW();
	DLL_MATH Vector4 swizzlingZXYX();
	DLL_MATH Vector4 swizzlingZXYY();
	DLL_MATH Vector4 swizzlingZXYZ();
	DLL_MATH Vector4 swizzlingZXZW();
	DLL_MATH Vector4 swizzlingZXZX();
	DLL_MATH Vector4 swizzlingZXZY();
	DLL_MATH Vector4 swizzlingZXZZ();
	DLL_MATH Vector4 swizzlingZYWW();
	DLL_MATH Vector4 swizzlingZYWX();
	DLL_MATH Vector4 swizzlingZYWY();
	DLL_MATH Vector4 swizzlingZYWZ();
	DLL_MATH Vector4 swizzlingZYXW();
	DLL_MATH Vector4 swizzlingZYXX();
	DLL_MATH Vector4 swizzlingZYXY();
	DLL_MATH Vector4 swizzlingZYXZ();
	DLL_MATH Vector4 swizzlingZYYW();
	DLL_MATH Vector4 swizzlingZYYX();
	DLL_MATH Vector4 swizzlingZYYY();
	DLL_MATH Vector4 swizzlingZYYZ();
	DLL_MATH Vector4 swizzlingZYZW();
	DLL_MATH Vector4 swizzlingZYZX();
	DLL_MATH Vector4 swizzlingZYZY();
	DLL_MATH Vector4 swizzlingZYZZ();
	DLL_MATH Vector4 swizzlingZZWW();
	DLL_MATH Vector4 swizzlingZZWX();
	DLL_MATH Vector4 swizzlingZZWY();
	DLL_MATH Vector4 swizzlingZZWZ();
	DLL_MATH Vector4 swizzlingZZXW();
	DLL_MATH Vector4 swizzlingZZXX();
	DLL_MATH Vector4 swizzlingZZXY();
	DLL_MATH Vector4 swizzlingZZXZ();
	DLL_MATH Vector4 swizzlingZZYW();
	DLL_MATH Vector4 swizzlingZZYX();
	DLL_MATH Vector4 swizzlingZZYY();
	DLL_MATH Vector4 swizzlingZZYZ();
	DLL_MATH Vector4 swizzlingZZZW();
	DLL_MATH Vector4 swizzlingZZZX();
	DLL_MATH Vector4 swizzlingZZZY();
	DLL_MATH Vector4 swizzlingZZZZ();
};

DLL_MATH Vector4 operator*(const float & Scalarf, const Vector4 & pos);