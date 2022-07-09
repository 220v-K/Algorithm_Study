#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_map; //�帣�� ���� �÷��� ��
    map<string, map<int, int>> playlist; //�帣 -> ������ȣ, �÷��� Ƚ��
    for (int i = 0; i < genres.size(); i++)
    {
        genres_map[genres[i]] += plays[i];
        playlist[genres[i]][i] = plays[i];
    }
    while (genres_map.size() > 0)
    {
        int max = 0;
        string temp_gen;
        for (auto gen : genres_map)
        {
            if (max < gen.second) {
                max = gen.second;
                temp_gen = gen.first;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            int index = -1, playVal = 0;
            for (auto pl : playlist[temp_gen])
            {
                if (playVal < pl.second) {
                    playVal = pl.second;
                    index = pl.first;
                }
            }
            if (index == -1) break; //�帣�� �� �Ѱ����� �뷡�ۿ� ���� ���
            answer.push_back(index);
            playlist[temp_gen].erase(index);
        }
        genres_map.erase(temp_gen);
    }
    
    return answer;
}
