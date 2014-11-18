@echo off
setlocal enableextensions
for /f "delims=" %%p in ('type "%~dp0path.txt"') do set "ic=%%p"
if not exist "%ic%" (
	echo Save the path to Impossible Creatures in path.txt before running this script.
	goto :end
)

if exist "%ic%\InsectModOriginal.dll" move "%ic%\InsectModOriginal.dll" "%ic%\InsectMod.dll" > nul 2> nul || (
	echo Failed to uninstall the patch. Ensure that you are running this script as an
	echo administrator.
	goto :end
)

echo Success!
:end
pause
