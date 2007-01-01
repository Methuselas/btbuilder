#ifndef __MONSTER_H
#define __MONSTER_H
/*-------------------------------------------------------------------------*\
  <monster.h> -- Monster header file

  Date      Programmer  Description
  11/06/00  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include <istdlib.h>
#include <file.h>
#include "dice.h"

/*
 [monster]
 name: char[14]
 starting distance: short {(1 to 9) * 16}
 move: short {0 to 15}
 rate of attacks: short {0 to 15}
 illusion: short {0 or 1}
 picture: short {0 to 74}
 combat action: array[4] of short
 melee extra damage: short
 armor class: short {-21 to 10}
 max appearing: short {1 to 99}
 hit point: dice
 melee damage: dice
 melee message: char[14]
 magic resistance: short {0 to 100}
 ranged damage: dice
 unknown: byte
 ranged extra damage: short
 range: short {1 to 15}
 ranged message: char[14]
 ranged type: short {none, physical: 1 foe, physical: group, magic (+ spell index)}
 level: short {0 to 20}
 gold: dice
 unknown: byte
*/

class BTMonster
{
 public:
  BTMonster(BinaryReadFile &f);
  BTMonster();

  const char *getName() const;
  IShort getAc() const;
  IShort getCombatAction(IShort round) const;
  const BTDice &getGold() const;
  const BTDice &getHp() const;
  IShort getLevel() const;
  IShort getMagicResistance() const;
  IShort getMaxAppearing() const;
  const BTDice &getMeleeDamage() const;
  IShort getMeleeExtra() const;
  const char *getMeleeMessage() const;
  IShort getMove() const;
  IShort getPicture() const;
  IShort getRange() const;
  const BTDice &getRangedDamage() const;
  IShort getRangedExtra() const;
  const char *getRangedMessage() const;
  IShort getRangedSpell() const;
  IShort getRangedType() const;
  IShort getRateAttacks() const;
  IShort getStartDistance() const;
  IBool isIllusion() const;
  void write(BinaryWriteFile &f);

 private:
  char name[14];
  IShort level;
  IShort startDistance;
  IShort move;
  IShort rateAttacks;
  IShort illusion;
  IShort picture;
  IShort combatAction[4];
  IShort ac;
  IShort maxAppearing;
  BTDice hp;
  BTDice gold;
  IShort magicResistance;

  char meleeMessage[14];
  BTDice meleeDamage;
  IShort meleeExtra;

  char rangedMessage[14];
  IShort rangedType;
  IShort rangedSpell;
  BTDice rangedDamage;
  IShort rangedExtra;
  IShort range;
};

#endif

