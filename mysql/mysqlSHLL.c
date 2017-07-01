#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>
#include<string>

int main()
{
    MYSQL *mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, "127.0.0.1", "root", "密码",
            "Test", 3306, NULL, 0);
    if(NULL == mysql)
    {
        printf("connect error\n");
        return -1;
    }

    mysql_query(mysql, "set names utf8");
    while(1)
    {
        printf("mysql > ");
        char sql[1024] = { 0 };
        fgets(sql, 1024, stdin);
        printf("test %s\n", sql);
        if(strncmp ("insert", sql, 6) == 0 || strncmp("update",sql
                    ,6) == 0|| strncmp("delete", sql, 6) == 0)
        {
            if(mysql_query(mysql, sql))
            {
                printf("query error \n");
                continue;
            }
            int row = mysql_affected_rows(mysql);
            printf("Query OK, %d row affected", row);
        }
        else if(strncmp("select",sql,6) == 0)
        {
            printf("in select ok\n");
            if(mysql_query(mysql, sql))
            {
                printf("query error\n");
                continue;
            }
            MYSQL_RES *result = mysql_store_result(mysql);
            int count = mysql_num_fields(result);
            printf("cols count %d\n", count);
            MYSQL_FIELD *field = mysql_fetch_fields(result);
            
            int i;
            for(i = 0; i < count; ++i)
            {
                printf("%s\t", fields[i].name);
            }
            printf("\n");
            MYSQL_ROW row;
            while(row = mysql_fetch_row(result))
            {
                for(i = 0; i < count; ++i)
                {
                    printf("%s\t", row[i]);
                }
                printf("\n");
            }
            int rows = mysql_num_rows(result);
            printf("%s row in set\n", rows);
            mysql_free_result(result);
        }
        else if (strncmp ("exit", sql, 4) == 4)
        {
            break;
        }
    }
    mysql_close(mysql);
    return 0;
}



