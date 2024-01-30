#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    while (true) {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        LPWSTR calcPtr = new wchar_t[MAX_PATH];//why can i just use a string?
        wcscpy_s(calcPtr, MAX_PATH, L"C:\\Windows\\System32\\calc.exe");
        CreateProcessW(NULL,   // No module name (use command line)
            calcPtr,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            CREATE_NO_WINDOW,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi);         // Pointer to PROCESS_INFORMATION structure
        delete[] calcPtr;
    }
    return 0;
}
