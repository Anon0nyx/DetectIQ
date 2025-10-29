#include <windows.h>

const char CLASS_NAME[] = "CenteredWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  static HWND hEdit;

  switch (uMsg) {
    case WM_CREATE:
      CreateWindow("STATIC", "Hello friend",
          WS_VISIBLE | WS_CHILD | SS_CENTER,
          50, 30, 200, 20,
          hwnd, NULL, NULL, NULL);

      hEdit = CreateWindow("EDIT", "",
          WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
          50, 60, 200, 25,
          hwnd, NULL, NULL, NULL);
      return 0;

    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

  RegisterClass(&wc);

  // Get screen size for centering
  int screenWidth = GetSystemMetrics(SM_CXSCREEN);
  int screenHeight = GetSystemMetrics(SM_CYSCREEN);
  int winWidth = 600, winHeight = 300;

  HWND hwnd = CreateWindowEx(
      0, CLASS_NAME, "Greeting Window",
      WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
      (screenWidth - winWidth) / 2, (screenHeight - winHeight) / 2,
      winWidth, winHeight,
      NULL, NULL, hInstance, NULL
      );

  if (!hwnd) return 0;

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

