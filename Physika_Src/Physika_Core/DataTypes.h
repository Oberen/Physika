#pragma once
#include <vector_types.h>
#include "Physika_Core/Vectors/vector.h"
#include "Physika_Core/Matrices/matrix.h"

namespace Physika
{
	template<class TReal, class TCoord, class TMatrix>
	class DataTypes
	{
	public:
		typedef TReal Real;
		typedef TCoord Coord;
		typedef TMatrix Matrix;

		static const char* name();
	};

	/// 1f DOF, single precision
	typedef DataTypes<float, Vector1f, Matrix1f> DataType1f;
	template<> inline const char* DataType1f::name() { return "DataType1f"; }

	/// 2f DOF, single precision
	typedef DataTypes<float, Vector2f, Matrix2f> DataType2f;
	template<> inline const char* DataType2f::name() { return "DataType2f"; }

	/// 3f DOF, single precision
	typedef DataTypes<float, Vector3f, Matrix3f> DataType3f;
	template<> inline const char* DataType3f::name() { return "DataType3f"; }

	/// 1d DOF, double precision
	typedef DataTypes<double, Vector1d, Matrix1d> DataType1d;
	template<> inline const char* DataType1d::name() { return "DataType1d"; }

	/// 2d DOF, double precision
	typedef DataTypes<double, Vector2d, Matrix2d> DataType2d;
	template<> inline const char* DataType2d::name() { return "DataType2d"; }

	/// 3d DOF, double precision
	typedef DataTypes<double, Vector3d, Matrix3d> DataType3d;
	template<> inline const char* DataType3d::name() { return "DataType3d"; }
}


