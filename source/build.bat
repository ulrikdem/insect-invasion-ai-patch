@echo off
setlocal enableextensions
for /f "delims=" %%p in ('type "%~dp0..\path.txt"') do set "ic=%%p"
if not exist "%ic%" (
	echo Save the path to Impossible Creatures in ..\path.txt before running this
	echo script.
	goto :end
)

rem Set the path to Visual Studio's vcvarsall.bat script in the following line.
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" > nul 2> nul || (
	echo Failed to set up the Visual Studio environment. Ensure that the path is set
	echo correctly in this script.
	goto :end
)
cl /EHsc /DWIN32 "/I%ic%\SDK\Include" "/I%ic%\SDK\Include\stl" "%~dp0dll.cpp" /link /dll "/out:%~dp0..\mod.dll" > nul 2> nul || (
	echo Failed to compile the mod. Ensure that you have installed the RDN SDK and have
	echo fixed it with the fix.bat script.
	goto :end
)
del dll.obj "%~dp0..\mod.lib" "%~dp0..\mod.exp" 2> nul

echo Success!
:end
pause
