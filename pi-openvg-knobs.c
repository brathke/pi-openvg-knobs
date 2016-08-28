#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"
#include <signal.h>
#include <math.h>

void draw(int width, int height)
{
    // remote control items
    static int frameNumber = 0;
    frameNumber++;
    
    // clear window
    Start(width, height);

    // set fixed user configurables
    int numKnobs = 3;
    int radius = width/numKnobs;
    
    // set fixed colors, widths
    float fillColor[4] = {color_blue, 255};
    float strokeColor[4] = {color_white, 255};
    float backgroundColor[4] = {color_black, 255};
    Background(color_black);
    setfill(backgroundColor);
    setstroke(strokeColor);
    StrokeWidth(radius/75);

    // draw knobs
    while (numKnobs--) {
        float x = radius/2+numKnobs*radius;
        float y = height*1/2;
        
        // outlines
        if (numKnobs == 0) {
            setfill(fillColor);
            Circle(x, y, radius);
            setfill(backgroundColor);
        }
        else {
            Circle(x, y, radius);
        }

        // indicators
        static float angle = 0;
        angle -= .01;
        float x2 = x + radius/2 * cos(angle*2*3.14);
        float y2 = y + radius/2 * sin(angle*2*3.14);
        Line(x, y, x2, y2);
    }
    
    // swap buffers, render to screen
    End();
}

void sig_handler(int sig)
{
    finish();
    exit(1);
}

int main(int argc, char** argv)
{
    signal(SIGINT, sig_handler);
    
    int width, height;
    init(&width, &height);

    int numIterations = 100;
    while (--numIterations) {
        printf("%i left to do\n", numIterations);
        draw(width, height);
        sleep(0);
    }

    sleep(1);
    finish();    
    exit(0);
}
