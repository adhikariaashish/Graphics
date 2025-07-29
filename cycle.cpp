#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawCycle(int x, int y)
{
    int r = 40; // Radius of wheels

    // Wheels
    circle(x, y, r);       // Rear wheel
    circle(x + 120, y, r); // Front wheel

    // Frame
    line(x, y, x + 40, y - 40);           // Rear wheel to seat
    line(x + 40, y - 40, x + 40, y);      // Seat down to center
    line(x + 40, y - 40, x + 80, y - 40); // Top bar
    line(x + 80, y - 40, x + 120, y);     // Down to front wheel
    line(x + 40, y, x + 120, y);          // Bottom connecting bar

    // Handlebars
    line(x + 80, y - 40, x + 80, y - 60); // Handlebar vertical
    line(x + 70, y - 60, x + 90, y - 60); // Handlebar horizontal

    // Seat
    line(x + 30, y - 40, x + 50, y - 40); // Seat
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0, y = 300; // Starting position

    while (!kbhit())
    { // Loop until key is pressed
        cleardevice();
        drawCycle(x, y);
        delay(30);
        x += 5;

        if (x > getmaxx() - 140) // Reset if it goes off screen
            x = -140;
    }

    closegraph();
    return 0;
}
