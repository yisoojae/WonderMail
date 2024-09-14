
// 이상한메일Dlg.h: 헤더 파일
//

#pragma once

#define buttonNum_1 1001
#define editNum_1 1002


// C이상한메일Dlg 대화 상자
class C이상한메일Dlg : public CDialogEx
{
// 생성입니다.
public:
	C이상한메일Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	void OnBnClickedButton1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	CButton button1;
	CEdit edit1;

	int grid_x[13] = { 1052, 1052 + 53, 1052 + (int)(53.333 * 2), 1052 + (int)(53.333 * 3), 1052 + (int)(53.333 * 4), 1052 + (int)(53.333 * 5), 1052 + (int)(53.333 * 6), 1052 + (int)(53.333 * 7), 1052 + (int)(53.333 * 8), 1052 + (int)(53.333 * 9), 1052 + (int)(53.333 * 10), 1052 + (int)(53.333 * 11), 1052 + (int)(53.333 * 12) };
	int grid_y[4] = { 1232,1232 + 48,1232 + 96,1232 + 144 };

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
