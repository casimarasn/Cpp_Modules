#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate(void)
{
	int	generator = std::rand() % 3;

	if (generator == 0)
		return (new A());
	if (generator == 1)
		return (new B());
	else
		return (new C());
}