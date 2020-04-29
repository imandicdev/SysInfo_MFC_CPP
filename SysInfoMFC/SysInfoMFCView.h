
// SysInfoMFCView.h : interface of the CSysInfoMFCView class
//

#pragma once


class CSysInfoMFCView : public CView
{
protected: // create from serialization only
	CSysInfoMFCView() noexcept;
	DECLARE_DYNCREATE(CSysInfoMFCView)

// Attributes
public:
	CSysInfoMFCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSysInfoMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SysInfoMFCView.cpp
inline CSysInfoMFCDoc* CSysInfoMFCView::GetDocument() const
   { return reinterpret_cast<CSysInfoMFCDoc*>(m_pDocument); }
#endif

