
// LineDrawing_LAB01View.cpp : implementation of the CLineDrawingLAB01View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LineDrawing_LAB01.h"
#endif

#include "LineDrawing_LAB01Doc.h"
#include "LineDrawing_LAB01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "DDALine.h"
#include "BSHLine.h"
// CLineDrawingLAB01View

IMPLEMENT_DYNCREATE(CLineDrawingLAB01View, CView)

BEGIN_MESSAGE_MAP(CLineDrawingLAB01View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLineDrawingLAB01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLineDrawingLAB01View construction/destruction

CLineDrawingLAB01View::CLineDrawingLAB01View() noexcept
{
	// TODO: add construction code here

}

CLineDrawingLAB01View::~CLineDrawingLAB01View()
{
}

BOOL CLineDrawingLAB01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLineDrawingLAB01View drawing

void CLineDrawingLAB01View::OnDraw(CDC* pDC)
{
	CLineDrawingLAB01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	auto scarlet = RGB(140, 0, 50);

	DDALine::slowlyIncreasingLine(pDC, 500, 100, 300, 200, scarlet);
	DDALine::slowlyIncreasingLine(pDC, 100, 100, 300, 200, scarlet);

	DDALine::fastlyIncreasingLine(pDC, 100, 100, 50, 250, scarlet);
	DDALine::fastlyIncreasingLine(pDC, 500, 100, 550, 250, scarlet);

	DDALine::fastlyIncreasingLine(pDC, 100, 550, 50, 250, scarlet);
	DDALine::fastlyIncreasingLine(pDC, 550, 250, 500, 550, scarlet);

	DDALine::fastlyIncreasingLine(pDC, 125, 225, 100, 550, scarlet);
	DDALine::fastlyIncreasingLine(pDC, 475, 225, 500, 550, scarlet);

	DDALine::slowlyIncreasingLine(pDC, 125, 225, 300, 300, scarlet);
	DDALine::slowlyIncreasingLine(pDC, 300, 300, 475, 225, scarlet);

	auto cyan = RGB(38, 198, 218);

	BSHLine::slowlyIncreasingLine(pDC, 300, 200, 500, 100, cyan);
	BSHLine::slowlyIncreasingLine(pDC, 100, 100, 300, 200, cyan);

	BSHLine::fastlyIncreasingLine(pDC, 100, 100, 50, 250, cyan);
	BSHLine::fastlyIncreasingLine(pDC, 500, 100, 550, 250, cyan);

	BSHLine::fastlyIncreasingLine(pDC, 50, 250, 100, 550, cyan);
	BSHLine::fastlyIncreasingLine(pDC, 550, 250, 500, 550, cyan);

	BSHLine::fastlyIncreasingLine(pDC, 125, 225, 100, 550, cyan);
	BSHLine::fastlyIncreasingLine(pDC, 475, 225, 500, 550, cyan);

	BSHLine::slowlyIncreasingLine(pDC, 125, 225, 300, 300, cyan);
	BSHLine::slowlyIncreasingLine(pDC, 300, 300, 475, 225, cyan);
}


// CLineDrawingLAB01View printing


void CLineDrawingLAB01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLineDrawingLAB01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLineDrawingLAB01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLineDrawingLAB01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLineDrawingLAB01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLineDrawingLAB01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLineDrawingLAB01View diagnostics

#ifdef _DEBUG
void CLineDrawingLAB01View::AssertValid() const
{
	CView::AssertValid();
}

void CLineDrawingLAB01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineDrawingLAB01Doc* CLineDrawingLAB01View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineDrawingLAB01Doc)));
	return (CLineDrawingLAB01Doc*)m_pDocument;
}
#endif //_DEBUG


// CLineDrawingLAB01View message handlers
