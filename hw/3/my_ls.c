#include "my_ls.h"

/*=================================
	GET FILETYPE
=================================*/
char get_filetype(int m)
{
	char c;
	if (S_ISREG(m))
		c = '-';
	else if (S_ISCHR(m))
		c = 'c';
	else if (S_ISDIR(m))
		c = 'd';
	else if (S_ISBLK(m))
		c = 'b';
	else
		c = '?';
	return c;
}


/*=================================
	GET PERMISSIONS
=================================*/
char* rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
char* get_permissions(char* buf, int m)
{	
	buf[0] = get_filetype(m);
	strcpy(&buf[1], rwx[(m>>6)&7]);
	strcpy(&buf[4], rwx[(m>>3)&7]);
	strcpy(&buf[7], rwx[(m)&7]);
	buf[10] = '\0';
	return buf;
}


/*=================================
	GET USERNAME
=================================*/
char* get_UserName(uid_t uid)
{
	struct passwd* pw = getpwuid(uid);
	return pw->pw_name ? pw->pw_name : "";
}


/*=================================
	GET GROUPNAME
=================================*/
char* get_GroupName(gid_t gid)
{
	struct group* grp = getgrgid(gid);
	return grp->gr_name ? grp->gr_name : "";
}


/*=================================
	GET LAST MODIFIED TIME
=================================*/
char* get_last_modified(char* buf, struct stat ent_stat, int sz)
{
	strftime(buf, sz, "%b %d %k:%M", localtime(&ent_stat.st_mtime));
	return buf;
}


/*=================================
	GET VERBOSE INFORMATION
=================================*/
void get_verbose(char* d_name, struct stat ent_stat)
{
	char permissions[11], last_modified[200]; 
	printf("%s %2hu %s  %s  %4lld %s %s\n", get_permissions(permissions, ent_stat.st_mode), ent_stat.st_nlink, 
											get_UserName(ent_stat.st_uid), get_GroupName(ent_stat.st_gid), ent_stat.st_size, 
											get_last_modified(last_modified, ent_stat, 200), d_name);
}


int do_ls(char* dirName)
{
	DIR* dir;
	struct dirent* entry;
	struct stat ent_stat;
	char* dirs[1024];
	int dirCount = 0;
	char path[1024];

	if (!(dir = opendir(dirName)))
		return -1;
	
	// loop through directory 
	while ((entry = readdir(dir)))
	{
		snprintf(path, sizeof(path), "%s/%s", dirName, entry->d_name);
		stat(path, &ent_stat);
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
			get_verbose(entry->d_name, ent_stat);	
		
		// add directories found into array
		if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0)
			dirs[dirCount++] = entry->d_name;
	}
	
	// loop through array of found directories for recursion
	int i = 0;
	while (i < dirCount)
	{
		snprintf(path, sizeof(path), "%s/%s", dirName, dirs[i]);
		printf("\n%s:\n", path);
		do_ls(path);
		i++;
	}

	closedir(dir);
	return 1;
}

int main(int argc, char* argv[])
{
	char* filename = argv[1];
	
	if (filename == NULL)
		filename = ".";
	
	do_ls(filename);

	return 0;
}
