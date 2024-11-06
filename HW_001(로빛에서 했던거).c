#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 50 //�л� �� ������ ���⸸ �����ϸ� ��

/*����-�⼮��
*�ּ��� �����׸� ����ü�� �̸� ���ҷ� ������ �л� ���� ����ü�� �����, �л� ���� ����ü�� ����ü �迭�� �����
*������ �۾��� �Է¹ް� if���̳� switch case������ �۾��� �´� �Լ��� ȣ���Ѵ�(7�� 3�� ���� 2��, 7�� 11�� ���� ����)
* �л� �߰� �۾� ����� �ּ��� �����׸��� ����Ű�� ����ü �����Ϳ� �����ϱ� ���� ���� �Ҵ��� ����Ѵ�
* �л� ���� �۾� ����� �ش� ����ü �迭 �ε����� ���� �Ҵ��� Ǭ��
* ���� �۾��� ���� for���� ����� ����ü �迭�� ���Ҹ� ���ؿ� ���� ��Һ��� �����Ѵ�(7�� 5�� 1�� ����)
* 
* ���Ϸ� ����/�ҷ������ ���� �ö�� ���Ͽ� ����� ���� ������ �����Ѵ�
* �ݺ����� �ݺ� Ƚ�� ���� ���� ���� �л����� ���������� �ξ� ��κ� �װ��� �������� �ϰ� �ִ� 
*/

typedef struct format {//�л� �ּ��� �����׸� ����ü
	char country[25];
	char Do[20];
	char city[20];
	char Gu[20];

}address;

typedef struct student {//�л� �ּ� ����ü�� �����ϴ� �л� ���� ����ü
	int num;
	char name[20];
	address* juso;
	float score;
}Student;

int input;//���� ���� ����
char command[10];//��ɾ� ���� ���ڿ�
int c = 0;//���� �л���

