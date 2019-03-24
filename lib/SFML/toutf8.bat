@echo off

:WHILE
	if "%1" == "" goto END

	for %%f in (%1) do (
		echo %%f
		nkf32 -wO %%f %%f.utf8
	)
	shift
	goto WHILE
:END