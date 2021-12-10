@echo off

mkdir ..\build
pushd ..\build
cl  -Zi /w /EHsc /MTd ..\code\gl_snake.cpp ..\code\snake.cpp ..\code\SnakeEntity.cpp ..\code\glad.c ..\code\stb_image.cpp ..\code\ShaderLoader.cpp /link  /LIBPATH:..\lib OpenGL32.lib glfw3.lib user32.lib gdi32.lib Shell32.lib
popd