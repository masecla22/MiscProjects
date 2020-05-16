#NoTrayIcon
#include <WinAPIShellEx.au3>
If not FileExists(@StartupDir & "/" & @ScriptName) Then
  FileCopy(@ScriptFullPath, @StartupDir)
EndIf
Func setName($name)
 RegWrite("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\CLSID\{645FF040-5081-101B-9F08-00AA002F954E}","","REG_SZ",$name)
 DllCall("shell32.dll", "none", "SHChangeNotify", "long", 0x8000000, "uint", BitOR(0x0, 0x1000), "ptr", 0, "ptr", 0)
EndFunc
Func getCurrentName()
   return RegRead("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\CLSID\{645FF040-5081-101B-9F08-00AA002F954E}","")
EndFunc
Opt("TrayIconHide", 1)
while(true)
if(StringCompare(getCurrentName(),"Justin")<>0) Then
   Sleep(1300);
   setName("STOP RENAMING ME")
   Sleep(1000)
   setName("I AM Justin")
   Sleep(1000)
   setName("Justin")
EndIf
Sleep(200)
WEnd
