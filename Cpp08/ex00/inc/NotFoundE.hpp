#ifndef NOTFOUNDE_HPP
# define NOTFOUNDE_HPP

#include <exception>

class NotFoundE : public std::exception
{
	public:
		NotFoundE();
		NotFoundE(const NotFoundE& other);
		NotFoundE& operator=(const NotFoundE& other);
		virtual ~NotFoundE() throw();
		virtual const char* what() const throw() {
			return "Value not found in container";
		}
};

#endif