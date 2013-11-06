///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/addressing.hpp
/// @date 2012-11-19 / 2012-11-19
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_ADDRESSING_INCLUDED
#define GLI_CORE_ADDRESSING_INCLUDED

#include "storage.hpp"

namespace gli{
namespace detail
{
	storage::size_type linearAddressing(
		storage const & Storage,
		storage::size_type const & LayerOffset, 
		storage::size_type const & FaceOffset, 
		storage::size_type const & LevelOffset);

}//namespace detail

	struct addressing
	{
		virtual storage::size_type operator() (
			storage const & Storage,
			storage::size_type const & LayerOffset, 
			storage::size_type const & FaceOffset, 
			storage::size_type const & LevelOffset) const = 0;
	};

	class linearAddressing : public addressing
	{
	public:
		virtual storage::size_type operator() (
			storage const & Storage,
			storage::size_type const & LayerOffset, 
			storage::size_type const & FaceOffset, 
			storage::size_type const & LevelOffset) const;
	};

}//namespace gli

#include "addressing.inl"

#endif//GLI_CORE_ADDRESSING_INCLUDED
