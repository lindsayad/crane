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

#ifndef LOGSTABILIZATIONSCALAR_H
#define LOGSTABILIZATIONSCALAR_H

#include "ODEKernel.h"

class LogStabilizationScalar;

template <>
InputParameters validParams<LogStabilizationScalar>();

class LogStabilizationScalar : public ODEKernel
{
public:
  LogStabilizationScalar(const InputParameters & parameters);
  virtual ~LogStabilizationScalar();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  Real _offset;
};

#endif /* LOGSTABILIZATIONSCALAR_H */
