#include <windows.h>

static COLORREF redColor = RGB(255, 0, 0);
static COLORREF blueColor = RGB(0, 0, 255);
static COLORREF greenColor = RGB(0, 255, 0);

/* SetPixel */
void setPixel(int x, int y, COLORREF& color = redColor)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);
	SetPixel(hdc, x, y, color);
	ReleaseDC(console, hdc);
	return;
}

void drawLineBresenham(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa - xb), dy = abs(ya - yb);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
	int x, y, xEnd;

	if (xa > xb) {
		x = xb;
		y = yb;
		xEnd = xa;
	}
	else {
		x = xa;
		y = ya;
		xEnd = xb;
	}

	setPixel(x, y);

	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyDx;
		}
		setPixel(x, y);
	}
}

int main()
{
	drawLineBresenham(10, 20, 250, 300);
	return 0;
}