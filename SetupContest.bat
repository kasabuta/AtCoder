@echo off
set /p CONTEST_NAME="Contest Name : "

set CONTEST_DIR=Question\%CONTEST_NAME%\
if not exist %CONTEST_DIR% (
    md %CONTEST_DIR%
)

set QINDEXIES=A B C D E F G Ex

setlocal enabledelayedexpansion
for %%i in (%QINDEXIES%) do (
::for /l %%i in (1,1,90) do (
    call set OUTPUT_FILE=%CONTEST_DIR%Question%CONTEST_NAME%%%i.cpp
    for /f "delims=" %%a in (Question\QuestionTemplate.cpp) do (
        set line=%%a
        set TEMP=!line:TITLE=%CONTEST_NAME%!
        set TEMP2=!TEMP:QINDEX=%%i!
        echo !TEMP2!>>!OUTPUT_FILE!
    )
)
for %%j in (%QINDEXIES%) do (
::for /l %%j in (1,1,90) do (
    call set OUTPUT_FILE2=%CONTEST_DIR%Question%CONTEST_NAME%%%j.h
    for /f "delims=" %%b in (Question\QuestionTemplate.h) do (
        set line2=%%b
        set TEMP2=!line2:TITLE=%CONTEST_NAME%!
        set TEMP22=!TEMP2:QINDEX=%%j!
        echo !TEMP22!>>!OUTPUT_FILE2!
    )
)

pause