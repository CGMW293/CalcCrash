#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    while (true) {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        LPWSTR calcPtr = new wchar_t[MAX_PATH];//why cant i just use a string?
        wcscpy_s(calcPtr, MAX_PATH, L"C:\\Windows\\System32\\calc.exe");
        CreateProcessW(NULL, calcPtr, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);   
        delete[] calcPtr;
    }
    return 0;
}
