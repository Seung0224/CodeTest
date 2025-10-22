/*
�迭 arr�� �־����ϴ�.�迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�.�̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�.
��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�.���� ���,

arr = [1, 1, 3, 3, 0, 1, 1] �̸�[1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸�[4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
�迭 arr�� ũ�� : 1, 000, 000 ������ �ڿ���
�迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ���� Ǭ ���
vector<int> solution(vector<int> arr)
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

vector <int> Solution(vector<int>arr)
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