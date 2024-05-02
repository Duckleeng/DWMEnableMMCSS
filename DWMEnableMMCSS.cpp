#include <iostream>
#include <Windows.h>
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi.lib")

int main(int argc, char *argv[])
{
    bool console = true;
    if (argc > 1) {
        if (std::string(argv[1]) == "--no-console") {
            console = false;
        }
    }

    HRESULT DWM = DwmEnableMMCSS(true);

    if (console) {
        if (DWM == S_OK) {
            std::cout << "Successful.\n";
        }
        else {
            std::cout << "ERROR\n";
            std::cout << "HRESULT error code: " << DWM << std::endl;
        }
    }

    if (!console) {
        FreeConsole();
    }

    Sleep(INFINITE);
}