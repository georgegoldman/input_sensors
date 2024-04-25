#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <climits>

std::string GetActiveWindowTitle(Display* display) {
    Window focused;
    int revert;
    XGetInputFocus(display, &focused, &revert);

    Atom prop = XInternAtom(display, "_NET_WM_NAME", False);
    Atom type;
    int format;
    unsigned long nitems, bytes_after;
    unsigned char *data = nullptr;

    if (XGetWindowProperty(display, focused, prop, 0, LONG_MAX, False, AnyPropertyType,
                           &type, &format, &nitems, &bytes_after, &data) != Success) {
        return "";
    }

    std::string title;
    if (type == XA_STRING) {
        title = reinterpret_cast<char*>(data);
    } else if (type == XInternAtom(display, "UTF8_STRING", False)) {
        title = std::string(reinterpret_cast<char*>(data));
    }

    XFree(data);
    return title;
}

int main() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    while (true) {
        std::string title = GetActiveWindowTitle(display);
        std::cout << "Active Window Title: " << title << std::endl;
        usleep(100000); // Sleep for 100ms (adjust as needed)
    }

    XCloseDisplay(display);
    return 0;
}
