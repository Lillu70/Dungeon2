@echo off
cls

set source=gen.cpp

set common_linker_flags= /incremental:no /opt:ref

set disapled_warnings= /wd4100 /wd4702 /wd4201 /wd4127 /wd4189 /wd4065 /wd4102

cl "%source%" /MT /W4 /WX /Od /Oi %disapled_warnings% %defs% /nologo /Zi /std:c++17 /link %common_linker_flags%
