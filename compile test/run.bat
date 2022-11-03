@echo off

set res=1
set prog=[Program]
echo %%G | findstr "connection" project.gpj >nul && set res=0

IF %res% equ 1 (
for /f "delims=" %%a in (project.gpj) do (
echo %%a>>a.txt
IF %%a == %prog% echo 		-Idevice>>a.txt
echo %prog% %%a
)

del project.gpj
ren a.txt project.gpj

echo device\sc_linkerdr.ld>> project.gpj
echo device\sc_startup.850>> project.gpj
echo device\dr7f701649_irq.h>> project.gpj
echo device\sc_intprg.c>> project.gpj
echo device\iodefine.h>> project.gpj
echo connection\connection.gpj>> project.gpj
) ELSE (
echo All files were already configured )

start C:\GHS\V800.V2015.1.7\multi_616\mprojmgr.exe default.gpj
