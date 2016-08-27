#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

void test_graphics_1(int w, int h, int n, char *s)
{	
	float radius = 200;
	float strokewidth = 3.0;
	float strokecolor[4] = {color_blue, 1};

	VGfloat deg = -1 * 360.0 / n;
	VGfloat x = radius/2, y = h / 2;
	int i;

	Start(w, h);
	Translate(x, y);
	int knobIndex;
	const int numKnobs = 6;
	for (knobIndex = 0; knobIndex<numKnobs; knobIndex++) {
		for (i = 0; i < n; i++) {
			Background(0, 0, 0);
			StrokeWidth(strokewidth);
			setstroke(strokecolor);
			CircleOutline(0, 0, radius);
			Line(0, 0, radius/2, 0);
			Rotate(deg);			
			End();
		}
		Translate(radius,0);
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
#endif
	End();
	
	//sleep(5);
	//fgets(s, 2, stdin);                     // look at the pic, end with [RETURN]

	finish();                               // Graphics cleanup
	exit(0);
}
