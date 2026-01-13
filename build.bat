@echo off
cd fontgen
echo.
echo Generating font binary
echo.
call node generator.js
cd ..
echo.
echo Compiling main.c
oscar64 -n src/main.c -o=build/graphicsmode.prg