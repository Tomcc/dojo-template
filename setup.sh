#!/bin/bash

git init 
git add .
git submodule add https://github.com/Tomcc/dojo2D.git
git submodule update --init --recursive

mkdir CMAKE_BUILD
cd CMAKE_BUILD
cmake ../
cd ../