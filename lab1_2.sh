# Name: <Paul Le> 
# Date: <9/23/21> (the day you have lab) 
# Title: Lab1 - task
# Description: This program computes the area of a circle using inputted radius
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
   echo "Enter radius of the circle: "
   read radius
   echo "The area of the circle is" 
   echo "3.14 * $radius * $radius" | bc
   #bc is basic calculator, put | bc after quotes
   echo "Would you like to repeat for another circle [Yes/No]?"
        read response
done
