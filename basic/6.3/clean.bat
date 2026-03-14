@echo off
rem 只保留 *.cpp，其余文件全部删除（不含子文件夹）
set "self=%~nx0"
for /F "delims=" %%F in ('dir /B /A:-D ^| findstr /V /I "\.cpp$" ^| findstr /V /I /C:"%self%"') do (
    del /F /Q "%%F"
)
echo Done.
pause