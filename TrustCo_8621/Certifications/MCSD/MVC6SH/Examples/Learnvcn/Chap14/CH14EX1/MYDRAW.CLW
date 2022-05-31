; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyDraw.h"
LastPage=0

ClassCount=9
Class1=CMyDrawApp
Class2=CMyDrawDoc
Class3=CMyDrawView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX

[CLS:CMyDrawApp]
Type=0
HeaderFile=MyDraw.h
ImplementationFile=MyDraw.cpp
Filter=N

[CLS:CMyDrawDoc]
Type=0
HeaderFile=DrawDoc.h
ImplementationFile=DrawDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CMyDrawView]
Type=0
HeaderFile=DrawVw.h
ImplementationFile=DrawVw.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=MyDraw.cpp
ImplementationFile=MyDraw.cpp
Filter=D

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
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_TOOL_RECTANGLE
Command19=ID_TOOL_ELLIPSE
Command20=ID_COLOR_BLACK
Command21=ID_COLOR_BLUE
Command22=ID_COLOR_GREEN
Command23=ID_COLOR_CYAN
Command24=ID_COLOR_RED
Command25=ID_COLOR_MAGENTA
Command26=ID_COLOR_YELLOW
Command27=ID_COLOR_WHITE
Command28=ID_COLOR_DKGRAY
Command29=ID_COLOR_LTGRAY
Command30=ID_TOOL_TRANSPARENT
Command31=ID_APP_ABOUT
CommandCount=31

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

