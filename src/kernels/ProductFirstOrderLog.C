#include "ProductFirstOrderLog.h"

// MOOSE includes
#include "MooseVariable.h"

registerMooseObject("CraneApp", ProductFirstOrderLog);

template <>
InputParameters
validParams<ProductFirstOrderLog>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("v", "The first variable that is reacting to create u.");
  params.addCoupledVar("w", "The second variable that is reacting to create u.");
  params.addRequiredParam<std::string>("reaction", "The full reaction equation.");
  params.addRequiredParam<Real>("coefficient", "The stoichiometric coeffient.");
  params.addParam<bool>("_v_eq_u", false, "If v == u.");
  params.addParam<bool>("_w_eq_u", false, "If w == u.");
  return params;
}

ProductFirstOrderLog::ProductFirstOrderLog(const InputParameters & parameters)
  : Kernel(parameters),
    _v(isCoupled("v") ? coupledValue("v") : _zero),
    _v_id(isCoupled("v") ? coupled("v") : 0),
    _n_gas(getMaterialProperty<Real>("n_gas")),
    _reaction_coeff(getMaterialProperty<Real>("k_" + getParam<std::string>("reaction"))),
    _stoichiometric_coeff(getParam<Real>("coefficient")),
    _v_eq_u(getParam<bool>("_v_eq_u"))
{
}

Real
ProductFirstOrderLog::computeQpResidual()
{
  Real mult1;

  if (isCoupled("v"))
    mult1 = std::exp(_v[_qp]);
  else
  {
    mult1 = _n_gas[_qp];
  }

  return -_test[_i][_qp] * _stoichiometric_coeff * _reaction_coeff[_qp] * mult1;
}

Real
ProductFirstOrderLog::computeQpJacobian()
{
  Real mult1, power, eq_u_mult, gas_mult;
  power = 0.0;
  eq_u_mult = 1.0;
  gas_mult = 1.0;

  if (isCoupled("v"))
    mult1 = std::exp(_v[_qp]);
  else
    mult1 = _n_gas[_qp];

  if (_v_eq_u)
  {
    power += 1.0;
    eq_u_mult *= mult1;
  }

  gas_mult *= mult1;

  if (!_v_eq_u)
  {
    return 0.0;
  }
  else
  {
    return -_test[_i][_qp] * _stoichiometric_coeff * power * _reaction_coeff[_qp] * gas_mult * _phi[_j][_qp];
  }
}

Real
ProductFirstOrderLog::computeQpOffDiagJacobian(unsigned int jvar)
{

  if (isCoupled("v"))
  {
    if (jvar == _v_id)
      return -_test[_i][_qp] * _stoichiometric_coeff * _reaction_coeff[_qp] *
              std::exp(_v[_qp]) * _phi[_j][_qp];
    else
      return 0.0;
  }
  else
  {
    return 0.0;
  }
}
