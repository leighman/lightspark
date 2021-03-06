/**************************************************************************
  Lightspark, a free flash player implementation

  Copyright (C) 2009-2011  Alessandro Pignotti (a.pignotti@sssup.it)

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/

#include "fastpaths.h"
#include <cinttypes>

extern "C"
{
	void fastYUV420ChannelsToYUV0Buffer_SSE2Aligned(uint8_t* y, uint8_t* u, 
			uint8_t* v, uint8_t* out, uint32_t width, uint32_t height);
	void fastYUV420ChannelsToYUV0Buffer_SSE2Unaligned(uint8_t* y, uint8_t* u, 
			uint8_t* v, uint8_t* out, uint32_t width, uint32_t height);
}

using namespace lightspark;

void lightspark::fastYUV420ChannelsToYUV0Buffer(uint8_t* y, uint8_t* u, uint8_t* v, uint8_t* out, uint32_t width, uint32_t height)
{
	//If the width is compatible with full aligned accesses use the aligned version of the packer
	if(width%32==0)
		fastYUV420ChannelsToYUV0Buffer_SSE2Aligned(y,u,v,out,width,height);
	else
		fastYUV420ChannelsToYUV0Buffer_SSE2Unaligned(y,u,v,out,width,height);
}
