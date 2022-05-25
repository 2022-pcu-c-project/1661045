#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>
#include <stdio.h>

#pragma comment(lib, "C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib\\libmysql.lib")

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PW "programming"
#define DB_NAME "cprogramming"

int main()
{
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;
	int query_stat;

	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PW, DB_NAME, 3306, (char*)NULL, 0);

	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 1;
	}

	char* query = "show tables";
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
		return 1;
	}

	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		printf("%2s %2s %s\n", sql_row[0], sql_row[1], sql_row[2]);
	}
	mysql_free_result(sql_result);

	mysql_close(connection);

	return 0;
}