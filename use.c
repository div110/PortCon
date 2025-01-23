#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char input[4];
int lines;
int max_length;
int length;



void help(){
printf("\nList of availible inputs:\nhelp - show this dialog\nUSE - USE Flag configuration mode\nVIDEO_CARDS - VIDEO_CARDS configuration mode\nMAKEOPTS - MAKEOPTS configuration mode\nACCEPT_LICENSE - ACCEPT_LICENSE configuration mode\nexit - exit program without saving changes\n\n");
}


////////////////////////////////////////////////////////////////////
void list(char category[15],char pcontents[lines][max_length])//////
{///////////////////////////////////////////////////////////////////
}///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


void use(){
do
{
	printf("USEconf: ");
	scanf("%s",input);
	if(strcmp(input,"list")==0){}
}
while(strcmp(input,"exit")!=0);
for(int i=0;i<4;i++){input[i]='\n';}
}
















int main(int argc, char* argv[]){

FILE *file;
file = fopen("/etc/portage/make.conf","r");
char buf[10000];
fscanf(file,"%[^#]",buf);
printf("%s\n", buf);

lines=0;
length=0;
max_length=0;
for(int i=0;i<strlen(buf);i++){
	length++;
	if(buf[i]=='\n'){lines++;length=0;}
	if(length>max_length){max_length=length;}
}
char contents[lines][max_length];


//filling matrix with '\0'
for(int i=0;i<lines;i++){for(int j=0;j<max_length;j++){contents[i][j]='\0';}}



lines=0;
int index=0;
for(int loko=0;loko<strlen(buf);loko++){
if(buf[loko]=='\n'){lines++;index=0;}
else{contents[lines][index]=buf[loko];
index++;
//printf("%c\n",contents[lines][index]);
}
}





printf("lines: %d\nlongest line: %d characters\n",lines, max_length);

do
	{
	printf("tool: ");
	scanf("%s",input);
	if(strcmp(input,"USE")==0){use();}
	else if(strcmp(input,"VIDEO_CARDS")==0){}
	else if(strcmp(input,"MAKEOPTS")==0){}
	else if(strcmp(input,"ACCEPT_LICENSE")==0){}
	else if(strcmp(input,"help")==0||strcmp(input,"h")==0){help();}
	else if(strcmp(input,"exit")!=0){printf("unrecognized; type 'help' to see availible commands\n");}
	}
	while(strcmp(input,"exit")!=0); //this is stupid non-sense




return 0;}
