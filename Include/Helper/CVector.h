/*
 * CVector.h
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#pragma once /* CVECTOR_H_ */

class CVector
{
public:
	float X, Y;

	CVector() : X(0), Y(0) { }
	CVector(const CVector& v) : X(v.X), Y(v.Y) { }
	CVector(const float vX, const float vY) : X(vX), Y(vY) { }

	CVector& operator = (const CVector& v)
	{
		X = v.X;
		Y = v.Y;
		return *this;
	}

	CVector& operator += (const CVector& v)
	{
		X += v.X;
		Y += v.Y;
		return *this;
	}

	CVector& operator -= (const CVector& v)
	{
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	CVector& operator *= (const float f)
	{
		X *= f;
		Y *= f;
		return *this;
	}
};

inline CVector operator + (const CVector& a, const CVector& b)
{
	return CVector(a.X+b.X, a.Y+b.Y);
}

inline CVector operator - (const CVector& a, const CVector& b)
{
	return CVector(a.X-b.X, a.Y-b.Y);
}

inline CVector operator * (const CVector& v, const float f)
{
	return CVector(v.X*f, v.Y*f);
}

inline CVector operator * (const float f, const CVector& v)
{
	return CVector(v.X*f, v.Y*f);
}

inline bool operator == (const CVector& a, const CVector& b)
{
	return ((a.X == b.X) && (a.Y == b.Y));
}

inline bool operator != (const CVector& a, const CVector& b)
{
	return ((a.X != b.X) || (a.Y != b.Y));
}
