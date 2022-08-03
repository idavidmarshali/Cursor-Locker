# Cursor Locker
 simple program that locks the cursor in the middle of the scree with a hotkey

------

### Why?
When ever im playing games, i like to watch a movie or youtube at the same time in PIP mode.
But games like `satisfactory` (at least until today) won't lock the mouse when you enter the game, which result in
accidentally clicking the PIP video although a game like phasmaphobia locks the mouse and prevents accidental clicking
from happening.
For so i made this simple program that locks the mouse cursor at the middle of the screen with pressing a special 
key and releases it when that key is pressed again.

### How to use?
by default the hotkey of the program is keyboards `F8` key.
Download the latest release (or source and compile it), run the `.exe` file and whenever you want to lock the cursor 
in the middle of the screen, press `F8`.

### How to change the hotkey?
there is file alongside the .exe file called `key.txt`, thats the HotKey file.
this program uses windows Virtual Keys. you can change the hotkey by finding the key you want
in [MS DOC](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes) then take its value and replace
the current value in [key.txt](./key.txt) with it.

for example if you want to change the key from F8 to the Control Key, first you have to find it in [MS DOC](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes) 
which is `VK_CONTROL`, then you take its value which is `0x11` and you replace the current value in [key.txt](./key.txt) to `0x11`
so now the only thing in [key.txt](./key.txt) is `0x11`. now re-run the program, and the hotkey is changed to the Control Key.

### Compiling
i used Mingw-gcc and linked to User32.dll library of win32api.