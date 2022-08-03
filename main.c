#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main(void) {
    int virtualKey = 0x0;   // The key that triggers the lock : https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    bool isEnabled = FALSE; // if True, the cursor is locked. if False, the cursor is released.
    char* cpBuffer = NULL;  // buffer for the text that's going to be read from key.txt
    FILE* pKeyFile = NULL;  // pointer to ket.txt handle

    printf("[START] Cursor Lock Starting!\n"
           "Reading key.txt... ");

    pKeyFile = fopen("./key.txt", "r");

    if (pKeyFile == NULL){
        printf("Failed!\n[ERROR] Opening key.txt failed with errno: %d\nEXITING!\n", errno);
        return -1;
    }

    cpBuffer = calloc(512, sizeof(char));

    if (cpBuffer == NULL) {
        printf("Failed!\n[ERROR] Failed to allocate memory for key.txt reading buffer!\nEXITING!\n");
        return -2;
    }

    fread(cpBuffer, sizeof(char), 511, pKeyFile);
    printf("OK!\n[INFO] Red \"%s\" from key.txt!\n", cpBuffer);
    virtualKey = (int) strtol(cpBuffer, NULL, 0);
    printf("[INFO] VirtualKey : 0x%X\n", virtualKey);

    fclose(pKeyFile);
    free(cpBuffer);

    COORD screenRes = {(signed short) GetSystemMetrics(SM_CXSCREEN),
                       (signed short) GetSystemMetrics(SM_CYSCREEN)}; // Getting Main screen resolution.

    COORD cursorPos = { (signed short) (screenRes.X/2),
                        (signed short) (screenRes.Y/2)}; // Getting the middle of the screen where the cursor is locked to.

    printf("[INFO] Screen Resolution: %hu x %hu\n", screenRes.X, screenRes.Y);
    printf("[INFO] Cursor Position will be : %hu x %hu (Middle of the screen)\n", cursorPos.X, cursorPos.Y);

    while (TRUE){
        if (GetKeyState(VK_CONTROL) < 0 && GetKeyState(VK_END) < 0) break; // if CTRL+END is pressed, exit the program.

        if (GetKeyState(virtualKey) < 0) {
            // if virtualKey is pressed, change the state of isEnabled.

            if (isEnabled) printf("[INFO] Releasing Mouse from center of the screen!\n");
            else printf("[INFO] Keeping the mouse at the center of the screen!\n");
            isEnabled = !isEnabled;
            Sleep(500);
        }
        if (isEnabled) SetCursorPos(cursorPos.X, cursorPos.Y);
    }
    printf("Exiting the program!");
    return 0;
}