; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDrawDoc
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyDraw.h"
LastPage=0

ClassCount=8
Class1=CMyDrawApp
Class2=CMyDrawDoc
Class3=CMyDrawView
Class4=CMainFrame

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDR_DRAWING
Resource3=IDD_DRAWING_TITLE
Class5=CAboutDlg
Class6=CTitleDialog
Resource4=IDR_MENU1
Resource5=IDD_ABOUTBOX
Class7=CLinePage
Class8=CShapePage
Resource6=IDD_PS_LINE
Resource7=IDD_PS_SHAPE

[CLS:CMyDrawApp]
Type=0
HeaderFile=MyDraw.h
ImplementationFile=MyDraw.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMyDrawApp

[CLS:CMyDrawDoc]
Type=0
HeaderFile=DrawDoc.h
ImplementationFile=DrawDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMyDrawDoc

[CLS:CMyDrawView]
Type=0
HeaderFile=DrawVw.h
ImplementationFile=DrawVw.cpp
Filter=W
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CMyDrawView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_TOOL_BRING_FWD




[CLS:CAboutDlg]
Type=0
HeaderFile=MyDraw.cpp
ImplementationFile=MyDraw.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PHYSICAL_MEM,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_DISK_SPACE,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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
Command14=ID_EDIT_ERASE
Command15=ID_EDIT_ERASE_ALL
Command16=ID_EDIT_DRAWING_TITLE
Command17=ID_VIEW_TOOLBAR_STD
Command18=ID_VIEW_TOOLBAR_DRAWING
Command19=ID_VIEW_STATUS_BAR
Command20=ID_TOOL_RECTANGLE
Command21=ID_TOOL_ELLIPSE
Command22=ID_COLOR_BLACK
Command23=ID_COLOR_BLUE
Command24=ID_COLOR_GREEN
Command25=ID_COLOR_CYAN
Command26=ID_COLOR_RED
Command27=ID_COLOR_MAGENTA
Command28=ID_COLOR_YELLOW
Command29=ID_COLOR_WHITE
Command30=ID_COLOR_DKGRAY
Command31=ID_COLOR_LTGRAY
Command32=ID_TOOL_CUSTOM_COLOR
Command33=ID_TOOL_TRANSPARENT
Command34=ID_TOOL_SETTINGS
Command35=ID_TOOL_BRING_FWD
Command36=ID_TOOL_SEND_BEHIND
Command37=ID_TOOL_BRING_FRONT
Command38=ID_TOOL_SEND_BACK
Command39=ID_APP_ABOUT
CommandCount=39

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[DLG:IDD_DRAWING_TITLE]
Type=1
Class=CTitleDialog
ControlCount=4
Control1=IDC_DRAWING_TITLE,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CTitleDialog]
Type=0
HeaderFile=dialogs.h
ImplementationFile=dialogs.cpp
BaseClass=CDialog
Filter=D
LastObject=CTitleDialog
VirtualFilter=dWC

[DLG:IDD_PS_LINE]
Type=1
Class=CLinePage
ControlCount=7
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_SPIN1,msctls_updown32,1342242871
Control3=IDC_COMBO1,combobox,1344339971
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC_COLOR,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_PS_SHAPE]
Type=1
Class=CShapePage
ControlCount=4
Control1=IDC_RADIO1,button,1342373897
Control2=IDC_RADIO2,button,1342242825
Control3=IDC_CHECK1,button,1342373891
Control4=IDC_STATIC,button,1342177287

[CLS:CLinePage]
Type=0
HeaderFile=dialogs.h
ImplementationFile=dialogs.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CLinePage

[CLS:CShapePage]
Type=0
HeaderFile=dialogs.h
ImplementationFile=dialogs.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC

[MNU:IDR_MENU1]
Type=1
Class=?
CommandCount=0

