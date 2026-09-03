@echo off
setlocal

call build.bat

set "VICEPATH=%userprofile%\Desktop\vice\bin\x64sc.exe"

call %VICEPATH% build\graphicsmode.prg

endlocal