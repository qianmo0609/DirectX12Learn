#include <windows.h>

// 窗口过程函数，处理窗口消息
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_DESTROY:
        // 当接收到 WM_DESTROY 消息时，请求退出应用程序
        PostQuitMessage(0);
        return 0;
    default:
        // 对于其他未处理的消息，调用默认的窗口过程函数进行处理
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

// 主函数，程序的入口点
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    // 定义窗口类名称
    static TCHAR szAppName[] = TEXT("MyWindowClass");
    WNDCLASS wc = {};

    // 设置窗口类的属性
    wc.style = CS_HREDRAW | CS_VREDRAW;  // 窗口大小改变时重绘
    wc.lpfnWndProc = WndProc;  // 指定窗口过程函数
    wc.cbClsExtra = 0;  // 额外的类信息
    wc.cbWndExtra = 0;  // 额外的窗口信息
    wc.hInstance = hInstance;  // 当前应用程序的实例句柄
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // 加载默认应用程序图标
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // 加载默认鼠标指针
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 设置窗口背景为白色
    wc.lpszMenuName = NULL;  // 不使用菜单
    wc.lpszClassName = szAppName;  // 设置窗口类名称

    // 注册窗口类
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
        return 0;
    }

    // 创建窗口
    HWND hwnd = CreateWindow(szAppName,  // 窗口类名称
        TEXT("My First Window"),  // 窗口标题
        WS_OVERLAPPEDWINDOW,  // 窗口样式
        CW_USEDEFAULT,  // 默认的水平位置
        CW_USEDEFAULT,  // 默认的垂直位置
        800,  // 窗口宽度
        600,  // 窗口高度
        NULL,  // 父窗口句柄
        NULL,  // 菜单句柄
        hInstance,  // 当前应用程序的实例句柄
        NULL);  // 额外的创建参数

    // 显示窗口
    ShowWindow(hwnd, iCmdShow);
    // 更新窗口
    UpdateWindow(hwnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        // 翻译虚拟键消息
        TranslateMessage(&msg);
        // 将消息分发给窗口过程函数处理
        DispatchMessage(&msg);
    }
    // 返回退出代码
    return msg.wParam;
}