@echo off
setlocal

call build.bat

set "VICEPATH=%userprofile%\Desktop\vice\x64sc.exe"

call %VICEPATH% build\graphicsmode.prg

endlocal