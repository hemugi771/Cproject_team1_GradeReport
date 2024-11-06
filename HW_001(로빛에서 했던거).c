#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 50 //학생 수 수정시 여기만 수정하면 됨

/*과제-출석부
*주소의 세부항목 구조체와 이를 원소로 가지는 학생 정보 구조체를 만들고, 학생 정보 구조체는 구조체 배열로 만든다
*진행할 작업을 입력받고 if문이나 switch case문으로 작업에 맞는 함수를 호출한다(7월 3일 과제 2번, 7월 11일 과제 전반)
* 학생 추가 작업 진행시 주소의 세부항목을 가리키는 구조체 포인터에 접근하기 위해 동적 할당을 사용한다
* 학생 삭제 작업 진행시 해당 구조체 배열 인덱스만 동적 할당을 푼다
* 정렬 작업은 이중 for문을 사용해 구조체 배열의 원소를 기준에 따라 대소비교해 정렬한다(7월 5일 1번 과제)
* 
* 파일로 저장/불러오기는 과제 올라온 당일에 배웠던 강의 내용을 참고한다
* 반복문의 반복 횟수 같은 것은 현재 학생수를 전역변수로 두어 대부분 그것을 기준으로 하고 있다 
*/

typedef struct format {//학생 주소의 세부항목 구조체
	char country[25];
	char Do[20];
	char city[20];
	char Gu[20];

}address;

typedef struct student {//학생 주소 구조체를 포함하는 학생 정보 구조체
	int num;
	char name[20];
	address* juso;
	float score;
}Student;

int input;//숫자 받을 변수
char command[10];//명령어 받을 문자열
int c = 0;//현재 학생수

