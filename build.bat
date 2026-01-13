@echo off
cd fontgen
echo Generating font binary
call node generator.js
cd ..
echo Compiling main.c
oscar64 -n src/main.c -o=build/graphicsmode.prg