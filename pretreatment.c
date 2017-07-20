#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>

int inputData(const char* data,int* ID ,char* Name ,int* Age ,int * sex )
{
    char data1[1024] = { 0 };
    strcpy(data1, data);

    char *p = strtok(data1, " ");
    if(NULL == p)
        return -1;

    *ID = atoi(p);
    p = strtok(NULL, " ");
    if(NULL == p)
        return -1;

    strcpy(Name, p);
    p = strtok(NULL, " ");    
    if(NULL == p)
        return -1;

    *Age = atoi(p);
    p = strtok(NULL, " "); 
    if(NULL == p)
        return -1;

    if(strcmp(p, "男") == 0)
    {   
        *sex = 1;
    }
    else if(strcmp(p, "女") == 0)
    {   
        *sex = 2;
    }
    else
    {
        return -1;
    }
    
    return 0;
}

int mysql(const char* ip, const char* user, const char* password, const char* database)
{
    MYSQL *mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, ip, user, password, database, 3306, NULL, 0);
    
    if(NULL == mysql)
    {
        printf("connect error \n");
        return -1;
    }

    //解决表格输入中文乱码问题
    mysql_query(mysql, "set names utf8");
    MYSQL_STMT *stmt = mysql_stmt_init(mysql);
    char *sql = "insert into Class  values(?,?,?,?,?)";
    mysql_stmt_prepare(stmt, sql, strlen(sql));
    
    MYSQL_BIND bind[5];

    int ID, Age, sex, i;
    MYSQL_TIME time ;
    char Name[1024] = { 0 };
    unsigned long Name_length;

    ID = 0;
    strcpy(Name, "空");
    Age = 0;
    
    char data[1024] = { 0 }; 

    while(1)
    {
        printf("input data (ID Name Age sex) >>");
        fgets(data, sizeof(data), stdin);
        strtok(data, "\n");

        if(strcmp(data, "exit") == 0)
        {
            printf("bey\n");
            return 0;
        }

        if(inputData(data, &ID, Name, &Age, &sex) != 0)
        {
            printf("Please re-enter\n");
            continue;
        }
        Name_length = (unsigned long)strlen(Name);
        
        bind[0].buffer_type = MYSQL_TYPE_LONG; 
        bind[0].buffer = (void *)&ID;
        bind[0].buffer_length = sizeof(ID);
        bind[0].is_null = (my_bool *)0;

        bind[1].buffer_type = MYSQL_TYPE_STRING;
        bind[1].buffer = (void *)Name;
        bind[1].buffer_length = strlen(Name);
        bind[1].is_null = (my_bool *)0;
        bind[1].length = &Name_length;
    
        bind[2].buffer_type = MYSQL_TYPE_LONG;
        bind[2].buffer = (void *)&Age;
        bind[2].buffer_length = sizeof(Age);
        bind[2].is_null = (my_bool *)0;

        bind[3].buffer_type =MYSQL_TYPE_DATE;
        bind[3].buffer = (char *)&time;
        bind[3].is_null = 0;
        bind[3].length = 0;

        bind[4].buffer_type = MYSQL_TYPE_LONG;
        bind[4].buffer = (void *)&sex;
        bind[4].buffer_length = sizeof(sex);
        bind[4].is_null = (my_bool *)0;

        mysql_stmt_bind_param(stmt, bind);

        //时间自己瞎j8弄吧
        time.year = 0000;
        time.month = 00;
        time.day = 00;
        time.hour = 00;
        time.minute = 00;
        time.second = 00;

        memset(data, 0, sizeof(data));

        if(mysql_stmt_execute(stmt))
        {
            printf("execute error\n");
            return -1;
        }
}
    mysql_close(mysql);
    return 0;
}
int main(int argc, char* argv[])
{
     if(mysql(argv[1], argv[2], argv[3], argv[4]))
     {
        printf("mysql error\n");
        return -1;
     }
    return 0;
}
