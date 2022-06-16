# include <fcntl.h>
# include <types.h> /* if present in sys directory use "sys\\types.h" */
# include <stat.h> /* if present in sys directory use "sys\\stat.h" */
# include <stdlib.h>
# include <stdio.h>
int main( )
{
char buffer[ 512 ], source [ 128 ], target [ 128 ] ;
int inhandle, outhandle, bytes ;
printf ( "\nEnter source file name" ) ;
gets ( source ) ;
inhandle = open ( source, O_RDONLY | O_BINARY ) ;
400 Let Us C
if ( inhandle == -1 )
{
puts ( "Cannot open file" ) ;
exit ( 1 ) ;
}
printf ( "\nEnter target file name" ) ;
gets ( target ) ;
outhandle = open ( target, O_CREAT | O_BINARY | O_WRONLY,
S_IWRITE ) ;
if ( outhandle == -1 )
{
puts ( "Cannot open file" ) ;
close ( inhandle ) ;
exit ( 2 ) ;
}
while ( 1 )
{
bytes = read ( inhandle, buffer, 512 ) ;
if ( bytes > 0 )
write ( outhandle, buffer, bytes ) ;
else
break ;
}
close ( inhandle ) ;
close ( outhandle ) ;
return 0 ;
}
