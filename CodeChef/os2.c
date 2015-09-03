#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <dirent.h>
#include <sys/resource.h>

int min(int,int);

struct INFO
{
char name[100];
}names[100];

void permission(struct stat *s_buffer,char *perm_dir)
{
	int i=0;
	if(s_buffer->st_mode & S_IFDIR)
		perm_dir[i++]='d';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IRUSR)
		perm_dir[i++]='r';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IWUSR)
		perm_dir[i++]='w';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IXUSR)
		perm_dir[i++]='x';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IRGRP)
		perm_dir[i++]='r';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IWGRP)
		perm_dir[i++]='w';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IXGRP)
		perm_dir[i++]='x';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IROTH)
		perm_dir[i++]='r';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IWOTH)
		perm_dir[i++]='w';
	else
		perm_dir[i++]='-';
	if(s_buffer->st_mode & S_IXOTH)
		perm_dir[i++]='x';
	else
		perm_dir[i++]='-';
	perm_dir[i]='\0';
}
int main(int argc, char const *argv[])
{
	int i,hflag,flag,temp,j,k,len,count;
	struct stat s_buffer;
	struct passwd *pw;
	struct group *gr;
	char tempdate[100],date[100],tempStr[100],perm_dir[10];
	struct dirent **namelist;
   	int n;
   	n = scandir(".", &namelist, 0,alphasort);
   	temp=n;
   	
   	hflag=0;
   	
    if(argc==3){
    	if(!strcmp(argv[2],"-a"))
              hflag=1;
      }

   	for(count=0,i=0;i<n;i++)
   	{    if(namelist[i]->d_name[0]=='.' && hflag==0)
   	       continue; 
   		 strcpy(names[count].name,namelist[i]->d_name);
   	     count++;
   	}
    //sorting the file names
    for(i=0;i<(count-1);i++)
    {
    	for(j=i+1;j<count;j++)
    	{
    	  flag=0;
    	  len=min(strlen(names[i].name),strlen(names[j].name));
    	  for(k=0;k<len;k++)
    	  {
    	   if(names[i].name[k]>=97 && names[j].name[k]<=90){
               if((names[i].name[k]-names[j].name[k])>32)
               	  flag=1;
    	    }
    	   else if(names[i].name[k]<=90 && names[j].name[k]>=97){
    	   	    if((names[i].name[k]-names[j].name[k])>=-32)
    	   	    	 flag=1;
    	   }
    	   else if(names[i].name[k]>names[j].name[k])
                  flag=1;
           if(flag==1)
           {
           	strcpy(tempStr,names[i].name);
            strcpy(names[i].name,names[j].name);
            strcpy(names[j].name,tempStr);
           } 
           if(names[i].name[k]!=names[j].name[k])
           	 break;
    	  }
    	}
    }

   	if(n<0)
   		perror("scandir");
   	else
   	{
		for(i=0;i<count;i++)
		{
			if(stat(names[i].name,&s_buffer)==-1)
			{
				perror("stat");
				exit(EXIT_FAILURE);
			}

			permission(&s_buffer,perm_dir);
			printf("%s ",perm_dir);
			printf("%2ld ",(long)s_buffer.st_nlink);
			//printf("Username: ");
			pw=getpwuid(s_buffer.st_uid);
			printf("%s ",pw->pw_name);
				//printf("Group name: ");
			gr=getgrgid(s_buffer.st_gid);
			printf("%s ",gr->gr_name);
			printf("%5ld ",(long)s_buffer.st_size);
			strcpy(tempdate,ctime(&s_buffer.st_mtime));
			for ( j = 4; j <=15; ++j)
				date[j-4]=tempdate[j];
				date[j-4]='\0';
			printf("%s ",date);
			printf("%s\n",names[i].name);
		}
	}
	return 0;
}

int min(int a,int b)
{
 if(a<b)
 	 return a;
 return b;
}