// #include <X11/Xlib.h>
// #include <iostream>

// int main() {
//     Display *display = XOpenDisplay(nullptr);
//     if (display == nullptr) {
//         std::cerr << "Error: Unable to open display." << std::endl;
//         return 1;
//     }

//     Window rootWindow = DefaultRootWindow(display);

//     XSelectInput(display, rootWindow, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

//     XEvent event;
//     while (true) {
//         XNextEvent(display, &event);

//         if (event.type == MotionNotify){
//             std::cout << "mouse moved!" << std::endl;
//         }else {
//             std::cerr << "Error: unable to get mouse motion" << std::endl;
//         }

//         /**
//         switch (event.type) {
//             case KeyPress:
//                 std::cout << "Key pressed!" << std::endl;
//                 break;
//             case KeyRelease:
//                 std::cout << "Key released!" << std::endl;
//                 break;
//             case ButtonPress:
//                 std::cout << "Button pressed!" << std::endl;
//                 break;
//             case ButtonRelease:
//                 std::cout << "Button released!" << std::endl;
//                 break;
//             case MotionNotify:
//                 std::cout << "Mouse moved!" << std::endl;
//                 break;
//             default:
//                 break;
//         }
//         **/
//     }

//     XCloseDisplay(display);
//     return 0;
// }


#include <X11/Xlib.h>
#include <iostream>

int main() {
    Display *display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    // Grab the mouse
    XGrabPointer(display, DefaultRootWindow(display), True,
                 ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
                 GrabModeAsync, GrabModeAsync, None, None, CurrentTime);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        if (event.type == ButtonPress) {
            std::cout << "Button Pressed: " << event.xbutton.button << " at (" 
                      << event.xbutton.x << ", " << event.xbutton.y << ")\n";
            // Do something when a mouse button is pressed
        } else if (event.type == ButtonRelease) {
            std::cout << "Button Released: " << event.xbutton.button << " at (" 
                      << event.xbutton.x << ", " << event.xbutton.y << ")\n";
            // Do something when a mouse button is released
        } else if (event.type == MotionNotify) {
            std::cout << "Mouse Moved to (" << event.xmotion.x << ", " 
                      << event.xmotion.y << ")\n";
            // Do something when the mouse moves
        }
    }

    XCloseDisplay(display);
    return 0;
}
