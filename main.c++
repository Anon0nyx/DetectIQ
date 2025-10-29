#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
            case WM_DESTROY:
                        PostQuitMessage(0);
                                    return 0;
                                        }
                                            return DefWindowProc(hwnd, uMsg, wParam, lParam);
                                            }

                                            int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                                                               LPSTR lpCmdLine, int nCmdShow) {
                                                                   const char CLASS_NAME[] = "MyWindowClass";

                                                                       WNDCLASS wc = {};
                                                                           wc.lpfnWndProc   = WindowProc;
                                                                               wc.hInstance     = hInstance;
                                                                                   wc.lpszClassName = CLASS_NAME;

                                                                                       RegisterClass(&wc);

                                                                                           HWND hwnd = CreateWindowEx(
                                                                                                   0,                              // Optional styles
                                                                                                           CLASS_NAME,                     // Window class
                                                                                                                   "My GUI App",                   // Window text
                                                                                                                           WS_OVERLAPPEDWINDOW,           // Window style
                                                                                                                                   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                                                                                                                           NULL, NULL, hInstance, NULL
                                                                                                                                               );

                                                                                                                                                   if (hwnd == NULL) return 0;

                                                                                                                                                       ShowWindow(hwnd, nCmdShow);

                                                                                                                                                           // Message loop
                                                                                                                                                               MSG msg = {};
                                                                                                                                                                   while (GetMessage(&msg, NULL, 0, 0)) {
                                                                                                                                                                           TranslateMessage(&msg);
                                                                                                                                                                                   DispatchMessage(&msg);
                                                                                                                                                                                       }

                                                                                                                                                                                           return 0;
                                                                                                                                                                                           }

