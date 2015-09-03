#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <dirent.h>
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
int compare(const void *a,const void *b)
{
	struct dirent *first=(struct dirent *)a;
	struct dirent *second=(struct dirent *)b;
	if(first->d_name[0]<=90 && second->d_name[0]>=97)
		 return -1;
	if(first->d_name[0]>=97 && second->d_name[0]<=90)
		return 1;
    return strcmp(first->d_name,second->d_name);

    /*
	if(((first->d_name[0])-(second->d_name[0]))==32)
	return 1;
	else if(((second->d_name[0])-(first->d_name[0]))==32)
	return -1;
	else
	return (-1)*strcmp(first->d_name,second->d_name);
    */
}
int main(int argc, char const *argv[])
{
	int i,temp,j;
	struct stat s_buffer;
	struct passwd *pw;
	struct group *gr;
	char tempdate[100],date[100],perm_dir[10];
	struct dirent **namelist;
   	int n;
   	n = scandir(".", &namelist, 0, alphasort);
   	qsort(namelist,n,sizeof(struct dirent),compare);
   	// for(i=0;i<n;i++)
   	// 	printf("%s\n",namelist[i]->d_name);
   	temp=n;
   	printf("total %d\n",n);
   	if(n<0)
   		perror("scandir");
   	else
   	{

		for(i=0;i<n;i++)
		{

			//puts(namelist[i]->d_name);
			//printf("%d\n",temp-n-1);
			if(stat(namelist[i]->d_name,&s_buffer)==-1)
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
			printf("%s\n",namelist[i]->d_name);
		}
	}
	return 0;
}