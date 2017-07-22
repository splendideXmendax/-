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

//����ѡ���б�
void CreatePlayerList(map<int, Player> &mList, vector<int> &vFirst)
{
	string nameSeend = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; ++i)
	{
		//����ѧ��
		Player p;
		p.mName = "ѡ��";
		p.mName += nameSeend[i];
		for (int j = 0; j < 3; ++j)
		{
			p.mScore[j] = 0;
		}
		//����Ψһ�Ĳ������
		int joinID = 100 + i;
		//����ѧ����Ϣ
		mList.insert(make_pair(joinID, p));
		//�����һ�ֲ����ı��
		vFirst.push_back(joinID);
	}
}

//��ǩ
void ChouQian(vector<int> &vJoinList)
{
	//�����������
	srand((unsigned int)time(NULL));
	//���Ҳ����б��˳��
	random_shuffle(vJoinList.begin(), vJoinList.end());

}

//����
void Match(int round, vector<int> &vJoinList, map<int, Player> &mPlayerList, vector<int> &mLevelList)
{

	srand((unsigned int)time(NULL));

	//���������Ϣmultimap<����,���> Ĭ���Ǵ�С����
	multimap<int, int, greater<int>> mGroups;

	//��������ѡ���б�
	for (vector<int>::iterator it = vJoinList.begin(); it != vJoinList.end(); ++it)
	{
		//����10λ��ί�ķ���
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			//��ί���
			int score = rand() % 50 + 50;
			dScores.push_back(score);
		}

		//�Է�����������(Ĭ����������)
		sort(dScores.begin(), dScores.end());
		//ȥ����߷ֺ���ͷ�
		dScores.pop_back();
		dScores.pop_front();
		//����ƽ�ַ�
		int avg = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();
		//���浱ǰѡ�ֵķ���
		mPlayerList[*it].mScore[round - 1] = avg;
		//���������Ϣ
		mGroups.insert( make_pair(avg, *it) );


		//��һ��������
		if (mGroups.size() == 6)
		{
			multimap<int, int, greater<int>>::iterator mit = mGroups.begin();
			for (int j = 0; j < 3; ++j)
			{
				mLevelList.push_back(mit->second);
				++mit;
			}

			//���mGroups
			mGroups.clear();
		}

	}

}

void Show(int round, vector<int> &vLevelList, map<int, Player> &mPlayersList)
{
	cout << "��" << round << "�ֱ���������������:" << endl;
	for (auto id : vLevelList)
	{
		cout << "Score " << mPlayersList[id].mScore[round - 1] << " Name:" << mPlayersList[id].mName << endl;
	}
	cout << "---------------" << endl;
}

int main(){

	//����24��ѡ��
	map<int, Player> mPlayersList; //��������ѡ�־�����Ϣ
	vector<int> vFirstRound; //�����һ�ֱ�������ѡ�ֵı��
	CreatePlayerList(mPlayersList, vFirstRound);


	vector<int> vLevelList1;
	vector<int> vLevelList2;
	vector<int> vLevelList3;


	//��ǩ
	ChouQian(vFirstRound);
	//�μӱ���
	Match(1, vFirstRound, mPlayersList, vLevelList1);
	//��ʾ��������
	Show(1, vLevelList1, mPlayersList);



	//��ǩ
	ChouQian(vLevelList1);
	//�μӱ���
	Match(2, vLevelList1, mPlayersList, vLevelList2);
	//��ʾ��������
	Show(2, vLevelList2, mPlayersList);

	//��ǩ
	ChouQian(vLevelList2);
	//�μӱ���
	Match(3, vLevelList2, mPlayersList, vLevelList3);
	//��ʾ��������
	Show(3, vLevelList3, mPlayersList);


	system("pause");
	return EXIT_SUCCESS;
}