Student sort(Student s[]){  //1. 정렬 함수
	printf("번호 / 이름 / 주소 / 성적\n입력 : ");
	scanf("%s", &command);

	if (!strcmp(command, "번호")) {//번호 기준 정렬
		for (int i = 0; i < c;i++) {//7월 5일 1번 과제 참고-구조체 배열 오름차순 정렬
			for (int j = 0; j < c - i - 1 ;j++) {
				if (s[j].num > s[j + 1].num) {//번호를 활용해 값 바꾸기
					s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
	if (!strcmp(command, "이름")) {//이름 기준 정렬
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].name > s[j + 1].name) {//이름을 비교해 값 바꾸기
					s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
	if (!strcmp(command, "주소")) { //주소 기준 정렬은 세부 주소를 따로 입력받음
		char command = '\0';//입력받을 문자열 초기화
		printf("국가 / 도 / 시 / 구");//세부 주소 입력
		scanf("%d", &command);
		if(!strcmp(command,"국가")){
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].juso->country > s[j + 1].juso->country) {//국가를 비교해 값 바꾸기
					s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
					s[j] = s[j + 1];
					s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "도")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->Do > s[j + 1].juso->Do) {//도를 비교해 값 바꾸기
						s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "시")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->city > s[j + 1].juso->city) {//시를 비교해 값 바꾸기
						s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "구")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->Gu > s[j + 1].juso->Gu) {//구를 비교해 값 바꾸기
						s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
	}

	if (!strcmp(command, "성적")) {
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].score > s[j + 1].score) {//성적을 활용해 값 바꾸기
					s[size] = s[j];//구조체 배열의 마지막 칸을 변수로 활용해 값 바꾸기
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
}

Student search(Student s[]) {//학생 찾기 함수
	printf("번호 / 이름 / 주소 / 성적\n입력 : ");
	scanf("%s", &command);
	if (!strcmp(command, "번호")) {//번호로 찾기
		int bunho;
		printf("입력 : ");
		scanf("%d", &bunho);//번호 입력받고 구조체 배열 하나하나 탐색하며 같은지 확인
		for (int i = 0;i < c;i++) {
			if (s[i].num == bunho) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "이름")) {//이름으로 찾기
		char yirum[10];
		printf("입력 : ");
		scanf("%s", &yirum);
		for (int i = 0;i < c;i++) {
			if (s[i].name == yirum) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "주소")) {//주소로 찾기
		char juso[20];
		printf("입력 : ");
		scanf("%s", &juso);
		for (int i = 0;i < c;i++) {//주소 조건 중 하나 이상만 일치하면 검색되게 함
			if (s[i].juso->country == juso || s[i].juso->Do == juso || s[i].juso->city == juso || s[i].juso->Gu == juso ) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "성적")) {//성적으로 찾기
		float seongjuck[10];
		printf("입력 : ");
		scanf("%f", &seongjuck);
		for (int i = 0;i < c;i++) {
			if (s[i].score == *seongjuck) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
}

void add(Student s[]) {//학생 추가 함수
	int a;
	printf("추가 명수 : ");//추가할 명수를 먼저 입력
	scanf("%d", &a);
	printf("추가 || 번호 / 이름 / 나라 / 도 / 시 / 구 / 성적\n입력 : ");//추가할 명수만큼 학생정보를 입력받음
	for (int i = 0;i < a;i++) {
		s[c].juso = (address*)malloc(sizeof(address) * 20);//juso에 접근하기 위해 juso에 메모리를 동적 할당
		scanf("%d %s %s %s %s %s %f", &s[c].num, s[c].name, s[c].juso->country, s[c].juso->Do, s[c].juso->city, s[c].juso->Gu, &s[c].score);
		c++;
	}
}

void delete(Student s[]) {//학생 삭제 함수
	Student temp;
	temp.juso = (address*)malloc(sizeof(address));//case 1처럼 s[size]로 해보았으나 원인 모를 오류가 발생해 임시 저장용 구조체를 하나 만듦
	printf("삭제 || 번호 / 이름 / 나라 / 도 / 시 / 구 / 성적\n입력 : ");
	scanf("%d %s %s %s %s %s %f", &temp.num, temp.name, temp.juso->country, temp.juso->Do, temp.juso->city, temp.juso->Gu, &temp.score);
	for (int i = 0; i < c; i++) {
		if (temp.num == s[i].num && !strcmp(temp.name, s[i].name) && !strcmp(temp.juso->country, s[i].juso->country) && !strcmp(temp.juso->Do, s[i].juso->Do) && !strcmp(temp.juso->city, s[i].juso->city) && !strcmp(temp.juso->Gu, s[i].juso->Gu) && temp.score == s[i].score) {
			free(s[i].juso);
			for (int j = i; j < c - 1; j++) {
				s[j] = s[j + 1];
			}
			c--;
			break;//삭제할 구조체의 동적 할당된 포인터 구조체를 할당 해제한 후, 구조체 배열의 칸을 한 칸씩 앞으로 당긴다.
		}
	}
	free(temp.juso);
}


void save(Student s[]) {//파일로 저장하는 함수
	FILE* fp = fopen("Student_List.txt", "w");//파일명

	for (int i = 0; i < c;i++) {
		fprintf(fp, "%d %s %s %s %s %s %.1f", s[i].num, s[i].name, s[i].juso->country, s[i].juso->Do, s[i].juso->city, s[i].juso->Gu, s[i].score);
		fprintf(fp, "\n");//출석부를 한 줄씩 옯겨놓음
	}
	fclose(fp);
}
void load(Student s[]) {//로드하는 함수
	FILE* fp = fopen("Student_List.txt", "r");
	for (int i = 0;i < c;i++) {//지금 실행중인 구조체 초기화
		s[i].num = 0;
		s[i].name[0] = '\0';
		free(s[i].juso);//동적 할당 해제도 해준다
		s[i].score = 0;
	}
	c = 0;

	while (!feof(fp)) {//fp 파일이 끝날 때까지 반복
		s[c].juso = (address*)malloc(sizeof(address) * 20);//여기서부턴 add에서 썼던 거랑 똑같이 하면 됨
		fscanf(fp, "%d %s %s %s %s %s %f\n", &s[c].num, s[c].name, s[c].juso->country, s[c].juso->Do, s[c].juso->city, s[c].juso->Gu, &s[c].score);
		c++;
	}
	fclose(fp);//파일 닫기
}

int main() {
	Student s[size + 1];//마지막 칸은 임시 저장 변수처럼 쓰려는 것
	while (1) {
		char command = '\0';//입력받을 문자열 초기화
		printf("\n1.학생정렬 2.학생찾기 3. 학생추가 4. 학생삭제 5. 출석부 저장 6. 출석부 불러오기\n번호 입력 : ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			if (c <= 1) {//학생수가 충분하지 않으면 입력과 로드 이외의 작업을 할 수 없음
				printf("학생이 충분하지 않습니다.\n");
			}
			else {
				sort(s);
			}break;
		case 2:
			if (c == 0) {
				printf("학생이 없습니다.\n");
			}
			else {
				search(s);
			}break;
		case 3:
			add(s);
			break;
		case 4:
			if (c == 0) {
				printf("학생이 없습니다.\n");
			}
			else {
				delete(s);
			}break;
		case 5:
			if (c == 0) {
				printf("학생이 없습니다.\n");
			}
			else {
				save(s);
			}break;
		case 6:
			load(s);
			break;
		default:
			printf("잘못 입력하셨습니다.\n\n");
			break;
		}
		if (c != 0) {
			for (int i = 0; i < c;i++) {//출력하기
				printf("\n%d %s %s %s %s %s %.1f", s[i].num, s[i].name, s[i].juso->country, s[i].juso->Do, s[i].juso->city, s[i].juso->Gu, s[i].score);
				printf("\n");
			}
		}
	}
}