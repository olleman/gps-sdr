/************************************************************************************************
Copyright 2008 Gregory W Heckler

This file is part of the GPS Software Defined Radio (GPS-SDR)

The GPS-SDR is free software; you can redistribute it and/or modify it under the terms of the
GNU General Public License as published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GPS-SDR is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along with GPS-SDR; if not,
write to the: 

Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
************************************************************************************************/

#ifndef FFT_H_
#define FFT_H_

#define MAX_RANKS (16)

/*! \ingroup CLASSES
 * 
 */
typedef class FFT
{


	private:

		MIX *W;						//!< Twiddle lookup array for FFT
		MIX *iW;					//!< Twiddle lookup array for iFFT
		int32 *BRX;					//!< Re-order temp array
		int32 *BR;					//!< Re-order index array
		
		int32 N;					//!< Length (should be 2^N!!!)
		int32 M;					//!< Log2(N) (number of ranks)
		int32 R[16];				//!< Programmable rank scaling

		void initW();				//!< Initialize twiddles
		void initBR();				//!< Initialize re-order array
		void doShuffle(CPX *_x);	//!< Do bit-reverse shuffling

	public:

		FFT();								//!< Initialize FFT
		FFT(int32 _N);						//!< Initialize FFT for 2^N
		FFT(int32 _N, int32 _R[MAX_RANKS]);			//!< Initialize FFT for 2^N, with ranks
		~FFT();								//!< Destructor
		void doFFT(CPX *_x, bool _shuf);	//!< Forward FFT, decimate in time
		void doiFFT(CPX *_x, bool _shuf);	//!< Inverse FFT, decimate in time
		void doFFTdf(CPX *_x, bool _shuf);	//!< Forward FFT, decimate in frequency
		void doiFFTdf(CPX *_x, bool _shuf);	//!< Inverse FFT, decimate in frequency

} FFT;

#endif /*FFT_H_*/
