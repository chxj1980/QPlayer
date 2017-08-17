#if !defined(AFX_VIDEOWND_H__2D780DDC_26E5_4561_91CC_53BCF9292071__INCLUDED_)
#define AFX_VIDEOWND_H__2D780DDC_26E5_4561_91CC_53BCF9292071__INCLUDED_
#include <atlstr.h>
#include <memory>
#include <mutex>
#include <VFW.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoWnd.h : header file
//

//Video buffer class
class CVideoBuffer
{
public:
	CVideoBuffer();
	~CVideoBuffer();

	BYTE *GetBuffer(int w=0,int h=0);
	void ReleaseBuffer();
	void CleanUpBuffer();
protected:
	void *m_buf;
	int m_w;
	int m_h;
	std::mutex m_mutex;
};

/**
CVideoWnd window
����CImage��Bitsָ��RGB���ݵײ������CImage���÷�ʽ
CImage img("videoback.jpg");
pWnd->FillBuffer((BYTE*)img.GetPixelAddress(0, img.GetHeight()-1), img.GetWidth(), img.GetHeight());
*/
class CVideoWnd
{
  HWND m_hWnd;            // must be first data member
// Construction
public:
	CVideoWnd();	
	virtual ~CVideoWnd();

	bool Create(HWND pParentWnd, DWORD dwExStyle,LPCTSTR lpszWindowName,DWORD dwStyle,
		int x, int y, int nWidth, int nHeight);

	BYTE * GetBuffer(int w,int h);
	BOOL ReleaseBuffer();
	/*
	���RGB.
	@arg pRgb ԭʼRGB����
	@arg width ԭʼ���
	@arg height ԭʼ�߶�
	@arg orgin ��ת���,Ϊ����
	- 0 ����ת
	- 1 90��
	- 2 180��
	- 3 270��
	@return BOOL 
	@retval 
	*/
	BOOL FillBuffer(BYTE* pRgb, int width, int height, int orgin);
	BOOL FillBuffer(BYTE* pRgb, int width, int height){
		return FillBuffer(pRgb, width, height, m_nDefOrgin);}
	// ����ȱʡ��ת����
	void SetDefOrgin(int orgin);
	// ���ô�����Ӧģʽ
	void SetFitMode(BOOL bFit);
	void SetBkColor(COLORREF color){m_clrBK=color;}
	BOOL TaskSnap(LPCTSTR path);
	/*
	�����ı�.
	@arg text ���� 
	@arg clr ��ɫ
	@arg mode ����ģʽ
	*/
	void SetText(LPCTSTR text, COLORREF clr, DWORD mode = DT_BOTTOM|DT_SINGLELINE);
	void Clear();
// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoWnd)
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bUseGDI;
	// ����ɫ
	COLORREF m_clrBK;
	// ��Ӧ����
	BOOL m_bFit;
	// ȱʡ��ת����
	int m_nDefOrgin;

	// �ı�
	CString m_szText;
	// ��ʽ DrawText��ʽ
	DWORD m_nTextFmt;
	// �ı���ɫ
	COLORREF m_clrText;

	BOOL m_bSizeChanged;

	BITMAPINFO m_bmi;
	HDRAWDIB m_hDrawDIB;

	CVideoBuffer m_buffer;
	// Generated message map functions
protected:
	//{{AFX_MSG(CVideoWnd)
	bool OnEraseBkgnd(HDC pDC);
	void OnLButtonDblClk(UINT nFlags, POINT point);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOWND_H__2D780DDC_26E5_4561_91CC_53BCF9292071__INCLUDED_)
