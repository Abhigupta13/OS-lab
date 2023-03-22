#include <stdio.h>
#include <windows.h>

int main() {
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(NULL, "child.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // CreateProcess failed
        printf("Error: failed to create child process.");
    } else {
        // parent process
        printf("Parent process ID: %d\n", GetCurrentProcessId());
        printf("Child process ID: %d\n", pi.dwProcessId);
    }

  return 0;
}