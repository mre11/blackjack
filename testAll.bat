set config=Release
if "%1"=="-d" (set config=Debug)
echo Running unit tests for %config% configuration
%~dp0bin\x64\%config%\utBlackjack.exe
