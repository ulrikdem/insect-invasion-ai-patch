@echo off
setlocal enableextensions
for /f "delims=" %%p in ('type "%~dp0..\path.txt"') do set "ic=%%p"
if not exist "%ic%" (
	echo Save the path to Impossible Creatures in ..\path.txt before running this
	echo script.
	goto :end
)

python "%~dp0script.py" "%ic%" 2> nul || (
	echo Failed to fix the RDN SDK. Ensure that you are running this script as an
	echo administrator.
	goto :end
)

echo Success!
:end
pause
