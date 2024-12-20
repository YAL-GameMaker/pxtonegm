@echo off

if not exist "pxtonegm-for-GMS1" mkdir "pxtonegm-for-GMS1"
cmd /C copyre ..\pxtonegm.gmx\extensions\pxtonegm.extension.gmx pxtonegm-for-GMS1\pxtonegm.extension.gmx
cmd /C copyre ..\pxtonegm.gmx\extensions\pxtonegm pxtonegm-for-GMS1\pxtonegm
cmd /C copyre ..\pxtonegm.gmx\datafiles\pxtonegm.html pxtonegm-for-GMS1\pxtonegm\Assets\datafiles\pxtonegm.html
cd pxtonegm-for-GMS1
cmd /C 7z a pxtonegm-for-GMS1.7z *
move /Y pxtonegm-for-GMS1.7z ../pxtonegm-for-GMS1.gmez
cd ..

if not exist "pxtonegm-for-GMS2\extensions" mkdir "pxtonegm-for-GMS2\extensions"
if not exist "pxtonegm-for-GMS2\datafiles" mkdir "pxtonegm-for-GMS2\datafiles"
if not exist "pxtonegm-for-GMS2\datafiles_yy" mkdir "pxtonegm-for-GMS2\datafiles_yy"
cmd /C copyre ..\pxtonegm_yy\extensions\pxtonegm pxtonegm-for-GMS2\extensions\pxtonegm
cmd /C copyre ..\pxtonegm_yy\datafiles\pxtonegm.html pxtonegm-for-GMS2\datafiles\pxtonegm.html
cmd /C copyre ..\pxtonegm_yy\datafiles_yy\pxtonegm.html.yy pxtonegm-for-GMS2\datafiles_yy\pxtonegm.html.yy
cd pxtonegm-for-GMS2
cmd /C 7z a pxtonegm-for-GMS2.zip *
move /Y pxtonegm-for-GMS2.zip ../pxtonegm-for-GMS2.yymp
cd ..

if not exist "pxtonegm-for-GMS2.3+\extensions" mkdir "pxtonegm-for-GMS2.3+\extensions"
if not exist "pxtonegm-for-GMS2.3+\datafiles" mkdir "pxtonegm-for-GMS2.3+\datafiles"
cmd /C copyre ..\pxtonegm_23\extensions\pxtonegm pxtonegm-for-GMS2.3+\extensions\pxtonegm
cmd /C copyre ..\pxtonegm_23\datafiles\pxtonegm.html pxtonegm-for-GMS2.3+\datafiles\pxtonegm.html
cd pxtonegm-for-GMS2.3+
cmd /C 7z a pxtonegm-for-GMS2.3+.zip *
move /Y pxtonegm-for-GMS2.3+.zip ../pxtonegm-for-GMS2.3+.yymps
cd ..

pause