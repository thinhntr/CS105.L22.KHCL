#include "pch.h"
#include "BSHLine.h"
#include <utility>

void BSHLine::slowlyIncreasingLine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto xi = x1;
	auto yi = y1;
	auto dx = x2 - x1;
	auto dy = y2 - y1;
	auto m = 1.0 * dy / dx;
	auto b = y1 - m * x1;
	while (xi < x2) {
		pDC->SetPixel(xi, yi, color);
		auto y = m * (xi + 1.0) + b;
		xi++;
		if (y2 > y1) {
			auto d1 = y - yi;
			auto d2 = yi + 1.0 - y;
			if (d1 > d2) {
				yi++;
			}
		}
		else {
			auto d1 = y - (yi + 1.0);
			auto d2 = yi - y;
			if (d1 < d2) {
				yi--;
			}
		}
	}
}

void BSHLine::fastlyIncreasingLine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	if (y1 > y2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto xi = x1;
	auto yi = y1;
	auto dx = x2 - x1;
	auto dy = y2 - y1;
	auto m = 1.0 * dy / dx;
	auto b = y1 - m * x1;
	while (yi < y2) {
		pDC->SetPixel(xi, yi, color);
		auto x = (yi + 1.0 - b) / m;
		yi++;
		if (x1 < x2) {
			auto d1 = x - xi;
			auto d2 = xi + 1.0 - x;
			if (d1 > d2) {
				xi++;
			}
		}
		else {
			auto d1 = x - (xi - 1.0);
			auto d2 = xi - x;
			if (d1 < d2) {
				xi--;
			}
		}
	}
}
