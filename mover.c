#include <string.h> 
#include <sys/stat.h>  
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char *argv[])
 
{
 
char mov; 

int f;

 
if(argc!=2)
 
{
 
printf("Error al ejecutar\n"); 

}
 
else
 
{

f = open(argv[1],O_RDONLY); 

if(f == -1) 

{
 
printf("Error al ejecutar\n"); 

}
 
close(f); 

remove(argv[1]);
 
} 

return 0; 

}
 // la logica simula el uso del fopen y fclose, ayuda de companeros en cuanto a como borrar el original, una vez cambiado//
