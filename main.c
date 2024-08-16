
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

/*
***PROGRAM INFORMATION***
Home and School scoreCalc
Second Edition

@see readme.txt

Provides a ready-to-use average, standard deviation, and grade calculation program for home and school users using the linux console.

IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER SOFTWARE), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Author Myungjae Lee
Copyright (c) 2023- Myungjae Lee, All rights reserved
License LGPL (Linux GNU)
Version 2.6
Built with Replit IDE, C11 script
Using stdio.h, stdlib.h, unistd.h, time.h, math.h

Change Log
2023.12 v1.0
2024.07.04 v2.0
--changed to view multiple scores at once
2024.07.04 v2.1
--added kor, math, eng avg
2024.07.04 v2.1.1
--added imp avg
2024.07.05 v2.2
--added standard deviation
2024.07.05 v2.3
--added splash screen
--enhanced loading screen
2024.07.05 v2.4
--added abs eval grade
2024.07.05 v2.5
--bug fixes
--enhanced start screen
2024.07.05 v2.5.1
--enhanced loading screen
--added graphical title
2024.07.05 v2.5.2
--added program info
2024.07.10 v2.6
--bug fixes
*/

//initiate
int num;
char name[10][20];
int kor[10], math[10], soc[10], hist[10], sci[10], han[10], homeec[10], moral[10], eng[10];
float avga[];

//splash text randomize
void splashText() {
	srand((unsigned)time(NULL));
	int r = rand()%10 + 1;
	printf("\n개발자의 한마디 : \n");
	switch(r) {
		case 1:
			printf("쉽고 빠르게 성적을 계산!\n");
			break;
		case 2:
			printf("test message 1\n");
			break;
		case 3:
			printf("Hello World!\n");
			break;
		case 4:
			printf("다양한 교과목 편성\n");
			break;
		case 5:
			printf("...\n");
			break;
		case 6:
			printf("test message 2\n");
			break;
		case 7:
			printf("printf('hello world');\n");
			break;
		case 8:
			printf("개발자의 한마디\n");
			break;
		case 9:
			printf("확률은 1/10\n");
			break;
		case 10:
			printf("대충 광고 문구\n");
			break;

	} return;
}

//standard deviation
void stDev() {
	float std[num];
	float numimp;
	float sum;
	for(int i = 0; i < num; i++) {
		numimp = 9;
		sum = 0;
		if(kor[i] == -1) {numimp--;}
		else{sum += (float)pow((float)kor[i] - avga[i], 2);}
		if(math[i] == -1) {numimp--;}
		else{sum += (float)pow((float)math[i] - avga[i], 2);}
		if(eng[i] == -1) {numimp--;}
		else{sum += (float)pow((float)eng[i] - avga[i], 2);}

		if(soc[i] == -1) {numimp--;}
		else{sum += (float)pow((float)soc[i] - avga[i], 2);}
		if(hist[i] == -1) {numimp--;}
		else{sum += (float)pow((float)hist[i] - avga[i], 2);}
		if(sci[i] == -1) {numimp--;}
		else{sum += (float)pow((float)sci[i] - avga[i], 2);}

		if(homeec[i] == -1) {numimp--;}
		else{sum += (float)pow(homeec[i] - avga[i], 2);}
		if(han[i] == -1) {numimp--;}
		else{sum += (float)pow((float)han[i] - avga[i], 2);}
		if(moral[i] == -1) {numimp--;}
		else{sum += (float)pow((float)moral[i] - avga[i], 2);}

		std[i] = (float)sqrt(sum / numimp);
	}
	printf("개인별 표준편차\n");
	for(int i = 0; i < num; i++) {
		printf("%s : %f\n", name[i], std[i]);
	}
	printf("\n");
	return;
}

//absolute evaluation grade
void absEval() {
	char grade[num];
	char gradepm[num];
	for(int i = 0; i < num; i++) {
		if((int)avga[i] >= 89) {
			grade[i] = 'A';
		} else if((int)avga[i] >= 79) {
			grade[i] = 'B';
		} else if((int)avga[i] >= 69) {
			grade[i] = 'C';
		} else if((int)avga[i] >= 59) {
			grade[i] = 'D';
		}else {
			grade[i] = 'F';
		} 
		if(((int)avga[i] + 1) % 10 > 7) {
			gradepm[i] = '+';
		} else if(((int)avga[i] + 1) % 10 > 3) {
			gradepm[i] = '0';
		}else {
			gradepm[i] = '-';
		} if(grade[i] == 'F') {gradepm[i] = ' ';}
	}
	printf("절대평가 기준 성적\n");
	for(int i = 0; i < num; i++) {
		printf("%s : %c%c\n", name[i], grade[i], gradepm[i]);
	}
	return;
}

