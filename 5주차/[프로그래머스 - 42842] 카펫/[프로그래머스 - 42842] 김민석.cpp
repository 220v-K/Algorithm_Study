#include <string>
#include <vector>

using namespace std;
//x + y = brown /2 + 2�� ���� ��� x,y�� ���ؼ� (x-2) * (y-2)�� yellow���� Ȯ��
vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int y = 3; y; y++)
    {
        int x = (brown / 2) + 2 - y;
        if ((x - 2) * (y - 2) == yellow) {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }

    return answer;
}