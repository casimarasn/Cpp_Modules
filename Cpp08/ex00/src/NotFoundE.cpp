#include "NotFoundE.hpp"

NotFoundE::NotFoundE(){}

NotFoundE::NotFoundE(const NotFoundE& other): std::exception(other){}


NotFoundE& NotFoundE::operator=(const NotFoundE& other)
{
	std::exception::operator=(other);
	return (*this);
}

NotFoundE::~NotFoundE() throw(){}

const char* NotFoundE::what() const throw() {
	return "Value not found in container"
	{

	}

}
virtual ~NotFoundE() throw()
{

}
