; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSTUploadDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "STUpload.h"
LastPage=0

ClassCount=9
Class1=CSTUploadApp
Class2=CSTUploadDoc
Class3=CSTUploadView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_CONFLICT_DIALOG
Class6=CConflictDialog
Class7=CFundDialog
Resource4=IDD_FUNDDIALOG
Class8=CQueryDialog
Resource5=IDR_SRVR_EMBEDDED
Class9=CResultsDialog
Resource6=IDD_QUERYDIALOG
Resource7=IDR_SRVR_INPLACE
Resource8=IDD_RESULTSDIALOG

[CLS:CSTUploadApp]
Type=0
HeaderFile=STUpload.h
ImplementationFile=STUpload.cpp
Filter=N

[CLS:CSTUploadDoc]
Type=0
HeaderFile=STUploadDoc.h
ImplementationFile=STUploadDoc.cpp
Filter=N
BaseClass=COleServerDoc
VirtualFilter=DC
LastObject=ID_DATA_QUERYDATABASE

[CLS:CSTUploadView]
Type=0
HeaderFile=STUploadView.h
ImplementationFile=STUploadView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=STUpload.cpp
ImplementationFile=STUpload.cpp
Filter=D
LastObject=CAboutDlg

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
Command10=ID_DATA_IMPORT
Command11=ID_DATA_UPLOAD
Command12=ID_DATA_QUERYDATABASE
Command13=ID_VIEW_FUNDSELECTION
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_DATA_IMPORT
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_DATA_QUERYDATABASE
Command7=ID_FILE_SAVE
Command8=ID_DATA_UPLOAD
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_DATA_IMPORT
Command5=ID_DATA_UPLOAD
Command6=ID_DATA_QUERYDATABASE
Command7=ID_FILE_PRINT
Command8=ID_VIEW_FUNDSELECTION
CommandCount=8

[DLG:IDD_CONFLICT_DIALOG]
Type=1
Class=CConflictDialog
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDABORT,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_DUPL_RICHEDIT,RICHEDIT,1350633604

[DLG:IDD_FUNDDIALOG]
Type=1
Class=CFundDialog
ControlCount=1
Control1=IDC_FUNDLIST,listbox,1352728835

[CLS:CConflictDialog]
Type=0
HeaderFile=ConflictDialog.h
ImplementationFile=ConflictDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CConflictDialog
VirtualFilter=dWC

[CLS:CFundDialog]
Type=0
HeaderFile=FundDialog.h
ImplementationFile=FundDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_FUNDLIST
VirtualFilter=dWC

[DLG:IDD_QUERYDIALOG]
Type=1
Class=CQueryDialog
ControlCount=9
Control1=IDC_FUND,combobox,1344340227
Control2=IDC_FROMDATE,SysDateTimePick32,1342242849
Control3=IDC_TODATE,SysDateTimePick32,1342242849
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CQueryDialog]
Type=0
HeaderFile=QueryDialog.h
ImplementationFile=QueryDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_RESULTSDIALOG]
Type=1
Class=CResultsDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_DATAGRID1,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control3=IDC_ADODC1,{67397AA3-7FB1-11D0-B148-00A0C922E820},1342177280

[CLS:CResultsDialog]
Type=0
HeaderFile=ResultsDialog.h
ImplementationFile=ResultsDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CResultsDialog

[TB:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_VIEW_TOOLBAR
Command6=ID_APP_ABOUT
CommandCount=6

[MNU:IDR_SRVR_EMBEDDED]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_FILE_SAVE_COPY_AS
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_SRVR_INPLACE]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_CANCEL_EDIT_SRVR
CommandCount=9

[ACL:IDR_SRVR_EMBEDDED]
Type=1
Class=?
Command1=ID_FILE_UPDATE
Command2=ID_FILE_PRINT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
CommandCount=12

