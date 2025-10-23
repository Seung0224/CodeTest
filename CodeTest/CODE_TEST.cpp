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


#pragma region 1. 같은 숫자는 싫어
/*
배열 arr가 주어집니다.배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면[1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면[4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

제한사항
배열 arr의 크기 : 1, 000, 000 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수

// 내가 푼 방법
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

#pragma region 2. 최소 직사각형
/*
명함 지갑을 만드는 회사에서 지갑의 크기를 정하려고 합니다. 다양한 모양과 크기의 명함들을 모두 수납할 수 있으면서, 작아서 들고 다니기 편한 지갑을 만들어야 합니다. 이러한 요건을 만족하는 지갑을 만들기 위해 디자인팀은 모든 명함의 가로 길이와 세로 길이를 조사했습니다.

아래 표는 4가지 명함의 가로 길이와 세로 길이를 나타냅니다.

명함 번호	가로 길이	세로 길이
1	60	50
2	30	70
3	60	30
4	80	40
가장 긴 가로 길이와 세로 길이가 각각 80, 70이기 때문에 80(가로) x 70(세로) 크기의 지갑을 만들면 모든 명함들을 수납할 수 있습니다. 하지만 2번 명함을 가로로 눕혀 수납한다면 80(가로) x 50(세로) 크기의 지갑으로 모든 명함들을 수납할 수 있습니다. 이때의 지갑 크기는 4000(=80 x 50)입니다.

모든 명함의 가로 길이와 세로 길이를 나타내는 2차원 배열 sizes가 매개변수로 주어집니다. 모든 명함을 수납할 수 있는 가장 작은 지갑을 만들 때, 지갑의 크기를 return 하도록 solution 함수를 완성해주세요.

제한사항
sizes의 길이는 1 이상 10,000 이하입니다.
sizes의 원소는 [w, h] 형식입니다.
w는 명함의 가로 길이를 나타냅니다.
h는 명함의 세로 길이를 나타냅니다.
w와 h는 1 이상 1,000 이하인 자연수입니다.

// 내가 푼 방법
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