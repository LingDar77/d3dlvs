#pragma once
#include "win.h"
#include <string>
#include <vector>
class winClass {
private:
	HINSTANCE hInstance;
	const char* className;
public:
	winClass(HINSTANCE hInstance, const char* name)noexcept;
	~winClass()noexcept;
};
class windowMan {
private:
	HINSTANCE hInstance;
	std::vector<HWND> hWnds;
public:
	windowMan(HINSTANCE hInstance)noexcept;
	void createWindow(const char* className, const char* windowName, unsigned X, unsigned Y, unsigned wh, unsigned ht)noexcept;

	~windowMan()noexcept;
};