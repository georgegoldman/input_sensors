#include <cstdlib>
#include <string>

void CaptureActiveWindow(const char* filename) {
    std::string command = "import -window $(xdotool getactivewindow) " + std::string(filename);
    system(command.c_str());
}

int main() {
    CaptureActiveWindow("screenshot.png");
    return 0;
}
