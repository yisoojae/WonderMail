
// 이상한메일Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "이상한메일.h"
#include "이상한메일Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C이상한메일Dlg 대화 상자



C이상한메일Dlg::C이상한메일Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C이상한메일Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C이상한메일Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(buttonNum_1, &C이상한메일Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C이상한메일Dlg 메시지 처리기

BOOL C이상한메일Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	button1.Create(_T("실행"), WS_CHILD | WS_VISIBLE, { 10,10,80,40 }, this, buttonNum_1);
	edit1.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN, { 10,50,400,300 }, this, editNum_1);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C이상한메일Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void C이상한메일Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR C이상한메일Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C이상한메일Dlg::OnBnClickedButton1()
{
	int del_x = 65535 / GetSystemMetrics(SM_CXSCREEN), del_y = 65535 / GetSystemMetrics(SM_CYSCREEN);
	LPTSTR text_1, tmp;
	text_1 = (LPTSTR)malloc((edit1.GetWindowTextLength() + 1) * sizeof(LPTSTR));
	if (!text_1) return;
	edit1.GetWindowText(text_1, edit1.GetWindowTextLength() + 1);
	tmp = text_1;

	while (*tmp)
	{
		switch (*tmp)
		{
		case L'C':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'F':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'H':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[7] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[7] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'J':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'K':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'M':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[12] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[12] * del_x, grid_y[0] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'N':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'P':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'Q':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[3] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[3] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'R':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'S':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'T':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[6] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[6] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'W':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'X':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'Y':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[11] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[11] * del_x, grid_y[1] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'0':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'1':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[1] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[1] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'2':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'3':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[3] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[3] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'4':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'5':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[5] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'6':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[6] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[6] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'7':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[7] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[7] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'8':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[8] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[8] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'9':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[9] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'@':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'&':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[12] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[12] * del_x, grid_y[2] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'-':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[0] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'#':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[2] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'%':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[4] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'+':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[8] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[8] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			break;
		case L'=':
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, grid_x[10] * del_x, grid_y[3] * del_y, 0, 0);
			Sleep(50);
			break;
		default:
			break;
		}
		++tmp;
	}

	free(text_1);
}