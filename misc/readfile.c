#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
/**
 *  struct dirent
	{
		long d_ino; // inode number 索引节点号 
		off_t d_off; // offset to this dirent 在目录文件中的偏移 
		unsigned short d_reclen; //length of this d_name 文件名长 
		unsigned char d_type; // the type of d_name 文件类型 
		char d_name [NAME_MAX+1]; // file name (null-terminated) 文件名，最长255字符 
	}	
	d_type表明该文件的类型：文件(8)、目录(4)、链接文件(10)
 * */

static int readFileList(char *path)
{
	DIR *dir;	
	struct dirent *ptr;
	char base[1024];
	
	if((dir = opendir(path)) == NULL){
		perror("opendir failed");
		return -1 ;
	}
	while((ptr = readdir(dir)) != NULL) 
	{
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0) {  ///current dir OR parrent dir
			continue;
			
		}else if(ptr->d_type == 8){ ///file
			printf("d_name:%s/%s\n",path,ptr->d_name);
			
		}else if(ptr->d_type == 10){  ///link file
			printf("d_name:%s/%s\n",path,ptr->d_name);
			
		}else if(ptr->d_type == 4 ){  ///dir
			memset(base,'\0',sizeof(base));
			strcpy(base,path);
			strcat(base,"/");
			strcat(base,ptr->d_name);
			readFileList(base);
		}else {
			printf("unkonw file type d_name:%s/%s\n",path,ptr->d_name);
		}
	}
	closedir(dir);
	return 0;
}


int main(int args,char *argv[])
{
	char base[1020];
	
	memset(base,'\0',sizeof(base));
//	sprintf(base,"%s",get_current_dir_name());
	getcwd(base,1024);
	printf("the current dir is %s \n",base);
	
	//memset(base,'\0',sizeof(base));
	strcpy(base,"/dev");
	readFileList(base);
	
	return 0;
}
