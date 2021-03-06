/****************************************************************/
/*                      DO NOT MODIFY THIS HEADER               */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*              (c) 2010 Battelle Energy Alliance, LLC          */
/*                      ALL RIGHTS RESERVED                     */
/*                                                              */
/*              Prepared by Battelle Energy Alliance, LLC       */
/*              Under Contract No. DE-AC07-05ID14517            */
/*              With the U. S. Department of Energy             */
/*                                                              */
/*              See COPYRIGHT for full restrictions             */
/****************************************************************/
#ifndef ZAPDOSEEDFRATECONSTANT_H_
#define ZAPDOSEEDFRATECONSTANT_H_

#include "Material.h"
/* #include "LinearInterpolation.h" */
#include "SplineInterpolation.h"

class ZapdosEEDFRateConstant;

template <>
InputParameters validParams<ZapdosEEDFRateConstant>();

class ZapdosEEDFRateConstant : public Material
{
public:
  ZapdosEEDFRateConstant(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();

  SplineInterpolation _coefficient_interpolation;

  Real _r_units;
  bool _elastic;
  MaterialProperty<Real> & _reaction_rate;
  MaterialProperty<Real> & _d_k_d_en;
  MaterialProperty<Real> & _energy_elastic;
  std::string _sampling_format;

  const MaterialProperty<Real> & _massIncident;
  const MaterialProperty<Real> & _massTarget;
  // const MaterialProperty<Real> & _reduced_field;
  const VariableValue & _sampler;
  const VariableValue & _em;
  const VariableValue & _mean_en;
};

#endif // ZAPDOSEEDFRATECONSTANT_H_
