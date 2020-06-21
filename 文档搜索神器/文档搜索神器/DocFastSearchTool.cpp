#include"common.h"
#include"Sysutil.h"

void Test_DirectionList()
{
	const string &path = "C:\\Users\\Administrator.PC-201810141417\\Desktop";
	vector<string> subfile, subdir;
	DirectionList(path,subfile,subdir);
	for (const auto &e : subdir)
		cout << e << endl;
	for (const auto &e : subdir)
		cout << e << endl;
}

int main(int argc,char *argv[])
{
	Test_DirectionList();
	return 0;
}