#!/bin/sh
HOST='127.0.0.1'
PORT='7000'
USER='Anonymous'
PASSWD=''

ftp -n $HOST -p $PORT <<END_SCRIPT
quote USER $USER
quote PASS $PASSWD
pwd
ls
ls /home/maxim/epitech_project
quit
END_SCRIPT
exit 0