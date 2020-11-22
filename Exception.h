#pragma once
#include <Exception>

class IndexIsNegative : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Index is negative");
	}
};

class IndexOutOfRange : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Index out if range");
	}
};

class NodeIsEmpty : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Node is empty");
	}
};
