#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <zconf.h> 
#include <unistd.h>
#include <stdint.h>

char input[26];
uint8_t lines=0;
uint16_t max_length;
uint16_t length=0;
char * search;
bool file_write=false;

enum Sizes {
SIZE_CHAR=sizeof(char),
SIZE_INT=sizeof(int),
SIZE_PTR=sizeof(search)
};

enum Limits {STRING_LIMIT=25};


//mark upperlower
void upperLower(char * pString,bool option){
if(option==true){
for(int i=0;i<strlen(pString);i++){pString[i]=toupper(pString[i]);}
}
else{
for(int i=0;i<strlen(pString);i++){pString[i]=tolower(pString[i]);}
}
}



//mark help
void help(){
printf("\nList of availible inputs:\nhelp - show this dialog\nUSE - USE Flag configuration mode\nVIDEO_CARDS - VIDEO_CARDS configuration mode\nMAKEOPTS - MAKEOPTS configuration mode\nACCEPT_LICENSE - ACCEPT_LICENSE configuration mode\nexit - exit program without saving changes\n\n");
}
//mark action
void action(char * name){

	char name_true[strlen(name)+3];
	name_true[0]=' ';
	for(int i=0;i<strlen(name_true);i++)
	{name_true[i+1]=name[i];} //changing name to name_true fixes Xkde bug
	//name_true[strlen(name_true)]=' ';	
	name_true[strlen(name)+1]=' ';
	name_true[strlen(name)+2]='\0';
	

	char * pSubstring=strstr(search,name_true);
	if(pSubstring!=NULL)
		{
			//todo REMOVE CORRECT SPACES, sidequest
			//printf("Found:/%s/\n",name_true);
			for(int j=0;j<strlen(name_true)-1;j++){
			for(int i=0;i<(strlen(search)-(strlen(search)-(strlen(pSubstring))));i++){
			pSubstring[i]=pSubstring[i+1];
			}
		}

		}
	else
		{
			//printf("name_true:%s\n",name_true);
			//for(int i=0;i<strlen(name_true);i++)
			//{
				strcat(search,name_true);
			//}
			//printf("final:%s\n",search);
		//chyba	
		}
	char space_limit[4]={' ',' ',' ','\0'};
	char * spaces = strstr(search,space_limit);
	//char * after_spaces = spaces+strlen(space_limit);
	if(spaces!=NULL)
	{
		char * after_spaces = spaces+strlen(space_limit);

		for(int i=0; i<(strlen(after_spaces)+3);i++)
		{
		spaces[i]=after_spaces[i-2];
		}
	}
	
	//printf("now should clense\n");	
	

	//cleaning name_true
	for(int i=0;i<sizeof(name_true);i++){name_true[i]='\0';}

}

