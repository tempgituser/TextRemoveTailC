// TextRemoveTailC.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <sys\stat.h>
using namespace std;
const int MAX_LINE_SIZE = 65535;
const int MAX_FILE_SIZE = 500 * 1024 * 1024;
int currentIndex = 0;

/*
	·�����ܰ������ġ�
*/

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

char* inputFileDefault = "T:\\removetail.txt";
char* outputFileDefault = "T:\\removetail_result.txt";
int doRemoveTail(char* inputFile){
	FILE* input;
	/*char* inputFileWide = new char[1];
	Wide2Bytes(inputFileWide, inputFile);*/
	wcout << "���ļ���" << inputFile << endl;
	if (fopen_s(&input, inputFile, "rt") != 0){
		wcout << inputFile << "�ļ�������" << endl;
		return 1;
	}
	struct stat buf;
	stat(inputFile, &buf);
	//delete(inputFileWide);
	int fileSize = buf.st_size + 1;
	wcout << "�ļ���С��" << buf.st_size << "�ֽ�" << endl;

	/*if((input = fopen("T:\\testinput.txt", "rt")) == NULL){
	wcout << "�ļ�������" << endl;
	system("pause");
	exit(1);
	}*/

	char* outputContent = (char*)malloc(sizeof(char)* fileSize);
	memset(outputContent, '\0', sizeof(char)* fileSize);

	char line[MAX_LINE_SIZE] = { '\0' };
	while (!feof(input)){
		fgets(line, MAX_LINE_SIZE, input);
		currentIndex++;
		//wcout << "�����ݣ�" << line << endl;
		int length = strlen(line);
		//wcout << "�г��ȣ�" << length << endl;
		int unicodeLength = getLastUnicodeCharIndex(line, length);
		//wcout << "Last Unicode Char Index:" << unicodeLength << endl<<endl;
		line[unicodeLength + 1] = '\0';
		//wcout << "�ü������" << line << endl;

		strcat_s(outputContent, fileSize, line);
		strcat_s(outputContent, fileSize, "\n\r");
	}
	fclose(input);

	//wcout << "�����" << outputContent << endl;
	wcout << "ת����ɣ�" << currentIndex << "�С�" << endl;

	char drive[255];
	char dir[255];
	char fname[255];
	char ext[255];
	_splitpath_s(inputFile, drive, 255, dir, 255, fname, 255, ext, 255);
	strcat_s(fname, "_removedTail");
	wcout << drive << dir << fname << ext << endl;
	char outputFile[255] = { '\0' };
	strcat_s(outputFile, drive);
	strcat_s(outputFile, dir);
	strcat_s(outputFile, fname);
	strcat_s(outputFile, ext);

	FILE* output;
	/*char* outputFileWide;
	Wide2Bytes(outputFileWide, outputFile);*/
	if (fopen_s(&output, outputFile, "wt") != 0){
		wcout << "�޷�����" << outputFile << "�ļ�" << endl;
		return 1;
	}


	fprintf(output, "%s", outputContent);
	wcout << "�����:" << outputFile << "��" << endl << endl;
	//delete(inputFileWide);

	//system("pause");
	//while (1);

	free(outputContent);
	fclose(output);
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//cout << argc << endl<<endl;
	if (argc <= 1){
		if (doRemoveTail(inputFileDefault)){
			system("pause");
			exit(1);
		}
	}
	else{
		char ** argn = allocate_argn(argc, argv);
		for (int i = 1; i < argc; i++){
			//wcout << argv[i] << endl;


			if (doRemoveTail(argn[i])){
				system("pause");
				exit(1);
			}
		}
	}


	system("pause");

	return 0;
}

