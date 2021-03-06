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

#ifndef EEDFRATECOEFFICIENTSCALAR_H
#define EEDFRATECOEFFICIENTSCALAR_H

#include "AuxScalarKernel.h"
#include "SplineInterpolation.h"
#include "BoltzmannSolverScalar.h"

class EEDFRateCoefficientScalar;

template <>
InputParameters validParams<EEDFRateCoefficientScalar>();

class EEDFRateCoefficientScalar : public AuxScalarKernel
{
public:
  EEDFRateCoefficientScalar(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const BoltzmannSolverScalar & _data;
  int _reaction_number;
  bool _sample_value;
  const VariableValue & _sampler_var;
};

#endif // EEDFRATECOEFFICIENTSCALAR_H
