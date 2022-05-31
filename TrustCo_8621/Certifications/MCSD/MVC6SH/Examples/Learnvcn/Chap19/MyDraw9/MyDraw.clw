; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLinePage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mydraw.h"
LastPage=0

ClassCount=8
Class1=CTitleDialog
Class2=CLinePage
Class3=CShapePage
Class4=CMyDrawDoc
Class5=CMyDrawView
Class6=CMainFrame
Class7=CMyDrawApp
Class8=CAboutDlg

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDR_DRAWING
Resource3=IDD_ABOUTBOX
Resource4=IDD_DRAWING_TITLE
Resource5=IDD_PS_LINE
Resource6=IDD_PSS_SHAPE

[CLS:CTitleDialog]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CLinePage]
Type=0
BaseClass=CPropertyPage
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp
Filter=D
VirtualFilter=idWC

[CLS:CShapePage]
Type=0
BaseClass=CPropertyPage
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CMyDrawDoc]
Type=0
BaseClass=CDocument
HeaderFile=DrawDoc.h
ImplementationFile=DrawDoc.cpp

[CLS:CMyDrawView]
Type=0
BaseClass=CScrollView
HeaderFile=DrawVw.h
ImplementationFile=DrawVw.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CMyDrawApp]
Type=0
BaseClass=CWinApp
HeaderFile=MyDraw.h
ImplementationFile=MyDraw.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MyDraw.cpp
ImplementationFile=MyDraw.cpp
LastObject=CAboutDlg

[DLG:IDD_DRAWING_TITLE]
Type=1
Class=CTitleDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DRAWING_TITLE,edit,1350631552

[DLG:IDD_PS_LINE]
Type=1
Class=CLinePage
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_SPIN1,msctls_updown32,1342242871
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_PSS_SHAPE]
Type=1
Class=CShapePage
ControlCount=4
Control1=IDC_RADIO1,button,1342373897
Control2=IDC_RADIO2,button,1342242825
Control3=IDC_CHECK1,button,1342373891
Control4=IDC_STATIC,button,1342177287

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_DRAWING_TITLE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_TOOL_RECTANGLE
Command18=ID_TOOL_ELLIPSE
Command19=ID_COLOR_BLACK
Command20=ID_COLOR_BLUE
Command21=ID_COLOR_GREEN
Command22=ID_COLOR_CYAN
Command23=ID_COLOR_RED
Command24=ID_COLOR_MAGENTA
Command25=ID_COLOR_YELLOW
Command26=ID_COLOR_WHITE
Command27=ID_COLOR_DKGRAY
Command28=ID_COLOR_LTGRAY
Command29=ID_TOOL_CUSTOM_COLOR
Command30=ID_TOOL_TRANSPARENT
Command31=ID_TOOL_SETTINGS
Command32=ID_APP_ABOUT
CommandCount=32

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_DRAWING]
Type=1
Class=?
Command1=ID_TOOL_SELECTION
Command2=ID_TOOL_RECTANGLE
Command3=ID_TOOL_ELLIPSE
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_TOOL_ELLIPSE
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_TOOL_RECTANGLE
Command7=ID_FILE_SAVE
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

