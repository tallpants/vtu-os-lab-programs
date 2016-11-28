# Shell script that accepts two file names as arguments, checks if the permissions
# for these files are identical and if the permissions are identical, outputs the
# common permissions, otherwise outputs each file name followed by its permissions.

if [ $# -ne 2 ]
then
    echo "Invalid Arguments"
elif [ ! -e $1 -o ! -e $2 ]
then
    echo "Files do not exist"
else
    per1=`ls -l $1 | cut -c 2-10`
    per2=`ls -l $2 | cut -c 2-10`

    if [ $per1 = $per2 ]
    then
        echo "Identical permissions: $per1"
    else
        echo "Permissions are not identical"
        echo "$1 permissions: $per1"
        echo "$2 permissions: $per2"
    fi
fi