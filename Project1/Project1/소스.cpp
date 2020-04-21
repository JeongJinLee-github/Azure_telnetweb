#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	MYSQL mysql;       // 구조체 선언
	MYSQL_RES *myresult;    // 포인터 선언  전체 값들을 포인터로 사용
	MYSQL_ROW row;         // 레코드 데이터 셋팅 한행이 레코드 값들 하나하나 쓴다

	unsigned int num_fields;
	unsigned int num_rows;
	char * string_query;

	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "192.168.1.20:3306", "admin", "blackbird7",
		"world", 0, NULL, 0))
		fputs("mysql connect success!\n", stdout);
	//서버데이터서버 접속할려면 내부ip는 외부에서 읽을 수 없다. // 외부 ip 넣어야 한다.
	else
	{
		fputs("mysql connect error!\n", stdout);
		exit(1);
	}
	string_query = "select * from testtable";    // 테이블 값 모두 보겠다.
	mysql_query(&mysql, string_query);         //  전달해준다. Mysql 한테
	myresult = mysql_store_result(&mysql);
	// 결과값 전체가 저장된다. 포인터로 쿼리문 통해서 결과값을 받는다.
	while (row = mysql_fetch_row(myresult))
		// 한행 레코드 끝날때 까지 와일문으로 불러 온다. 레코드값 없을때 까지.
		printf("%s\t %s\n", row[0], row[1], row[2]);
	//데이터 베이스 필드 개수    
	//각 필드 요소들을 불러 온다. 데이터 타입 문자열로 받는다. 
	//숫자로 변환하려면 구조체를 만들어서 변화해야 된다. 
	mysql_free_result(myresult);
	mysql_close(&mysql);     // 종료할때
	return 0;
}
