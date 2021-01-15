// GetCurrentPath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#ifdef _WIN32
#include <io.h>
#include <tchar.h>
#include <direct.h>
#include <Windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include <stdio.h>

std::string GetCurrentPath() {
  char curr_path[1024];
#ifdef _WIN32
  ::GetModuleFileName(NULL, curr_path, MAX_PATH);
  (_tcsrchr(curr_path, '\\'))[1] = 0;
#else	
  getcwd(curr_path, 1024);
  sprintf(curr_path, "%s/", curr_path);
#endif
  std::string str_curr_path = curr_path;
  return str_curr_path;
}

int main()
{
  std::cout << GetCurrentPath() << std::endl;
}
