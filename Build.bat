@echo off
cls


set source=src\Dungeon.cpp

set common_linker_flags= /incremental:no /opt:ref /DYNAMICBASE

set disapled_warnings= /wd4100 /wd4702 /wd4201 /wd4127 /wd4189 /wd4065 /wd4102

set defs= /DSLOW /DX86


if not exist "bin\" mkdir "bin"

call headache %source%

pushd bin
cl "../%source%" /we4062 /MT /W4 /WX /Od /Oi %disapled_warnings% %defs% /nologo /Zi /std:c++17 /link %common_linker_flags%
popd