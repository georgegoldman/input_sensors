#include <X11/Xlib.h>
#include <iostream>

int main() {
    Display *display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        std::cerr << "Error: Unable to open display." << std::endl;
        return 1;
    }

    Window rootWindow = DefaultRootWindow(display);

    XSelectInput(display, rootWindow, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);

        if (event.type == MotionNotify){
            std::cout << "mouse moved!" << std::endl;
        }else {
            std::cerr << "Error: unable to get mouse motion" << std::endl;
        }

        /**
        switch (event.type) {
            case KeyPress:
                std::cout << "Key pressed!" << std::endl;
                break;
            case KeyRelease:
                std::cout << "Key released!" << std::endl;
                break;
            case ButtonPress:
                std::cout << "Button pressed!" << std::endl;
                break;
            case ButtonRelease:
                std::cout << "Button released!" << std::endl;
                break;
            case MotionNotify:
                std::cout << "Mouse moved!" << std::endl;
                break;
            default:
                break;
        }
        **/
    }

    XCloseDisplay(display);
    return 0;
}
