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
	//CVector(CVector& v) : X(v.X), Y(v.Y) { }
	CVector(float vX, float vY) : X(vX), Y(vY) { }

	/*CVector& operator = (CVector& v)
	{
		X = v.X;
		Y = v.Y;
		return *this;
	}*/
};

inline CVector operator + (CVector& a, CVector& b)
{
	return CVector(a.X+b.X, a.Y+b.Y);
}

inline CVector operator - (CVector& a, CVector& b)
{
	return CVector(a.X-b.X, a.Y-b.Y);
}

inline bool operator == (CVector& a, CVector& b)
{
	return ((a.X == b.Y) && (a.Y == b.Y));
}
