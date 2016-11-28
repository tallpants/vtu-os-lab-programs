# Non-recursive shell script that accepts any number of arguments and
# prints them in the Reverse order, ( For example, if the script is
# named rargs, then executing rargs A B C should produce C B A on
# the standard output).

if [ $# -eq 0 ]
then
    echo "No arguments"
else
    echo "Number of arguments is $#"
    echo "The arguments are $@"
    
    for i in "$@"
    do
        rev=$i' '$rev
    done

    echo "The reverse is $rev"
fi