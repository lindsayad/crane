/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef VARIABLESUM_H
#define VARIABLESUM_H

#include "AuxScalarKernel.h"
// #include "SplineInterpolation.h"

class VariableSum;

template <>
InputParameters validParams<VariableSum>();

class VariableSum : public AuxScalarKernel
{
public:
  VariableSum(const InputParameters & parameters);

protected:
  virtual Real computeValue();
  unsigned int _nargs;
  std::vector<const VariableValue *> _args;
};

#endif // VARIABLESUM_H
