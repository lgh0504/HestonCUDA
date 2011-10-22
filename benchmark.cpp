#include <iostream>
#include "BlackScholes.hpp"
#include "HestonCallFFT.hpp"


void hestonTests() {
	double tol = 1e-6;

	double fft_price_cpu_1 = HestonCallFFT(2,0.04,0.1,0.5,0.04,0.01,0.3,1.0,0.8,4096);
  double fft_price_cpu_2 = HestonCallFFT(2,0.04,0.1,0.5,0.04,0.01,1.0,1.0,1.0,4096);
  double fft_vol_cpu_1   = BlackScholesImplied(1.0, 0.8, 0.01, 0.3, fft_price_cpu_1);
  double fft_vol_cpu_2   = BlackScholesImplied(1.0, 1.0, 0.01, 1.0, fft_price_cpu_2);
	double fft_price_matlab_1 = 0.203756595588233;
  double fft_price_matlab_2 = 0.085020234245137;
  double fft_vol_matlab_1   = 0.222875129654834;
  double fft_vol_matlab_2   = 0.201741713389921;
	
	std::cout << "-- fft heston call --" << std::endl;
  std::cout << "\tCPU\t\t\tMATLAB" << std::endl;
  std::cout << "1\t" << fft_price_cpu_1 << "\t" << fft_price_matlab_1 << std::endl;
  std::cout << "2\t" << fft_price_cpu_2 << "\t" << fft_price_matlab_2 << std::endl;
  std::cout << "1\t" << fft_vol_cpu_1   << "\t" << fft_vol_matlab_1 << std::endl;
  std::cout << "2\t" << fft_vol_cpu_2   << "\t" << fft_vol_matlab_2 << std::endl;
}

int main(int args, char* argv[]) {
	std::cout.precision(16);
  hestonTests();
}

