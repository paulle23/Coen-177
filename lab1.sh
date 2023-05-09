# Name: <Paul Le> 
# Date: <9/23/21> (the day you have lab) 
# Title: Lab1 - task
# Description: This program computes the area of a rectangle using inputted height and width
#!/bin/sh
echo Executing $0 #$0 = name of shell program
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME #path name of home directory
echo "USER="$USER #username
echo "PATH="$PATH #path environment variable value
echo "PWD="$PWD #current directory path
echo "\$\$"=$$ #$$ = process id of current process
user=`whoami`
#user and numusers are variables that are created
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "ple" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!"
        exit 1 
fi
response="Yes"
while [ $response != "No" ]
do
   echo "Enter height of rectangle: "
   read height
   echo "Enter width of rectangle: "
   read width
   area=`expr $height \* $width`
   echo "The area of the rectangle is $area"
   echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response
done
