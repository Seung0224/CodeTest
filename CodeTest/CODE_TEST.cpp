#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    system("pause");
	return 0;
}


#pragma region 1. ���� ���ڴ� �Ⱦ�
/*
�迭 arr�� �־����ϴ�.�迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�.�̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�.
��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�.���� ���,

arr = [1, 1, 3, 3, 0, 1, 1] �̸�[1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸�[4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
�迭 arr�� ũ�� : 1, 000, 000 ������ �ڿ���
�迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����

// ���� Ǭ ���
vector<int> Mysolution(vector<int> arr)
{
    vector<int> answer;

    // Search
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != arr.size() - 1)
        {
            for (int j = 1; j < arr.size() - i; j++)
            {
                if (arr[i] == arr[i + j])
                {
                    arr.at(i + j) = -1;
                }
                else
                {
                    break;
                }
            }
        }
    }

    int target = -1;
    arr.erase(remove(arr.begin(), arr.end(), target), arr.end());
    answer = arr;

    return answer;
}

vector <int> solution(vector<int>arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main()
{
    vector<int> arr = { 1, 1, 2, 2, 3, 3, 0, 1, 1 };

    vector<int> result = Solution(arr);
    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}
*/
#pragma endregion

#pragma region 2. �ּ� ���簢��
/*
���� ������ ����� ȸ�翡�� ������ ũ�⸦ ���Ϸ��� �մϴ�. �پ��� ���� ũ���� ���Ե��� ��� ������ �� �����鼭, �۾Ƽ� ��� �ٴϱ� ���� ������ ������ �մϴ�. �̷��� ����� �����ϴ� ������ ����� ���� ���������� ��� ������ ���� ���̿� ���� ���̸� �����߽��ϴ�.

�Ʒ� ǥ�� 4���� ������ ���� ���̿� ���� ���̸� ��Ÿ���ϴ�.

���� ��ȣ	���� ����	���� ����
1	60	50
2	30	70
3	60	30
4	80	40
���� �� ���� ���̿� ���� ���̰� ���� 80, 70�̱� ������ 80(����) x 70(����) ũ���� ������ ����� ��� ���Ե��� ������ �� �ֽ��ϴ�. ������ 2�� ������ ���η� ���� �����Ѵٸ� 80(����) x 50(����) ũ���� �������� ��� ���Ե��� ������ �� �ֽ��ϴ�. �̶��� ���� ũ��� 4000(=80 x 50)�Դϴ�.

��� ������ ���� ���̿� ���� ���̸� ��Ÿ���� 2���� �迭 sizes�� �Ű������� �־����ϴ�. ��� ������ ������ �� �ִ� ���� ���� ������ ���� ��, ������ ũ�⸦ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
sizes�� ���̴� 1 �̻� 10,000 �����Դϴ�.
sizes�� ���Ҵ� [w, h] �����Դϴ�.
w�� ������ ���� ���̸� ��Ÿ���ϴ�.
h�� ������ ���� ���̸� ��Ÿ���ϴ�.
w�� h�� 1 �̻� 1,000 ������ �ڿ����Դϴ�.

// ���� Ǭ ���
int mysolution(vector<vector<int>> sizes)
{
    int answer = 0;
    int maxX = 0, maxY = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        for (int j = 0 ; j < sizes[i].size() - 1; j++)
        {
            int temp = 0;

            if (sizes[i][j] < sizes[i][j + 1])
            {
                temp = sizes[i][j];
                sizes[i][j] = sizes[i][j + 1];
                sizes[i][j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < sizes.size(); i++)
    {
        for (int j = 0 ; j < sizes[i].size() - 1; j++)
        {
            if (maxX < sizes[i][j]) maxX = sizes[i][j];
            if (maxY < sizes[i][j + 1]) maxY = sizes[i][j + 1];
        }
    }

    answer = maxX * maxY;

    return answer;
}

int solution(vector<vector<int>> sizes)
{
    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
}

int main()
{
    vector<int> arr = { 1, 1, 2, 2, 3, 3, 0, 1, 1 };

    vector<int> result = Solution(arr);
    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}
*/
#pragma endregion