//mark use
void use(char pcontents[lines][max_length]){

//char * search;

	for(int i=0;i<lines;i++)
	{
		search = strstr(pcontents[i],"USE");
		if(search!=NULL){break;}
	}

search=search+5;
search[strlen(search)-1]=' ';

do
{
	printf("USEconf: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	if(strcmp(input,"list")==0||strcmp(input,"ls")==0||strcmp(input,"LIST")==0||strcmp(input,"LS")==0){printf("\n%s\n\n",search);}
	else if(strcmp(input,"clear")==0){system("clear");}
	else if(strcmp(input,"exit")!=0){action(input);printf("\n%s\n\n",search);}
}
while(strcmp(input,"exit")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';
}
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//mark cflags
void cflags(char pcontents[lines][max_length]){
for(int i=0;i<lines;i++){
search = strstr(pcontents[i],"CFLAGS");
if(search!=NULL){break;}
}

search = search + 8;
search[strlen(search)-1]=' ';

do{
	printf("CFLAGSconf: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	if(strcmp(input,"clear")==0){system("clear");}
	else if(strcmp(input, "list")==0||strcmp(input, "ls")==0||strcmp(input,"LIST")==0||strcmp(input,"LS")==0){printf("\n\n%s\n", search);}
	else if(strcmp(input, "exit")!=0){action(input);printf("\n%s\n\n",search);}
}
while(strcmp(input,"exit")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';
}
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//mark cxxflags
void cxxflags(char pcontents[lines][max_length]){
for(int i=0;i<lines;i++){
search = strstr(pcontents[i],"CXXFLAGS");
if(search!=NULL){break;}
}
search = search + 10;
search[strlen(search)-1]=' ';

do {
printf("CXXFLAGSconf: ");
fgets(input,STRING_LIMIT,stdin);
input[strlen(input)-1]='\0';
if(strcmp(input,"clear")==0){system("clear");}
else if(strcmp(input,"list")==0||strcmp(input,"ls")==0||strcmp(input,"LIST")==0||strcmp(input,"LS")==0){printf("\n%s\n\n", search);}
else if(strcmp(input,"same")==0||strcmp(input,"SAME")==0){action("${CFLAGS}");printf("\n%s\n\n",search);}
else if(strcmp(input,"exit")!=0){action(input);printf("\n%s\n\n",search);}
}
while(strcmp(input,"exit")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';

}
////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//mark makeopts
void makeopts(char pcontents[lines][max_length]){

//char * search;
	for(int i=0;i<lines;i++)
	{
		search = strstr(pcontents[i],"MAKEOPTS");
		if(search!=NULL){break;}
	}
if(search!=NULL){search=search+10;
search[strlen(search)-1]=' ';
}

do
{
	printf("MAKEOPTSconf: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	upperLower(input,false);
	if(strcmp(input, "list")==0){printf("\n%s\n\n",search);}
	else if(strcmp(input, "clear")==0){system("clear");}
	else if(strcmp(input,"exit")!=0){action(input);printf("\n%s\n\n",search);}
}
while(strcmp(input,"exit")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';
}

//mark video
void video_cards(char pcontents[lines][max_length]){
for(int i=0;i<lines;i++)
{
search = strstr(pcontents[i],"VIDEO_CARDS");
if(search!=NULL){break;}
}
if(search!=NULL){search=search+13;
search[strlen(search)-1]=' ';
}
do
{
	printf("VIDEO_CARDS: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	upperLower(input,false);
	if(strcmp(input, "list")==0){printf("\n%s\n\n",search);}
	else if(strcmp(input, "clear")==0){system("clear");}
	else if(strcmp(input,"exit")!=0){
		
		if(strcmp(input,"nvidia")==0){action(input);}
		else if(strcmp(input,"amdgpu")==0){action(input);}
		else if(strcmp(input,"nouveau")==0){action(input);}
		else if(strcmp(input,"radeonsi")==0){action(input);}
		else if(strcmp(input,"intel")==0){action(input);}
		else if(strcmp(input,"vc4")==0){action(input);}
		else if(strcmp(input,"virgl")==0){action(input);}
		else if(strcmp(input, "d3d12")==0){action(input);}
		else{printf("Unrecognized Flag :( \n");}

		printf("\n%s\n\n",search);}
}
while(strcmp(input,"exit")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';
}
//mark accept_license()
void accept_license(char pcontents[lines][max_length]){
for(int i=0;i<lines;i++){
search = strstr(pcontents[i],"ACCEPT_LICENSE");
if(search!=NULL){break;}
}
if(search!=NULL){search=search+16;
search[strlen(search)-1]=' ';
}
do
{
	printf("ACCEPT_LICENSE: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	upperLower(input,true);
	if(strcmp(input,"LIST")==0||strcmp(input,"LS")==0){printf("\n%s\n\n",search);}
	else if(strcmp(input,"CLEAR")==0){system("clear");}
	else if(strcmp(input,"EXIT")!=0){
		if(strcmp(input, "@GPL-COMPATIBLE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@FSF-APPROVED")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@MISC-FREE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@EULA")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@OSI-APPROVED")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@OSI-APPROVED-FREE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@OSI-APPROVED-NONFREE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@BINARY-REDISTRUTABLE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@FSF-APPROVED-OTHER")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@MISC-FREE-DOCS")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@FREE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@FREE-SOFTWARE")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"@FREE-DOCUMENTS")==0){action(input);printf("\n%s\n\n",search);}
		else if(strcmp(input,"HELP")==0||strcmp(input,"H")==0){
		printf("Recognized flags:\n @GPL-COMPATIBLE\n @FSF-APPROVED\n @MISC-FREE\n @EULA\n @OSI-APPROVED\n @OSI-APPROVED-FREE\n @OSI-APPROVED-NONFREE\n @BINARY-REDISTRUTABLE\n @FSF-APPROVED-OTHER\n @MISC-FREE-DOCS\n @FREE\n @FREE-SOFTWARE\n @FREE-DOCUMENTS\n");

		}
		else{
			printf("Flag not recognized\nUse it anyway?\n");
			char option[20];
			do{
				printf("\n[y/n]: ");
				scanf("%1s",option);
			}
			while(strlen(option)!=1);
			(strcmp(option,"y")==0) ? action(input) : printf("trashing...\n");
			printf("\n%s\n\n",search);
		}
		//action(input); printf("should print\n");
	}//printf("\n%s\n\n",search);
}
while(strcmp(input,"EXIT")!=0);
search[strlen(search)]='"';
search[strlen(search)+1]='\0';
input[1]='\0';
}





//mark main
int main(int argc, char* argv[]){
//uncomment
//if(getuid()!=0){printf("Tool requires Root privileges\n");exit(1);}
if(access("/etc/portage/make.conf", W_OK)!=0){printf("RW permission required: /etc/portage/make.conf\n");exit(1);}
system("clear");
//printing
printf("      ___          ___          ___      ___          ___          ___          ___     \n");
printf("     /\\  \\        /\\  \\        /\\  \\    /\\  \\        /\\  \\        /\\  \\        /\\__\\    \n");
printf("    /  \\  \\      /  \\  \\      /  \\  \\   \\ \\  \\      /  \\  \\      /  \\  \\      /  |  |   \n");
printf("   / /\\ \\  \\    / /\\ \\  \\    / /\\ \\  \\   \\ \\  \\    / /\\ \\  \\    / /\\ \\  \\    / | |  |   \n");
printf("  /  \\ \\ \\  \\  / /  \\ \\  \\  /  \\ \\ \\  \\  /  \\  \\  / /  \\ \\  \\  / /  \\ \\  \\  / /| |  |__ \n");
printf(" / /\\ \\ \\ \\__\\/ /__/ \\ \\__\\/ /\\ \\ \\ \\__\\/ /\\ \\__\\/ /__/ \\ \\__\\/ /__/ \\ \\__\\/ / | | /\\__\\\n");
printf(" \\/__\\ \\/ /  /\\ \\  \\ / /  /\\/_|  \\/ /  / /  \\/__/\\ \\  \\  \\/__/\\ \\  \\ / /  /\\/__| |/ /  / \n");
printf("      \\  /  /  \\ \\  / /  /    | |  /  / /  /      \\ \\  \\       \\ \\  / /  /     | / /  / \n");
printf("       \\/__/    \\ \\/ /  /     | |\\/__/\\/__/        \\ \\  \\       \\ \\/ /  /      |  /  /  \n");
printf("                 \\  /  /      | |  |                \\ \\__\\       \\  /  /       / /  /   \n");
printf("                  \\/__/        \\|__|                 \\/__/        \\/__/        \\/__/        \n");
printf("\n			PortCon is a simple CLI Portage configuration tool!\n\n");
FILE *file;
file = fopen("/etc/portage/make.conf","r");
fseek(file,0,SEEK_END);
uint8_t size = ftell(file);
//printf("\n\nX	%d    X\n\n",size);
fseek(file,0,SEEK_SET);
char *buf = calloc((size),SIZE_CHAR);
if(buf==NULL){printf("Couldn't allocate enough space\n");exit(1);}
//free(size);
fscanf(file,"%[^~]",buf);
//printf("buffer: \n%s\n", buf);
lines=0;
length=0;
max_length=0;
for(int i=0;i<strlen(buf);i++){
	length++;
	if(buf[i]=='\n'){lines++;length=0;}
	if(length>max_length){max_length=length;}
}
max_length = 2 * (max_length+200);
char contents[lines][max_length];


//filling matrix with '\0'
for(int i=0;i<lines;i++){for(int j=0;j<max_length;j++){contents[i][j]='\0';}}


lines=0;
uint16_t index=0;
for(int loko=0;loko<strlen(buf);loko++){
if(buf[loko]=='\n'){lines++;index=0;}
else{contents[lines][index]=buf[loko];
index++;
//printf("%c\n",contents[lines][index]);
}
}

free(buf);


//mark loop
do
	{
	printf("tool: ");
	fgets(input,STRING_LIMIT,stdin);
	input[strlen(input)-1]='\0';
	upperLower(input,true);
	//
	if(strcmp(input,"USE")==0){use(contents);}
	else if(strcmp(input,"VIDEO_CARDS")==0){video_cards(contents);}
	else if(strcmp(input,"MAKEOPTS")==0){makeopts(contents);}
	else if(strcmp(input,"ACCEPT_LICENSE")==0){accept_license(contents);}
	else if(strcmp(input,"CFLAGS")==0){cflags(contents);}
	else if(strcmp(input,"CXXFLAGS")==0){cxxflags(contents);}
	//
	else if(strcmp(input,"HELP")==0||strcmp(input,"H")==0||strcmp(input,"LIST")==0||strcmp(input,"LS")==0){help();}
	else if(strcmp(input,"SAVE")==0||strcmp(input,"S")==0){file_write=true;printf("Writing = true\n");}
	else if(strcmp(input,"CLEAR")==0){system("clear");}
	else if(strcmp(input,"EXIT")!=0){printf("unrecognized; type 'help' to see availible commands\n");}
	}
	while(strcmp(input,"EXIT")!=0); //this is stupid non-sense
if(file_write==false){
do{
printf("Save changes?[y/n]: ");
scanf("%1s",input);
upperLower(input,false);
}
while(strcmp(input,"y")!=0&&strcmp(input,"n")!=0);

switch(strcmp(input,"y")){
	case 0:
		file_write=true;break;
	default:break;
}
}
size=0;
for(int i=0;i<lines;i++){
for(int j=0;j<max_length;j++){
	if(contents[i][j]!='\0'){
		size++;
	}	
}
}
size=size+lines;
//printf("final size: %d\n",size);
buf=calloc(size+2,SIZE_CHAR);
if(buf == NULL){printf("Couldn't allocate enough memory\n");exit(1);}
uint32_t loko=0;
for(int i=0;i<lines;i++){


	for(int j=0;j<max_length;j++){
		if(contents[i][j]=='\0')
			
			{buf[loko]='\n';j=max_length;printf("\n");}
		
		else{buf[loko]=contents[i][j];printf("%c",contents[i][j]);}
	loko++;
	}
}
if(file_write){
file = fopen("/etc/portage/make.conf","w");
fprintf(file,"%s",buf);
}
fclose(file);
free(buf);
return 0;}

