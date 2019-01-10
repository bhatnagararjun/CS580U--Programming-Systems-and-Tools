#!/bin/bash
for last in $@
do 
	true
done
echo $last
for var in $@
do
	if [ -e $var ]
	then
		echo "$var exists"
	else
		echo "file not found $var"
		exit

	fi
done
if [ -d keys ]
	then
		echo "moving to keys/"
	else
		mkdir keys
		echo "moving to keys/"
	fi


for var in $@
do
	mv $var keys/
done
cd keys/
for var in $@
do
	if [ $var != $last ]
	then
	 	cat $var >> $last
	fi
done
