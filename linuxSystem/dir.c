#include"../header.h"
#include<dirent.h>

#if 0
int main()
{
    DIR* dir = opendir(".");
//#if 0
    struct dirent* entry = readdir(dir);
    printf("ino = %d, name = %s\n", (int)entry->d_ino, entry->d_name);

    entry = readdir(dir);
    printf("ino = %d, name = %s\n", (int)entry->d_ino, entry->d_name);
//#endif

    while(1)
    {

        struct dirent* entry = readdir(dir);
        if(entry == NULL) break;
        if(entry->d_name[0] == '.') continue;    
    
        printf("ino = %d, name = %s\n", (int)entry->d_ino, entry->d_name);

    }
         closedir(dir);
}
#endif
int sum;
void strDeal(char* buf1, char* buf2)
{
    strcat(buf1, "/");
    strcat(buf1, buf2);
}
void ergodicDir(char *dirl)
{
    DIR *dir = opendir(dirl);
    char a[100] = { 0 };
    strcpy(a, dirl);
    while(1)
    {
        struct dirent* entry = readdir(dir);

        if(entry == NULL)    break;
        if(strcmp(entry->d_name, ".") == 0)  continue;
        if(strcmp(entry->d_name, "..") == 0)  continue;
        if(entry->d_type == DT_DIR)
        {
            printf("dir :  %s\n",entry->d_name);
            strDeal(a , entry->d_name);

            ergodicDir(a);
            continue;
        }
        printf("%s \n", entry->d_name);
        ++sum;
    } 
}
int main(int argc, char* argv[])
{
    sum = 0;
    if(argc != 2)
    {
        return -1;
    }

    ergodicDir(argv[1]);
    printf("目录下普通文件个数为:%d\n", sum);
    return 0;
}
#if 0
struct Pointer
{
    int len;
    char * Poiint;
}
typedef Pointer Point

int strDeal(Pointer* DirName, char* sonDir)
{
    int sonDirLen;
    sonDirLen = strlen(sonDir) + 1;
    if(DirName->len < strlen(DirName) + sonDirLen)
    {
        free(DirName->Point);
        DirName->Point = NULL;
        DirName->Point = (char*)malloc(DirName->len + 2048);
        if(DirName == NULL)
        {
            perror("malloc");
            return -1;
        }
        DirName->len = DirName->len + 2048;
    }
    strcat(DirName->Point, "/");
    strcat(DirName->Point, sonDir);
}
int myCopyFile(const char* srcfile, int )
{





}
int ergodicDir(char* MyDir)
{
    DIR *dir = opendir(MyDir);
    Point* DirName;
    DirName = (Point*) malloc(sizeof(Point));
    DirName.Point = (char*)malloc(2048);
    DirName.len = 2048;

    strcpy(DirName, MyDir);
    while(1)
    {
        struct dirent* entry = readdir(MyDir);
        if(entry == NULL) break;
        if(strcmp(entry->d_name), "." == 0) continue;
        if(strcmp(entry->d_name), ".." == 0) continue;
        if(entry->d_type == DT_DIR)
        {
            strDeal(DirName, entry->d_name);
            ergodicDir(DirName.Point);
            continue ;
        }
    
    }
}


int main(int argc, char *argv[])
{
    
    

    ergodicDir(argv[3]);
    return 0;
}
#endif









