#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

// rotext draws text, rotated around the center of the screen, progressively faded
void rotext(int w, int h, int n, char *s) {
	VGfloat fade = (100.0 / (VGfloat) n) / 100.0;
	VGfloat deg = 360.0 / n;
	VGfloat x = w / 2, y = h / 2;
	VGfloat alpha = 1.0;	// start solid
	int i, size = w / 8;

	Start(w, h);
	Background(0, 0, 0);
	Translate(x, y);
	for (i = 0; i < n; i++) {
		Fill(255, 255, 255, alpha);
		Text(0, 0, s, SerifTypeface, size);

		StrokeWidth(5.0);
		float c[4] = {color_white, 1};
		setstroke(c);
		Line(10, 10, 500, 500);

		alpha -= fade;				   // fade
		size += n;				   // enlarge
		Rotate(deg);
	}
	End();
}

void test_graphics_1(int w, int h, int n, char *s)
{	
	VGfloat deg = 360.0 / n;
	VGfloat x = w / 2, y = h / 2;
	int i;

	float radius = 200;

	Start(w, h);
	Background(0, 0, 0);
	Translate(x, y);
	for (i = 0; i < n; i++) {
//		vgClear(0, 0, w, h);

		StrokeWidth(3.0);

		float c[4] = {color_white, 1};
		setstroke(c);
		
		CircleOutline(0, 0, radius);
		Line(0, 0, radius/2, 0);

		Rotate(deg);
		
		End();
	}
	End();
}

int main() {
	int width, height;
	char s[3];
	
	init(&width, &height);                  // Graphics initialization

	Start(width, height);
#if 1
	test_graphics_1(width, height, 32, "what");
#else
	rotext(width, height, 100, "what the hell?");
#endif
	End();
	
	//sleep(5);
	fgets(s, 2, stdin);                     // look at the pic, end with [RETURN]

	finish();                               // Graphics cleanup
	exit(0);
}
