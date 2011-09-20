#!/bin/bash
Path="/bin:/usr/local/bin:/usr/bin:/usr/sbin"
export Path

hello()
{
  printf "HelloWorld %s\n" $1
}

$PRINTF "echo" "HelloWorld"

read -p "You Name:" name


#call hellofunction
hello $name




for line in $name
 do echo $line;
done
len=${#name}
for ((i=0;i<len;i=i+1))
 do echo $i;
done 

if [  `echo $name | grep '[0-9]'` ] ; then
 echo "name has Num"
else
 echo "name no Num "
fi
