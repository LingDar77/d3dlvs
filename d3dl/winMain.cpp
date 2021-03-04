#include "window.h"
//??????
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreInstance,
	LPSTR nCmdLine,
	int nCmdshow)
{
	winClass c1(hInstance, "f1");
	windowMan m1(hInstance);
	m1.createWindow("f1", "a wiindow", 100, 100, 800, 600);
	while (1);
	return 0;
}