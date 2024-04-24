#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <iostream>

int main() {
    Display *display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    // Grab the keyboard
    XGrabKeyboard(display, DefaultRootWindow(display), True,
                  GrabModeAsync, GrabModeAsync, CurrentTime);

    KeyCode escapeKeyCode = XKeysymToKeycode(display, XK_Escape);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            std::cout << "Key: " << event.xkey.keycode << std::endl;
            if (event.xkey.keycode == escapeKeyCode){
                break;
            }
            std::cout << "Key Pressed\n";
            // Do something when a key is pressed
        } else if (event.type == KeyRelease) {
            std::cout << "Key Released\n";
            // Do something when a key is released
        }
    }

    XCloseDisplay(display);
    return 0;
}
