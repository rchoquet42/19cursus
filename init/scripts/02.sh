#!bin/bash
if [ "$EUID" -ne 0 ]; then 
	echo "Please run as root"
	exit 1
fi;
if [ $# -ne 1 ]; then
	echo "USAGE: 02 user_name"
	exit 1
fi;
passwd -l $1 > /dev/null 
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit 1
fi;
pkill -KILL -u $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit 1
fi;
userdel -r $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit 1
fi;
crontab -r -u $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit 1
fi;
echo "$1 SUCCESFULLY DELETED"
