# VTU OS Lab Programs

All of the VTU OS lab problems with solutions and instructions and how to run it.

Hopefully it'll help some poor soul who needs it the way I did.

## Shell Programs

### 7A

*Non-recursive shell script that accepts any number of arguments and prints them in the Reverse order, ( For example, if the script is named rargs, then executing rargs A B C should produce C B A on the standard output).*

#### Execution:

Do `sh 7a_reverse_arguments.sh` followed by some arguments.

For example:

```shell
$ sh 7a_reverse_arguments.sh Hello World

Number of arguments is 2
The arguments are Hello World
The reverse is World Hello 
```

### 8A

*Shell script that accepts two file names as arguments, checks if the permissions for these files are identical and if the permissions are identical, outputs the common permissions, otherwise outputs each file name followed by its permissions.*

### Execution

```shell
$ touch f1
$ touch f2
$ sh 8a_permissions.sh f1 f2

Identical permissions: rw-rw-r--

$ chmod u+x f1
$ sh 8a_permissions.sh f1 f2

Permissions are not identical
f1 permissions: rwxrw-r--
f2 permissions: rw-rw-r--
```