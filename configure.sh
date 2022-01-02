#!/bin/bash 


# CMAKE_EXPORT_COMPILE_COMMANDS=1: 
#    Output compile_commands.json for clangd and further coc.nvim
# GLFW_BUILD_DOCS=OFF:
#    Do not build documents
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DGLFW_BUILD_DOCS=OFF -S ./ -B ./out/build

# Copy the compile_commands.json from build dir to root dir, so coc.nvim can 
# read the file and parse the code correctly
cp ./out/build/compile_commands.json ./

