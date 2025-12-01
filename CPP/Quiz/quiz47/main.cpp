#include <iostream>
#include <string>
#include "paladin.hpp"
#include "sorcerer.hpp"

using namespace std;

int main()
{
    Paladin paladin = Paladin::Builder("해머딘")
                          .setLeftWeapon("스피릿 크리스탈 소드")
                          .setRightWeapon("스피릿 성기사 방패")
                          .setLeftRing("패캐 링")
                          .setRightRing("러번 프로스트")
                          .setArmor("수수께끼 아머")
                          .setAmulet("마라의 만화경")
                          .build();

    paladin.print();

    Sorcerer sorcerer = Sorcerer::Builder("메이지")
                            .setLeftWeapon("아크메이지 스태프")
                            .setRightWeapon("오브 오브 더 마그")
                            .setLeftRing("매직 링")
                            .setRightRing("소서러 링")
                            .setArmor("아크메이지 로브")
                            .setAmulet("소서러 아뮬렛")
                            .build();
    sorcerer.print();

    //defalut 소서러
    Sorcerer defaultSorcerer = Sorcerer::Builder("원소술사")
    .setRightWeapon("기본 지팡이")
    .build();
    defaultSorcerer.print();

    return 0;
}
