#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health;
    
    int bandageCount = 0; // 얼마나 붕대 감았는지
    int monsterAttackTime = attacks[0][0]; // 첫 몬스터 공격 타임
    int monsterAttack = attacks[0][1]; // 첫 몬스터 피해량
    
    int monsterCount = 0; //
    
    for(int i = 1; i <= attacks[attacks.size() -1][0]; i++) {
        if(monsterAttackTime == i) { //몬스터가 공격할 차례일 때
            bandageCount = 0;
            hp -= monsterAttack;
            if(hp <= 0) return -1;//죽으면 리턴
            
            if(monsterCount + 1 < attacks.size()) {
                monsterCount++;
                monsterAttackTime = attacks[monsterCount][0];
                monsterAttack = attacks[monsterCount][1];
            }            
        }
        else { // 공격 안해서 붕대 감을 떄
            bandageCount++;
            hp += bandage[1];
            if(bandageCount == bandage[0]) { //밴드 연속해서 감으면 추가 회복
                bandageCount = 0;
                hp += bandage[2];
            }
            if(hp > health) hp = health; // 최대 체력으로
        }
    }
    
    return hp;
}