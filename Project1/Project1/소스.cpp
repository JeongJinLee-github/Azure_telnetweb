#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	MYSQL mysql;       // ����ü ����
	MYSQL_RES *myresult;    // ������ ����  ��ü ������ �����ͷ� ���
	MYSQL_ROW row;         // ���ڵ� ������ ���� ������ ���ڵ� ���� �ϳ��ϳ� ����

	unsigned int num_fields;
	unsigned int num_rows;
	char * string_query;

	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "192.168.1.20:3306", "admin", "blackbird7",
		"world", 0, NULL, 0))
		fputs("mysql connect success!\n", stdout);
	//���������ͼ��� �����ҷ��� ����ip�� �ܺο��� ���� �� ����. // �ܺ� ip �־�� �Ѵ�.
	else
	{
		fputs("mysql connect error!\n", stdout);
		exit(1);
	}
	string_query = "select * from testtable";    // ���̺� �� ��� ���ڴ�.
	mysql_query(&mysql, string_query);         //  �������ش�. Mysql ����
	myresult = mysql_store_result(&mysql);
	// ����� ��ü�� ����ȴ�. �����ͷ� ������ ���ؼ� ������� �޴´�.
	while (row = mysql_fetch_row(myresult))
		// ���� ���ڵ� ������ ���� ���Ϲ����� �ҷ� �´�. ���ڵ尪 ������ ����.
		printf("%s\t %s\n", row[0], row[1], row[2]);
	//������ ���̽� �ʵ� ����    
	//�� �ʵ� ��ҵ��� �ҷ� �´�. ������ Ÿ�� ���ڿ��� �޴´�. 
	//���ڷ� ��ȯ�Ϸ��� ����ü�� ���� ��ȭ�ؾ� �ȴ�. 
	mysql_free_result(myresult);
	mysql_close(&mysql);     // �����Ҷ�
	return 0;
}
