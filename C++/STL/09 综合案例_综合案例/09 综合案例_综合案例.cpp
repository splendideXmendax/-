#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<deque>
#include<numeric>
#include<functional>
using namespace std;

class Player
{
public:
	string mName;
	int mScore[3];
};

//创建选手列表
void CreatePlayerList(map<int, Player> &mList, vector<int> &vFirst)
{
	string nameSeend = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; ++i)
	{
		//创建学生
		Player p;
		p.mName = "选手";
		p.mName += nameSeend[i];
		for (int j = 0; j < 3; ++j)
		{
			p.mScore[j] = 0;
		}
		//生成唯一的参赛编号
		int joinID = 100 + i;
		//保存学生信息
		mList.insert(make_pair(joinID, p));
		//保存第一轮参赛的编号
		vFirst.push_back(joinID);
	}
}

//抽签
void ChouQian(vector<int> &vJoinList)
{
	//设置随机种子
	srand((unsigned int)time(NULL));
	//打乱参赛列表的顺序
	random_shuffle(vJoinList.begin(), vJoinList.end());

}

//比赛
void Match(int round, vector<int> &vJoinList, map<int, Player> &mPlayerList, vector<int> &mLevelList)
{

	srand((unsigned int)time(NULL));

	//保存分组信息multimap<分数,编号> 默认是从小到大
	multimap<int, int, greater<int>> mGroups;

	//遍历参赛选手列表
	for (vector<int>::iterator it = vJoinList.begin(); it != vJoinList.end(); ++it)
	{
		//保存10位评委的分数
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			//评委打分
			int score = rand() % 50 + 50;
			dScores.push_back(score);
		}

		//对分数进行排序(默认升序排列)
		sort(dScores.begin(), dScores.end());
		//去除最高分和最低分
		dScores.pop_back();
		dScores.pop_front();
		//计算平局分
		int avg = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();
		//保存当前选手的分数
		mPlayerList[*it].mScore[round - 1] = avg;
		//保存分组信息
		mGroups.insert( make_pair(avg, *it) );


		//够一个分组了
		if (mGroups.size() == 6)
		{
			multimap<int, int, greater<int>>::iterator mit = mGroups.begin();
			for (int j = 0; j < 3; ++j)
			{
				mLevelList.push_back(mit->second);
				++mit;
			}

			//清空mGroups
			mGroups.clear();
		}

	}

}

void Show(int round, vector<int> &vLevelList, map<int, Player> &mPlayersList)
{
	cout << "第" << round << "轮比赛晋级名单如下:" << endl;
	for (auto id : vLevelList)
	{
		cout << "Score " << mPlayersList[id].mScore[round - 1] << " Name:" << mPlayersList[id].mName << endl;
	}
	cout << "---------------" << endl;
}

int main(){

	//创建24个选手
	map<int, Player> mPlayersList; //保存所有选手具体信息
	vector<int> vFirstRound; //保存第一轮比赛参赛选手的编号
	CreatePlayerList(mPlayersList, vFirstRound);


	vector<int> vLevelList1;
	vector<int> vLevelList2;
	vector<int> vLevelList3;


	//抽签
	ChouQian(vFirstRound);
	//参加比赛
	Match(1, vFirstRound, mPlayersList, vLevelList1);
	//显示晋级名单
	Show(1, vLevelList1, mPlayersList);



	//抽签
	ChouQian(vLevelList1);
	//参加比赛
	Match(2, vLevelList1, mPlayersList, vLevelList2);
	//显示晋级名单
	Show(2, vLevelList2, mPlayersList);

	//抽签
	ChouQian(vLevelList2);
	//参加比赛
	Match(3, vLevelList2, mPlayersList, vLevelList3);
	//显示晋级名单
	Show(3, vLevelList3, mPlayersList);


	system("pause");
	return EXIT_SUCCESS;
}