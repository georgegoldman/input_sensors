#include <cstdlib>
#include <unistd.h>

int main(){
    // Run the xdotool command
    while (1)
    {
        system("xdotool getwindowfocus getwindowname");
        usleep(500'000);
    }
    

    return 0;
}