@echo off
setlocal enableextensions
for /f "delims=" %%p in ('type "%~dp0path.txt"') do set "ic=%%p"
if not exist "%ic%" (
	echo Save the path to Impossible Creatures in path.txt before running this script.
	goto :end
)

if not exist "%ic%\InsectModOriginal.dll" move "%ic%\InsectMod.dll" "%ic%\InsectModOriginal.dll" > nul 2> nul || (
	echo Failed to install the patch. Ensure that you are running this script as an
	echo administrator.
	goto :end
)
copy "%~dp0mod.dll" "%ic%\InsectMod.dll" > nul 2> nul || (
	echo Failed to install the patch. Ensure that you are running this script as an
	echo administrator.
	goto :end
)

echo Success!
:end
pause
