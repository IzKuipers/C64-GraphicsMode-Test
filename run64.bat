@echo off
setlocal

call build.bat

set "VICEPATH=%userprofile%\Desktop\vice\bin\x64sc.exe"

call node tools\uploadc64u.js

endlocal