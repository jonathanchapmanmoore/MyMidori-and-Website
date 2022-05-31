///////////////////////////////////
//
// winsim.cpp
//
// A very simple simulation of an MFC application's life
//
///////////////////////////////////
#include <stdafx.h>
#include <iostream.h>

typedef char* string;

// The real class CWinApp is part of MFC
// This is a simple mockup
class CWinApp
{
public:
	CWinApp();
	virtual void InitInstance();	// Initialize and create window, document, view
	void Run();						// Pump Windows messages to the app
	void ExitInstance();			// Clean up after the app before it quits
	virtual ~CWinApp();

	string strInitMsg;				// Messages used in the simulation
	string strWindowMsg;
	string strPumpMsg;
	string strDispatchMsg;
	string strQuitMsg;
	string strDestroyMsg;
	string strExitMsg;
};

// You're required to derive a class from CWinApp -- this is it
class CMyApp : public CWinApp
{
public:
	CMyApp();
	void InitInstance();		// You must override CWinApp::InitInstance
	~CMyApp();
};

CMyApp theApp;	// The one and only application object;
                //   constructed before main runs (object declared at file scope)

// Global function prototype
void __stdcall WinMain();    // See note on __stdcall at bottom

int main(int argc, char* argv[])
{
	cout << "In main\n";

	WinMain();			// Windows' hidden main calls WinMain, which you write
						//   unless you use MFC

	return 0;
}

////////////////////////////////////
// WinMain function - the heart of a Windows application

void __stdcall WinMain()
{
	cout << "In WinMain\n";	// Covers whole life of the app

	theApp.InitInstance();
	theApp.Run();			// Until a WM_CLOSE message is received
}

/////////////////////////////////////
// CWinApp member functions

CWinApp::CWinApp()
{
	cout << "In CWinApp's constructor\n";

	// Initialize strings used throughout the application
	strInitMsg = "  Doing programmer-defined initialization.";
	strWindowMsg = "  Creating the app's main window, document, and view.";
	strPumpMsg = "  Continuously getting Windows messages from message queue.";
	strDispatchMsg = "  Continuously dispatching Windows messages to the app.";
	strQuitMsg = "  Received WM_QUIT message.";
	strDestroyMsg = "  Destroying window, document, and view.";
	strExitMsg = "  Doing programmer-defined cleanup.";
}

void CWinApp::InitInstance()	// You must override
{
	cout << "In CWinApp::InitInstance\n";
}

void CWinApp::Run()		// You can but seldom will override
{
	cout << "In CWinApp::Run\n";

	// The app's message loop looks something like this:
	// while(GetMessage())			// Obtain message from app's message queue
	// {
	//     TranslateMessage();		// Translate keyboard command messages
	//     DispatchMessage();		// Send message to appropriate app window
	// }

	cout << strPumpMsg << endl;
	cout << strDispatchMsg << endl;
	cout << strQuitMsg << endl;
	cout << strDestroyMsg << endl;

	theApp.ExitInstance();
}

void CWinApp::ExitInstance()	// You can override to do your own cleanup
{
	cout << "In CWinApp::ExitInstance\n";

	cout << strExitMsg << endl;
}

CWinApp::~CWinApp()
{
	cout << "In CWinApp's destructor\n";
}

/////////////////////////////////////
// CMyApp member functions

CMyApp::CMyApp()
{
	cout << "In CMyApp's constructor\n";
}

void CMyApp::InitInstance()		// This is the required override
{
	cout << "In CMyApp's override of InitInstance\n";

	cout << strInitMsg << endl;
	cout << strWindowMsg << endl;
}

CMyApp::~CMyApp()
{
	cout << "In CMyApp's destructor\n";
}


/////////////////////////////////////////
// Note on __stdcall

// The __stdcall modifier (with two leading underscores) specifies
// a particular 'calling convention.' A calling convention tells
// the compiler how to call a particular function or kind of function,
// including things like:
//    - the order in which arguments are passed to the function
//    - argument passing convention, such as by value
//    - who cleans up the stack after the call: caller or callee
//    
// For more information about __stdcall and other calling conventions,
// check the Help index for __stdcall. You won't need this information
// much for Learn Visual C++ Now. 
