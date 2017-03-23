// archive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "archive.h"
#include "complexData.h"
#include <iostream>

int main()
{

	Archive ar;
	if (ar.toWrite("x.dat"))
	{
		ComplexData cd;
		cd.x = 666;
		cd.y = 5.75f;
		cd.z = false;
		cd.w = "Bonjour";
		ar << cd;
		ar.Close();
	}

	if (ar.toRead("x.dat"))
	{
		ComplexData cd;
		ar >> cd;
		std::cout << cd.x << ", " << cd.y << ", " << ((cd.z) ? "true" : "false") << ", " << cd.w.c_str() << std::endl;

	}

	std::cin.get();

	return 0;

	

}
