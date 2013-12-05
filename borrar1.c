#include <stdio.h> 
#include <stdlib.h> 
#define nullptr NULL 
static void dltcomm(FILE* txtfile)
{
FILE* dos;
FILE* texto;
dos=fopen("/home/alejandro/salvarelculo/dos.text","w");

char ger;
while(ger=getc(txtfile)!=EOF){
if(ger=='/'){
ger=getc(txtfile);
if(ger=='/'){
ger=getc(txtfile);
 }
else if(ger=='*'){
ger=getc(txtfile);
 }
 }
else if(ger=='*'){
ger=getc(txtfile);
if(ger=='/'){
ger=getc(txtfile);
 }
 }
fputc(ger,dos);
 }
fclose(texto);
fclose(dos);
 }
int main()
{
FILE* txtfile; 
txtfile=fopen("/home/alejandro/salvarelculo/texto.txt","r"); 
dltcomm(FILE* txtfile); 
if(txtfile==nullptr)return EXIT_FAILURE; 
printf(txtfile); 
return EXIT_SUCCESS; 
}

