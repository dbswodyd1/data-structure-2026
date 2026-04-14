#pragma once
#include <stdio.h>
#include<cstring>

const int MAX_STRING = 20;
const int MAX_STACK_SIZE = 20;

class Student {
	int id; // 학번
	char name[MAX_STRING]; // 이름
	char dept[MAX_STRING]; // 소속 학과
public:
	Student(int i = 0, const char* n = "", const char* d = "") {
		set(i, n, d);
	}
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy_s(name, MAX_STRING, n); // 문자열 복사 함수
		strcpy_s(dept, MAX_STRING, d); // 문자열 복사 함수
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};

class ArrayStack{
	int top; // 요소의 개수
	Student data[MAX_STACK_SIZE];
public:
	ArrayStack() { top = -1; }
	void push(Student e) {
		if (top < MAX_STACK_SIZE - 1) {
			data[++top] = e;
		}
		else {
			printf("스택 오버플로우\n");
		}
	}
	Student pop() { 
		if (top >= 0) {
			return data[top--];
		}
		else {
			printf("스택 언더플로우\n");
			return Student();
		}
	}
	Student peek() {
		if (top >= 0)
			return data[top];
		else
			return Student();
	}
	void display() {
		printf("[스택 항목의 수 = %2d] ==> \n", top + 1);
		for (int i = 0; i <= top; i++) {
			data[i].display();
		}
		printf("\n");
	}
};
