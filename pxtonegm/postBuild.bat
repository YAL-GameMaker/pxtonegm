@echo off
set dllPath=%~1
set solutionDir=%~2
set projectDir=%~3
set arch=%~4
set config=%~5

echo Running post-build for %config%

set extName=pxtonegm
set dllName=pxtonegm

set gmlDir8=%solutionDir%pxtonegm81
set gmlDir14=%solutionDir%pxtonegm.gmx
set gmlDir22=%solutionDir%pxtonegm_yy
set gmlDir23=%solutionDir%pxtonegm_23

set ext8=%gmlDir8%
set ext14=%gmlDir14%\extensions\%extName%
set ext22=%gmlDir22%\extensions\%extName%
set ext23=%gmlDir23%\extensions\%extName%

set dllRel=%dllName%.dll
set cppRel=%dllName%.cpp
set cppPath=%ext23%\%cppRel%
set gmlPath=%ext14%\*.gml
set docName=%extName%.html
set docPath=%solutionDir%export\%docName%

echo Copying documentation...
if not exist "%gmlDir23%\datafiles" mkdir "%gmlDir23%\datafiles"
copy /Y %docPath% "%gmlDir23%\datafiles\%docName%"
if not exist "%gmlDir22%\datafiles" mkdir "%gmlDir22%\datafiles"
copy /Y %docPath% "%gmlDir22%\datafiles\%docName%"
if not exist "%gmlDir14%\datafiles" mkdir "%gmlDir14%\datafiles"
copy /Y %docPath% "%gmlDir14%\datafiles\%docName%"

where /q gmxgen
if %ERRORLEVEL% EQU 0 (
	
	echo Combining the source files...
	type "%projectDir%*.h" "%projectDir%*.cpp" >"%cppPath%" 2>nul
	
	echo Running GmxGen...
	
	gmxgen "%ext23%\%extName%.yy" ^
	--copy "%dllPath%" "%dllRel%:%arch%" ^
	--copy "%gmlPath%" "*.gml"

	gmxgen "%ext22%\%extName%.yy" ^
	--copy "%dllPath%" "%dllRel%:%arch%" ^
	--copy "%cppPath%" "%cppRel%" ^
	--copy "%gmlPath%" "*.gml"
	
	gmxgen "%ext14%.extension.gmx" ^
	--copy "%dllPath%" "%dllRel%:%arch%" ^
	--copy "%cppPath%" "%cppRel%"

	gmxgen "%ext8%\%extName%.gmxgen81" ^
	--copy "%dllPath%" "%dllRel%:%arch%" ^
	--copy "%cppPath%" "%cppRel%" ^
	--copy "%ext23%\%extName%.gml" "%extName%_core.gml" ^
	--gmk-loader pxtone_init_wrapper^
	--strip-cc --disable-incompatible

) else (

	echo Copying DLLs...
	if "%arch%" EQU "x64" (
		copy /Y "%dllPath%" "%ext23%\%dllName%_x64.dll"
	) else (
		copy /Y "%dllPath%" "%ext22%\%dllRel%"
		copy /Y "%dllPath%" "%ext23%\%dllRel%"
		copy /Y "%dllPath%" "%ext14%\%dllRel%"
	)
	
	echo Copying GML files...
	robocopy %ext14% %ext22% *.gml /L >nul
	robocopy %ext14% %ext23% *.gml /L >nul

	echo postBuild.bat: Warning N/A: Could not find GmxGen - extensions will not be updated automatically. See https://github.com/YAL-GameMaker-Tools/GmxGen for setup.
)