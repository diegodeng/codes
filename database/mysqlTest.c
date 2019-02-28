#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int args, char *argv[])
{
	MYSQL m_conn;
	int ret  = 0;
	
	mysql_init(&m_conn);
	printf("init MYSQL success\n");
	
	if(mysql_real_connect(&m_conn,"localhost","root","root123","db",0,NULL,0)){
		printf("connect mysql successful\n");
		ret = mysql_query(&m_conn,"insert into t1 values(10,'Tony')");
		if(!ret){
			printf("insert %lu,rows \n",(unsigned long)mysql_affected_rows(&m_conn));
		}
		else{
			printf("insert error\n");
		}
	}
	//delete
	char* deleteData = "delete from t1 where a=3";
	ret = mysql_real_query(&m_conn, deleteData,(unsigned int)strlen(deleteData));
	if(!ret){
		printf("delete successful\n");
	}
	else{
		printf("delete error\n");
	}
	 //show all data
	MYSQL_ROW row;
	MYSQL_RES *res;
	int t;
	char *allData = "select * from t1";
	ret = mysql_real_query(&m_conn, allData, (unsigned int)strlen(allData));
	res = mysql_store_result(&m_conn); //
	while(row=mysql_fetch_row(res)){
		for(t=0; t<mysql_num_fields(res); t++)
		{
			printf("%s\t",row[t]);
		}
		printf("\n");
	}	
 
	mysql_close(&m_conn);
	return ret;
}
