/*
배열 arr가 주어집니다.배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면[1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면[4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

제한사항
배열 arr의 크기 : 1, 000, 000 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 내가 푼 방법
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