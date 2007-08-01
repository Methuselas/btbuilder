#ifndef __DICE_H
#define __DICE_H
/*-------------------------------------------------------------------------*\
  <dice.h> -- Dice header file

  Date      Programmer  Description
  11/07/00  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "istdlib.h"
#include <file.h>
#include "xmlserializer.h"

/*
 [dice]
 number: bits[5] (add 1)
 type: bits[3] {d2, d4, d6, d8, d10, d12, d20, d100}
*/

#define DICE_VALIDTYPES 8

class BTDice : public XMLObject
{
 public:
  BTDice(BinaryReadFile &f);
  BTDice(int n, int t, int m = 0);
  BTDice();

  int getNumber() const;
  int getType() const;
  void read(BinaryReadFile &f);
  int roll() const;
  virtual void serialize(ObjectSerializer* s);
  void setNumber(IShort val);
  void setType(IShort val);
  void write(BinaryWriteFile &f);

 private:
  int number;
  int type;
  int modifier;

  static IShort validType[DICE_VALIDTYPES];
};

#endif

