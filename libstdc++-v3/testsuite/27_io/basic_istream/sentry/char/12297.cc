// Copyright (C) 2003-2018 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 27.6.1.1.2 class basic_istream::sentry

#include <sstream>
#include <testsuite_hooks.h>

int main()
{
  using namespace std;
  istringstream stream;
  stream.exceptions(ios_base::eofbit);

  // The library throws the new definition of std::ios::failure
#if _GLIBCXX_USE_CXX11_ABI
    typedef std::ios_base::failure exception_type;
#else
    typedef std::exception exception_type;
#endif

  try
    {
      istream::sentry sentry(stream, false);
      VERIFY( false );
    }
  catch (exception_type&)
    {
      VERIFY( stream.rdstate() == (ios_base::eofbit | ios_base::failbit) );
    }

  return 0;
}
