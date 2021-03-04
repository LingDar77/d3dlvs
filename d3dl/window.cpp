#include "window.h"

winClass::winClass(HINSTANCE hInstance, const char* name)noexcept
	:hInstance(hInstance), className(name)
{
	WNDCLASSEX wc = { 0 };
	wc.hInstance = hInstance;
	wc.lpszClassName = className;
	wc.cbSize = sizeof(wc);
	wc.hCursor = nullptr;
	wc.hIconSm = nullptr;
	//wc.hIcon = Loadimage();
	wc.hIcon = nullptr;
	wc.lpfnWndProc = DefWindowProc;
	wc.style = CS_OWNDC;
	RegisterClassEx(&wc);
}

winClass::~winClass()noexcept
{
	UnregisterClass(className, hInstance);
}

windowMan::windowMan(HINSTANCE hInstance) noexcept
	:hInstance(hInstance)
{
}

void windowMan::createWindow(const char* className, const char* windowName, unsigned X, unsigned Y, unsigned wh, unsigned ht) noexcept
{
	auto hWnd = CreateWindow(
		className, windowName,
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,

		X, Y, wh, ht,
		nullptr, nullptr,
		hInstance, this
	);
	ShowWindow(hWnd, SW_SHOW);
	hWnds.push_back(hWnd);
}

windowMan::~windowMan() noexcept
{
	for (auto& i : hWnds)
		DestroyWindow(i);
}