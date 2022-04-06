#include "graph.h"

void main()
{
	resizeConsole(1024, 400);

	thread th1(line1);
	thread th2(line2);
	thread th3(line3);
	thread th4(line4);

	th1.join();
	th2.join();
	th3.join();
	th4.join();
}

