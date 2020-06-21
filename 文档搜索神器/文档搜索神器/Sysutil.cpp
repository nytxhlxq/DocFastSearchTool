#include"Sysutil.h"

void DirectionList(const string &path, vector<string> &subfile, vector<string> &subdir)
{
	string _path = path;
	_path += "\\*.*";//路径下所有文件

	_finddata_t file;
	long handle = _findfirst(_path.c_str(),&file);
	if (-1 == handle)
	{
		perror("_findfirst");
		return;
	}
	do
	{
		//if (file.name[0] == '.')//屏蔽掉自带的.文件（上一个文件夹）
		if (strcmp(file.name, ".") == 0 || strcmp(file.name,"..") == 0)
		    continue;
		if (file.attrib & _A_SUBDIR)
		{
			//cout << file.name << endl;
			//string tmp_path = path;
			//tmp_path += "\\";
			//tmp_path += file.name;
			//DirectionList(tmp_path);
			subdir.push_back(file.name);
		}
		else
			//cout << file.name << endl;
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);
	_findclose(handle);
}
