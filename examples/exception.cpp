#include <iostream>
#include "general/BaseException.h"

int main()
{
	try {
		throw sdk::general::BaseException("Some errors occoured!");
	}
	catch (const sdk::general::BaseException& ex)
	{
		std::cout << "Exception thrown: " << ex.getErrorMsg() << "\n";
	}
	return 0;
}