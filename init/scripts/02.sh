if [ "$EUID" -ne 0 ]; then 
	echo "Please run as root"
	exit
if [ $# -ne 1 ]; then
	echo "USAGE: 02 user_name"
	exit
passwd -l $1 > /dev/null 
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit
pkill -KILL -u $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit
userdel -r $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit
crontab -r -u $1 > /dev/null
if [ $? -ne 0 ]; then
	echo "FAILED TO DELETE USER" $1
	exit
echo "$1 SUCCESFULLY DELETED"