Student sort(Student s[]){  //1. ���� �Լ�
	printf("��ȣ / �̸� / �ּ� / ����\n�Է� : ");
	scanf("%s", &command);

	if (!strcmp(command, "��ȣ")) {//��ȣ ���� ����
		for (int i = 0; i < c;i++) {//7�� 5�� 1�� ���� ����-����ü �迭 �������� ����
			for (int j = 0; j < c - i - 1 ;j++) {
				if (s[j].num > s[j + 1].num) {//��ȣ�� Ȱ���� �� �ٲٱ�
					s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
	if (!strcmp(command, "�̸�")) {//�̸� ���� ����
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].name > s[j + 1].name) {//�̸��� ���� �� �ٲٱ�
					s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
	if (!strcmp(command, "�ּ�")) { //�ּ� ���� ������ ���� �ּҸ� ���� �Է¹���
		char command = '\0';//�Է¹��� ���ڿ� �ʱ�ȭ
		printf("���� / �� / �� / ��");//���� �ּ� �Է�
		scanf("%d", &command);
		if(!strcmp(command,"����")){
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].juso->country > s[j + 1].juso->country) {//������ ���� �� �ٲٱ�
					s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
					s[j] = s[j + 1];
					s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "��")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->Do > s[j + 1].juso->Do) {//���� ���� �� �ٲٱ�
						s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "��")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->city > s[j + 1].juso->city) {//�ø� ���� �� �ٲٱ�
						s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
		if (!strcmp(command, "��")) {
			for (int i = 0; i < c;i++) {
				for (int j = 0; j < c - i - 1;j++) {
					if (s[j].juso->Gu > s[j + 1].juso->Gu) {//���� ���� �� �ٲٱ�
						s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
						s[j] = s[j + 1];
						s[j + 1] = s[size];
					}
				}
			}
		}
	}

	if (!strcmp(command, "����")) {
		for (int i = 0; i < c;i++) {
			for (int j = 0; j < c - i - 1;j++) {
				if (s[j].score > s[j + 1].score) {//������ Ȱ���� �� �ٲٱ�
					s[size] = s[j];//����ü �迭�� ������ ĭ�� ������ Ȱ���� �� �ٲٱ�
					s[j] = s[j + 1];
					s[j + 1] = s[size];
				}
			}
		}
	}
}

Student search(Student s[]) {//�л� ã�� �Լ�
	printf("��ȣ / �̸� / �ּ� / ����\n�Է� : ");
	scanf("%s", &command);
	if (!strcmp(command, "��ȣ")) {//��ȣ�� ã��
		int bunho;
		printf("�Է� : ");
		scanf("%d", &bunho);//��ȣ �Է¹ް� ����ü �迭 �ϳ��ϳ� Ž���ϸ� ������ Ȯ��
		for (int i = 0;i < c;i++) {
			if (s[i].num == bunho) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "�̸�")) {//�̸����� ã��
		char yirum[10];
		printf("�Է� : ");
		scanf("%s", &yirum);
		for (int i = 0;i < c;i++) {
			if (s[i].name == yirum) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "�ּ�")) {//�ּҷ� ã��
		char juso[20];
		printf("�Է� : ");
		scanf("%s", &juso);
		for (int i = 0;i < c;i++) {//�ּ� ���� �� �ϳ� �̻� ��ġ�ϸ� �˻��ǰ� ��
			if (s[i].juso->country == juso || s[i].juso->Do == juso || s[i].juso->city == juso || s[i].juso->Gu == juso ) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
	if (!strcmp(command, "����")) {//�������� ã��
		float seongjuck[10];
		printf("�Է� : ");
		scanf("%f", &seongjuck);
		for (int i = 0;i < c;i++) {
			if (s[i].score == *seongjuck) {
				printf("%s ", s[i].name);
			}
		}
		printf("\n");
	}
}

void add(Student s[]) {//�л� �߰� �Լ�
	int a;
	printf("�߰� ��� : ");//�߰��� ����� ���� �Է�
	scanf("%d", &a);
	printf("�߰� || ��ȣ / �̸� / ���� / �� / �� / �� / ����\n�Է� : ");//�߰��� �����ŭ �л������� �Է¹���
	for (int i = 0;i < a;i++) {
		s[c].juso = (address*)malloc(sizeof(address) * 20);//juso�� �����ϱ� ���� juso�� �޸𸮸� ���� �Ҵ�
		scanf("%d %s %s %s %s %s %f", &s[c].num, s[c].name, s[c].juso->country, s[c].juso->Do, s[c].juso->city, s[c].juso->Gu, &s[c].score);
		c++;
	}
}

void delete(Student s[]) {//�л� ���� �Լ�
	Student temp;
	temp.juso = (address*)malloc(sizeof(address));//case 1ó�� s[size]�� �غ������� ���� �� ������ �߻��� �ӽ� ����� ����ü�� �ϳ� ����
	printf("���� || ��ȣ / �̸� / ���� / �� / �� / �� / ����\n�Է� : ");
	scanf("%d %s %s %s %s %s %f", &temp.num, temp.name, temp.juso->country, temp.juso->Do, temp.juso->city, temp.juso->Gu, &temp.score);
	for (int i = 0; i < c; i++) {
		if (temp.num == s[i].num && !strcmp(temp.name, s[i].name) && !strcmp(temp.juso->country, s[i].juso->country) && !strcmp(temp.juso->Do, s[i].juso->Do) && !strcmp(temp.juso->city, s[i].juso->city) && !strcmp(temp.juso->Gu, s[i].juso->Gu) && temp.score == s[i].score) {
			free(s[i].juso);
			for (int j = i; j < c - 1; j++) {
				s[j] = s[j + 1];
			}
			c--;
			break;//������ ����ü�� ���� �Ҵ�� ������ ����ü�� �Ҵ� ������ ��, ����ü �迭�� ĭ�� �� ĭ�� ������ ����.
		}
	}
	free(temp.juso);
}


void save(Student s[]) {//���Ϸ� �����ϴ� �Լ�
	FILE* fp = fopen("Student_List.txt", "w");//���ϸ�

	for (int i = 0; i < c;i++) {
		fprintf(fp, "%d %s %s %s %s %s %.1f", s[i].num, s[i].name, s[i].juso->country, s[i].juso->Do, s[i].juso->city, s[i].juso->Gu, s[i].score);
		fprintf(fp, "\n");//�⼮�θ� �� �پ� ���ܳ���
	}
	fclose(fp);
}
void load(Student s[]) {//�ε��ϴ� �Լ�
	FILE* fp = fopen("Student_List.txt", "r");
	for (int i = 0;i < c;i++) {//���� �������� ����ü �ʱ�ȭ
		s[i].num = 0;
		s[i].name[0] = '\0';
		free(s[i].juso);//���� �Ҵ� ������ ���ش�
		s[i].score = 0;
	}
	c = 0;

	while (!feof(fp)) {//fp ������ ���� ������ �ݺ�
		s[c].juso = (address*)malloc(sizeof(address) * 20);//���⼭���� add���� ��� �Ŷ� �Ȱ��� �ϸ� ��
		fscanf(fp, "%d %s %s %s %s %s %f\n", &s[c].num, s[c].name, s[c].juso->country, s[c].juso->Do, s[c].juso->city, s[c].juso->Gu, &s[c].score);
		c++;
	}
	fclose(fp);//���� �ݱ�
}

int main() {
	Student s[size + 1];//������ ĭ�� �ӽ� ���� ����ó�� ������ ��
	while (1) {
		char command = '\0';//�Է¹��� ���ڿ� �ʱ�ȭ
		printf("\n1.�л����� 2.�л�ã�� 3. �л��߰� 4. �л����� 5. �⼮�� ���� 6. �⼮�� �ҷ�����\n��ȣ �Է� : ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			if (c <= 1) {//�л����� ������� ������ �Է°� �ε� �̿��� �۾��� �� �� ����
				printf("�л��� ������� �ʽ��ϴ�.\n");
			}
			else {
				sort(s);
			}break;
		case 2:
			if (c == 0) {
				printf("�л��� �����ϴ�.\n");
			}
			else {
				search(s);
			}break;
		case 3:
			add(s);
			break;
		case 4:
			if (c == 0) {
				printf("�л��� �����ϴ�.\n");
			}
			else {
				delete(s);
			}break;
		case 5:
			if (c == 0) {
				printf("�л��� �����ϴ�.\n");
			}
			else {
				save(s);
			}break;
		case 6:
			load(s);
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n\n");
			break;
		}
		if (c != 0) {
			for (int i = 0; i < c;i++) {//����ϱ�
				printf("\n%d %s %s %s %s %s %.1f", s[i].num, s[i].name, s[i].juso->country, s[i].juso->Do, s[i].juso->city, s[i].juso->Gu, s[i].score);
				printf("\n");
			}
		}
	}
}