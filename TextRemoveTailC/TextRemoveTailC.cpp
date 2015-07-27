// TextRemoveTailC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <sys\stat.h>
#include <iostream>
using namespace std;
const int MAX_LINE_SIZE = 65535;
int currentIndex = 0;

const int MAX_FILE_SIZE = 500 * 1024 * 1024;

int getLastUnicodeCharIndex(char line[], int length){
	int i = 0;
	for (i = length - 1; i >= 0; i--){
		int chr = line[i];
		//wcout << chr << endl;
		if (chr > 256 || chr < 0) {
			return i;
		}
	}
	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << argc << endl<<endl;
	if (argc <= 1){
		for (int i = 0; i < argc; i++){
			wcout << argv[i] << endl;
		}
	}
	else{
		for (int i = 0; i < argc; i++){
			wcout << argv[i] << endl;
		}
	}

	FILE* input;
	if (fopen_s(&input, "T:\\testinput.txt", "rt") != 0){
		wcout << "文件不存在" << endl;
		system("pause");
		exit(1);
	}
	struct stat buf;
	stat("T:\\testinput.txt", &buf);
	int fileSize = buf.st_size + 1;
	wcout << "文件大小：" << buf.st_size << "字节" << endl;



	/*if((input = fopen("T:\\testinput.txt", "rt")) == NULL){
		wcout << "文件不存在" << endl;
		system("pause");
		exit(1);
	}*/

	char* output = (char*)malloc(sizeof(char)* fileSize);
	memset(output, '\0', sizeof(char)* fileSize);

	char line[MAX_LINE_SIZE] = { '\0' };
	while (!feof(input)){
		fgets(line, MAX_LINE_SIZE, input);
		//wcout << "行内容：" << line << endl;
		int length = strlen(line);
		//wcout << "行长度：" << length << endl;
		int unicodeLength = getLastUnicodeCharIndex(line, length);
		//wcout << "Last Unicode Char Index:" << unicodeLength << endl<<endl;
		line[unicodeLength + 1] = '\0';
		//wcout << "裁剪结果：" << line << endl;

		strcat_s(output, fileSize, line);
		strcat_s(output, fileSize, "\r\n");
	}

	wcout << "结果：" << output << endl;




	//system("pause");
	//while (1);

	return 0;
}

