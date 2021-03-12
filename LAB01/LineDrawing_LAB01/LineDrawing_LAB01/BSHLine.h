#pragma once
class BSHLine
{
public:
	static void slowlyIncreasingLine(CDC* pDC, int x1,  int y1, int x2, int y2, COLORREF color);
	static void fastlyIncreasingLine(CDC* pDC, int x1,  int y1, int x2, int y2, COLORREF color);
private:
	BSHLine();
};

