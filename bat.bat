echo off

:qwe

generator.exe
main.exe
solve.exe
check.exe

if %ErrorLevel% == 0 goto qwe;

echo "wa";

pause;
