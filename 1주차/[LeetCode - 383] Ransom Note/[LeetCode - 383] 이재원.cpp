class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    vector<char> ransom(ransomNote.begin(), ransomNote.end());
    vector<char> mag(magazine.begin(), magazine.end());

    for (int i = 0; i < ransom.size(); i++) {
        char toFind = ransom[i];
        auto it = find(mag.begin(), mag.end(), toFind);
        // ã�� ������ ���
        if(it == mag.end()){
            return false;
        } else {    // ã���� ���
            mag.erase(it);
        }
    }

    return true;
    }
};