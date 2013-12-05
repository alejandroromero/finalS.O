#include <stdlib.h>
#include <stdio.h> 


int desp;
 
int main(int argc,char **argv)

{
 
desp = remove(argv[1]);
 
if(desp!=0)

{
 
printf("Error, El archivo no existe\n");
 
return(EXIT_FAILURE); 

}
 
return(EXIT_SUCCESS);
 
}
