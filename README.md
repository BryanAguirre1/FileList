HOME PROGRAMMING TEST
---------------------

Directory List
---------------------
Main function: this software lists the weight in bytes and name of all the files in a folder and converts it to a json file.

The program runs as follows on the command line:
listdir.exe c:/files

first the program needs a path.
then it enters a cycle to obtain only the name (without the path) and weight of the files, 
finally this element is added to the json and after exiting the cycle this file is created.

the json file will show something like this:

{
"files": [
     {"name":"texto1.txt","size":450},
     {"name":"texto2.txt","size":950}]}
