#include "stdafx.h"
#include "complexData.h"

ComplexData::ComplexData()
{

}

Archive& operator << (Archive& ar, const ComplexData& cd)
{
	ar << cd.x;
	ar << cd.y;
	ar << cd.z;
	ar << cd.w;

	return ar;
}

Archive& operator >> (Archive& ar, ComplexData& cd)
{
	ar >> cd.x;
	ar >> cd.y;
	ar >> cd.z;
	ar >> cd.w;

	return ar;
}

