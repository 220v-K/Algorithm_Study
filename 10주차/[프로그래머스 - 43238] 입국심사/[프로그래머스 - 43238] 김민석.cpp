#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
��� ����� �ɻ� �޴µ� �ɸ��� �ð��� �ּڰ� = > �ð�
�ּ� �ð�(��ٸ��� ��� 1�� �ɻ�� �ɻ� �ð� 1��)�� 1��, 
�ִ� �ð�(��ٸ��� ��� n���� �ɽ� �ð��� ����� �ɻ������ �� ���°��)�� times[times.size()-1] * n�� (times ����)
start = 1 ,end = times[tiems.size() -1] * n
mid �ð� (�� �ð����� ó�� �� ���ִ� ����� �� ����)

mid�� n���� ������ start ó��
mid�� n���� ũ�� end ó��
start < end ��� �ݺ�
*/
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long start = 1;
    long long end = (long long)times[times.size() - 1] * n; 
    long long mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        long long count = 0;

        for (int i = 0; i < times.size(); i++)
        {
            count += mid / times[i];
        }
        if (count < n) {
            start = mid + 1;
        }
        else {
            if (mid <= end)
                answer = mid;

            end = mid - 1;
        }  
    }
  
    return answer;
}

