// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <stdlib.h>
#include <iostream>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
void Wide2Bytes(char* pBytes, TCHAR* pWide);
int wstrlen(_TCHAR * wstr);
char * wstrdup(_TCHAR * wSrc);
char ** allocate_argn(int argc, _TCHAR* argv[]);