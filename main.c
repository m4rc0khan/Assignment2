#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	if(stat("text1",&stat1)==-1)
		printf("Erorr: file is not open.");
	else
		stat("text1",&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	if(stat("text2",&stat2)==-1)
		printf("Error: file is not open.");
	else
		stat("text2",&stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
if((int)stat1.st_size>(int)stat2.st_size)
	printf("text1 bigger than text2\n");
else if((int)stat1.st_size<(int)stat2.st_size)
	printf("text2 bigger than text1\n");
else
	printf("size is same\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	if(((int)stat1.st_blocks)>((int)stat2.st_blocks))
		printf("text1 is bigger\n");
	else if(((int)stat1.st_blocks)<((int)stat2.st_blocks))
		printf("text2 is bigger\n");
	else
		printf("block size are equal\n");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
time1 = localtime(&stat1.st_mtime);
int h_temp = time1->tm_hour;
int m_temp = time1->tm_min;
time2 = localtime(&stat2.st_mtime);

	if(h_temp > time2->tm_hour)
		printf("text2 is early\n");
	else if(h_temp < time2->tm_hour)
		printf("text1 is early\n");
	else if(m_temp < time2->tm_min)
		printf("text1 is early\n");
	else
		printf("text2 is early\n");
	

}


