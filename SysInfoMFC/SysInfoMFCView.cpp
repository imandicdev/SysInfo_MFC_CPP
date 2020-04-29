
// SysInfoMFCView.cpp : implementation of the CSysInfoMFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SysInfoMFC.h"
#endif

#include "SysInfoMFCDoc.h"
#include "SysInfoMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSysInfoMFCView

IMPLEMENT_DYNCREATE(CSysInfoMFCView, CView)

BEGIN_MESSAGE_MAP(CSysInfoMFCView, CView)
END_MESSAGE_MAP()

// CSysInfoMFCView construction/destruction

CSysInfoMFCView::CSysInfoMFCView() noexcept
{
	// TODO: add construction code here

}

CSysInfoMFCView::~CSysInfoMFCView()
{
}

BOOL CSysInfoMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSysInfoMFCView drawing

void CSysInfoMFCView::OnDraw(CDC* /*pDC*/)
{
	CSysInfoMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSysInfoMFCView diagnostics

#ifdef _DEBUG
void CSysInfoMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CSysInfoMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSysInfoMFCDoc* CSysInfoMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSysInfoMFCDoc)));
	return (CSysInfoMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CSysInfoMFCView message handlers
