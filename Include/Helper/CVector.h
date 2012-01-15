/*
 * CVector.h
 *
 *  Created on: 11.01.2012
 *      Author: 06hofmann-sebas
 */

#pragma once /* CVECTOR_H_ */

template<class T>class CVector_
{
public:
	T X, Y;

	CVector_() : X(0), Y(0) { }
	CVector_(const CVector_<T>& v) : X(v.X), Y(v.Y) { }
	CVector_(const T vX, const T vY) : X(vX), Y(vY) { }

	CVector_<T>& operator = (const CVector_<T>& v)
	{
		X = v.X;
		Y = v.Y;
		return *this;
	}

	CVector_<T>& operator += (const CVector_<T>& v)
	{
		X += v.X;
		Y += v.Y;
		return *this;
	}

	CVector_<T>& operator -= (const CVector_<T>& v)
	{
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	CVector_<T>& operator *= (const T f)
	{
		X *= f;
		Y *= f;
		return *this;
	}

	template <class C> operator CVector_<C> ()
	{
		return CVector_<C>(X, Y);
	}
};

template<class T> inline CVector_<T> operator + (const CVector_<T>& a, const CVector_<T>& b)
{
	return CVector_<T>(a.X+b.X, a.Y+b.Y);
}

template<class T> inline CVector_<T> operator - (const CVector_<T>& a, const CVector_<T>& b)
{
	return CVector_<T>(a.X-b.X, a.Y-b.Y);
}

template<class T> inline CVector_<T> operator * (const CVector_<T>& v, const float f)
{
	return CVector_<T>(v.X*f, v.Y*f);
}

template<class T> inline CVector_<T> operator * (const float f, const CVector_<T>& v)
{
	return CVector_<T>(v.X*f, v.Y*f);
}

template<class T> inline bool operator == (const CVector_<T>& a, const CVector_<T>& b)
{
	return ((a.X == b.X) && (a.Y == b.Y));
}

template<class T> inline bool operator != (const CVector_<T>& a, const CVector_<T>& b)
{
	return ((a.X != b.X) || (a.Y != b.Y));
}

typedef CVector_<float> CVector_f;
typedef CVector_<Uint8> CVector_Ui8;
typedef CVector_<Uint16> CVector_Ui16;
typedef CVector_<Uint32> CVector_Ui32;

typedef CVector_f CVector;
