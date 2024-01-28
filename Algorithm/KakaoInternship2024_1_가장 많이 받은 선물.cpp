#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> frendsMap;
vector<vector<int>> giftMap;
vector<vector<int>> giftPointMap;

void setGiftMap(vector<string> v) {
    for (auto s : v) {
        int giv, rcv = -1;
        string name = "";
        for (auto c : s) {
            if (c == ' ') {
                giv = frendsMap[name];
                name = "";
                continue;
            }
            name += c;
        }
        rcv = frendsMap[name];
        giftMap[giv][rcv]++;
        giftPointMap[giv][0]++;
        giftPointMap[rcv][1]++;
    }
    for (int i = 0; i < giftPointMap.size(); i++) {
        giftPointMap[i][2] = giftPointMap[i][0] - giftPointMap[i][1];
    }
}

int calMaxGift() {
    vector<int> nextMounthGift(giftMap.size(), 0);
    for (int i = 0; i < giftMap.size(); i++) {
        int gift = 0;
        for (int j = 0; j < giftMap[i].size(); j++) {
            if (i == j) continue;
            if (giftMap[i][j] == -1) continue;
            if (giftMap[j][i] != giftMap[i][j]) {
                nextMounthGift[giftMap[i][j] > giftMap[j][i] ? i : j]++;
                giftMap[i][j] = -1;
                giftMap[j][i] = -1;
            }
            else if (giftMap[i][j] == giftMap[j][i]) {
                if (giftPointMap[i][2] == giftPointMap[j][2]) continue;
                nextMounthGift[giftPointMap[i][2] > giftPointMap[j][2] ? i : j]++;
                giftMap[i][j] = -1;
                giftMap[j][i] = -1;
            }


        }
    }
    int maxGift = 0;
    for (auto iter : nextMounthGift)
        if (maxGift < iter) maxGift = iter;
    return maxGift;
}

int solution(vector<string> friends, vector<string> gifts) {
    giftMap = vector<vector<int>>(friends.size(), vector<int>(friends.size()));
    giftPointMap = vector<vector<int>>(friends.size(), vector<int>(3));
    for (int i = 0; i < friends.size(); i++)
        frendsMap[friends[i]] = i;
    setGiftMap(gifts);
    return calMaxGift();
}
