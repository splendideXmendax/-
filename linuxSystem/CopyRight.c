#include"../header.h"

int getfilesize(const char* filename)
{
    struct stat buf;
    stat(filename, &buf);
    return buf.st_size;
}
void copy_frag(const char* srcfile, const char* dstfile, int start, int len)
{
    FILE * fpi = fopen(srcfile, "r");
    FILE * fpo = fopen(dstfile, "w");
    
    fseek(fpi, start, SEEK_SET); //每个线程读取的起始位置不一样
    fseek(fpo, start, SEEK_SET);

    char buf[4096];
    while(len > 0)
    {
        int copylen = sizeof(buf) < len ? sizeof(buf) : len; //找小的那个
        int ret = fread(buf, 1, copylen, fpi);
        if(ret <= 0)break;
        fwrite(buf, ret, 1, fpo);
        len -= ret; 
    }
    fclose(fpi);
    fclose(fpo);


}

void  copyfile(int jobs,const char* srcfile, const char* dstfile)
{
    int filesize = getfilesize(srcfile);
    
    //13/4 = 
    int frag = filesize / jobs;

    int i;
    for(i = 0; i < jobs; ++i)
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            copy_frag(srcfile, dstfile, frag*i, frag);
            return ;
        }
    }
    //拷贝剩余的部分
    copy_frag(srcfile, dstfile, frag*i, filesize - frag*jobs);

    for(i = 0; i < jobs; ++i)
    {
        wait(NULL);
    }
}
// ./ a.out -j 4 srcfile dstfile
int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        printf("argument error\n");
        return 1;
    }

    int jobs = atoi(argv[2]);
    const char* srcfile = argv[3];
    const char* dstfile = argv[4];

    copyfile(jobs, srcfile, dstfile);
    return 0;
}
