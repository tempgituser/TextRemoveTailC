// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// TextRemoveTailC.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO:  �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������


/*
#include <windows.h>
#include <winnls.h>
void Wide2Bytes(char* pBytes, TCHAR* pWide)
{
int nLen = WideCharToMultiByte(CP_ACP, 0, pWide, -1, NULL, 0, NULL, NULL);
// get need convert length
int i = (int)wcslen(pWide)*sizeof(TCHAR);
// get need new memory size
pBytes = new char[i + 1];
if (!pBytes) // if fail then new again
{
pBytes = new char[i + 1];
}
if (!pBytes) { return; }
WideCharToMultiByte(CP_ACP, 0, pWide, -1, pBytes, nLen, NULL, NULL);
}*/

int wstrlen(_TCHAR * wstr)
{
	int l_idx = 0;
	while (((char*)wstr)[l_idx] != 0) l_idx += 2;
	return l_idx;
}
char * wstrdup(_TCHAR * wSrc)
{
	int l_idx = 0;
	int l_len = wstrlen(wSrc);
	char * l_nstr = (char*)malloc(l_len);
	if (l_nstr) {
		do {
			l_nstr[l_idx] = (char)wSrc[l_idx];
			l_idx++;
		} while ((char)wSrc[l_idx] != 0);
	}
	l_nstr[l_idx] = 0;
	return l_nstr;
}
char ** allocate_argn(int argc, _TCHAR* argv[])
{
	char ** l_argn = (char **)malloc(argc * sizeof(char*));
	for (int idx = 0; idx<argc; idx++) {
		l_argn[idx] = wstrdup(argv[idx]);
	}
	return l_argn;
}