//average of korean, math, english
void avgImp() {
    float avg[num];
	float sum;
	float numimp;
	for(int i = 0; i < num; i++) {
		numimp = 3;
		sum = 0;
		if(kor[i] == -1) {numimp--;}
		else{sum += kor[i];}
		if(math[i] == -1) {numimp--;}
		else{sum += math[i];}
		if(eng[i] == -1) {numimp--;}
		else{sum += eng[i];}
		avg[i] = sum / numimp;
	}
	printf("국영수 평균\n");
	for(int i = 0; i < num; i++) {
		printf("%s : %f\n", name[i], avg[i]);
	}
	printf("\n");
	return;
}

//average of all subjects
void avgAll() {
	float sum;
	float numimp;
	for(int i = 0; i < num; i++) {
		numimp = 9;
		sum = 0;
		if(kor[i] == -1) {numimp--;}
		else{sum += kor[i];}
		if(math[i] == -1) {numimp--;}
		else{sum += math[i];}
		if(eng[i] == -1) {numimp--;}
		else{sum += eng[i];}

		if(soc[i] == -1) {numimp--;}
		else{sum += soc[i];}
		if(hist[i] == -1) {numimp--;}
		else{sum += hist[i];}
		if(sci[i] == -1) {numimp--;}
		else{sum += sci[i];}

		if(homeec[i] == -1) {numimp--;}
		else{sum += homeec[i];}
		if(han[i] == -1) {numimp--;}
		else{sum += han[i];}
		if(moral[i] == -1) {numimp--;}
		else{sum += moral[i];}

		avga[i] = sum / numimp;
	}
	printf("모든 과목 평균\n");
	for(int i = 0; i < num; i++) {
		printf("%s : %f\n", name[i], avga[i]);
	}
	printf("\n");
	return;
}

//average of major subjects
void avgFive() {
	float avg[num];
	float sum;
	float numimp;
	for(int i = 0; i < num; i++) {
		numimp = 6;
		sum = 0;
		if(kor[i] == -1) {numimp--;}
		else{sum += kor[i];}
		if(math[i] == -1) {numimp--;}
		else{sum += math[i];}
		if(eng[i] == -1) {numimp--;}
		else{sum += eng[i];}

		if(soc[i] == -1) {numimp--;}
		else{sum += soc[i];}
		if(hist[i] == -1) {numimp--;}
		else{sum += hist[i];}
		if(sci[i] == -1) {numimp--;}
		else{sum += sci[i];}

		avg[i] = sum / numimp;
	}
	printf("주요 5과목(국영수사(역)과) 평균\n");
	for(int i = 0; i < num; i++) {
		printf("%s : %f\n", name[i], avg[i]);
	}
	printf("\n");
	return;
}

//print title
void title() {
	printf("loading user interface...\n");
	sleep(1);
	printf("complete!\nloading system files...\n");
	sleep(1);
	system("clear");
	printf("/-- /-- /-\\ |-\\ |--   /-- /-\\ |   /--\n\\-\\ |   | | |-/ |--   |   |-| |   |\n--/ \\-- \\-/ | \\ |--   \\-- | | |-- \\--\n");
	printf("scoreCalc\n");
	sleep(2);
	printf("Second Edition v2.6\nCopyright (c) Myungjae Lee,\nYangchung Middle School\nAll rights reserved\nKo-KR\n\nLoading...\n");
	sleep(4);
	system("clear");
	splashText();
	sleep(3);
	system("clear");
	printf("규칙\n\n");
	sleep(1);
	printf("1. 몇명인지 입력한다\n2. 이름을 입력한다\n3. 성적을 입력한다. 안봤을시 -1입력\n4. 결과를 확인한다\n\n\n");
	sleep(1);
	printf("몇명의 성적을 계산하시겠습니까? : ");
	scanf("%d", &num);
}

//scan scores
void scan() {
	system("clear");
	for(int i = 0; i < num; i++) {

		printf("이름을 입력하십시오 : ");
		scanf("%s", &name[i]);

		printf("국어 성적을 입력하십시오 : ");
		scanf("%d", &kor[i]);

		printf("수학 성적을 입력하십시오 : ");
		scanf("%d", &math[i]);

		printf("사회 성적을 입력하십시오 : ");
		scanf("%d", &soc[i]);

		printf("역사 성적을 입력하십시오 : ");
		scanf("%d", &hist[i]);

		printf("과학 성적을 입력하십시오 : ");
		scanf("%d", &sci[i]);

		printf("한문 성적을 입력하십시오 : ");
		scanf("%d", &han[i]);

		printf("기술가정 성적을 입력하십시오 : ");
		scanf("%d", &homeec[i]);

		printf("도덕 성적을 입력하십시오 : ");
		scanf("%d", &moral[i]);

		printf("영어 성적을 입력하십시오 : ");
		scanf("%d", &eng[i]);
		printf("\n");
		system("clear");
	}
	printf("\n");
}

//execute all
void main() {
	title();
	scan();
    avgImp();
	avgFive();
	avgAll();
	stDev();
	absEval();
    return;
}