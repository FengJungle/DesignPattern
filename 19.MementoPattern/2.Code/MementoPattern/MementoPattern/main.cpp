#include "Originator.h"
#include "Memento.h"
#include "CodeManager.h"

int main()
{
	CodeManager *Jungle = new CodeManager();

	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");

	// 提交初始版本
	printf("提交初始版本:\n");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了日志功能
	printf("\n提交一个版本，增加了日志功能:\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	Jungle->commit(codeVer->save());

	// 修改一个版本，增加了Qt图片浏览器
	printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	Jungle->commit(codeVer->save());

	// 查看提交历史
	printf("\n查看提交历史\n");
	Jungle->codeLog();

	// 回退到上一个版本
	printf("\n回退到上一个版本\n");
	codeVer->restore(Jungle->switchToPointedVersion(1));

	// 查看提交历史
	printf("\n查看提交历史\n");
	Jungle->codeLog();

	printf("\n\n");
	system("pause");
	return 0;
}