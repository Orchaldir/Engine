#include "Engine.hpp"


int main()
{
	cout << "Example " << MAJOR << "." << MINOR << endl;

	Engine fEngine("Example", 800, 600);

	fEngine.run();

	return 0;
}
