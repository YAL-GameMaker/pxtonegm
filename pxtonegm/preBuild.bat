@echo off
set dllPath=%~1
set solutionDir=%~2
set projectDir=%~3
set arch=%~4
set config=%~5

echo Running pre-build for %config%

where /q GmlCppExtFuncs
if %ERRORLEVEL% EQU 0 (
	echo Running GmlCppExtFuncs...
	GmlCppExtFuncs ^
	--prefix pxtonegm^
	--cpp "%projectDir%autogen.cpp"^
	--gml "%solutionDir%pxtonegm.gmx/extensions/pxtonegm/autogen.gml"^
	--gmk "%solutionDir%pxtonegm81/pxtonegm_autogen.gml"^
	%projectDir%pxtonegm.cpp
)