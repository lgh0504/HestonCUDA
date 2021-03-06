#ifndef __HESTONCALLQUAD_HPP__
#define __HESTONCALLQUAD_HPP__

#include "HestonCallQuadCPU.hpp"


double HestonCallQuad(
  double dKappa,
  double dTheta,
  double dSigma,
	double dRho,
  double dV0,
  double dR,
  double dT, 
	double dS0,
  double dK) {
  return HestonCallQuadCPU(dKappa, dTheta, dSigma, dRho, dV0, dR, dT, dS0, dK);
}


#endif

