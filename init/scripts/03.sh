#!/bin/sh

echo $#
echo $1

if [ $# -eq  0 ]; then
	sudo apt-get install eclipse java
	sudo apt-get install code::blocks c
	sudo apt-get install pycharm python
	sudo apt-get install "komodo edit" html css
	sudo apt-get install geany shell
elif [[ $1 == *".java"* ]]; then
	eclipse $1
elif [[ $1 == *".c"* ]]; then
	code::blocks $1
elif [[ $1 == *".py"* ]]; then
	pycharm $1
elif [[ $1 == *".html"* ]]; then
	bluefish $1
elif [[ $1 == *".sh"* ]]; then
	geany $1
fi ;
