#include <windows.h>

// ���ڹ��̺�������������Ϣ
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_DESTROY:
        // �����յ� WM_DESTROY ��Ϣʱ�������˳�Ӧ�ó���
        PostQuitMessage(0);
        return 0;
    default:
        // ��������δ�������Ϣ������Ĭ�ϵĴ��ڹ��̺������д���
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

// ���������������ڵ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    // ���崰��������
    static TCHAR szAppName[] = TEXT("MyWindowClass");
    WNDCLASS wc = {};

    // ���ô����������
    wc.style = CS_HREDRAW | CS_VREDRAW;  // ���ڴ�С�ı�ʱ�ػ�
    wc.lpfnWndProc = WndProc;  // ָ�����ڹ��̺���
    wc.cbClsExtra = 0;  // ���������Ϣ
    wc.cbWndExtra = 0;  // ����Ĵ�����Ϣ
    wc.hInstance = hInstance;  // ��ǰӦ�ó����ʵ�����
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // ����Ĭ��Ӧ�ó���ͼ��
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // ����Ĭ�����ָ��
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // ���ô��ڱ���Ϊ��ɫ
    wc.lpszMenuName = NULL;  // ��ʹ�ò˵�
    wc.lpszClassName = szAppName;  // ���ô���������

    // ע�ᴰ����
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
        return 0;
    }

    // ��������
    HWND hwnd = CreateWindow(szAppName,  // ����������
        TEXT("My First Window"),  // ���ڱ���
        WS_OVERLAPPEDWINDOW,  // ������ʽ
        CW_USEDEFAULT,  // Ĭ�ϵ�ˮƽλ��
        CW_USEDEFAULT,  // Ĭ�ϵĴ�ֱλ��
        800,  // ���ڿ��
        600,  // ���ڸ߶�
        NULL,  // �����ھ��
        NULL,  // �˵����
        hInstance,  // ��ǰӦ�ó����ʵ�����
        NULL);  // ����Ĵ�������

    // ��ʾ����
    ShowWindow(hwnd, iCmdShow);
    // ���´���
    UpdateWindow(hwnd);

    // ��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        // �����������Ϣ
        TranslateMessage(&msg);
        // ����Ϣ�ַ������ڹ��̺�������
        DispatchMessage(&msg);
    }
    // �����˳�����
    return msg.wParam;
}