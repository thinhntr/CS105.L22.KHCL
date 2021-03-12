#include "pch.h"
#include "DDALine.h"
#include <utility>

void DDALine::slowlyIncreasingLine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto m = (1.0 * y2 - y1) / (1.0 * x2 - x1);
	for (double x = x1, y = y1; x <= x2; x++, y += m) {
		pDC->SetPixel(x, y, color);
	}
}

void DDALine::fastlyIncreasingLine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	if (y1 > y2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	auto k = (1.0 * x2 - x1) / (1.0 * y2 - y1);
	for (double y = y1, x = x1; y <= y2; y++, x += k) {
		pDC->SetPixel(x, y, color);
	}
}