#ifndef ADDZAPDOSREACTIONS_H
#define ADDZAPDOSREACTIONS_H

#include "AddVariableAction.h"
#include "Action.h"
#include "ChemicalReactionsBase.h"

class AddZapdosReactions;

template <>
InputParameters validParams<AddZapdosReactions>();

class AddZapdosReactions : public ChemicalReactionsBase
{
public:
  AddZapdosReactions(InputParameters params);

  virtual void act();

protected:
  std::string _coefficient_format;
  std::vector<std::string> _aux_species;


};

#endif // ADDZAPDOSREACTIONS_H
