
###############################################################################
#                                                                             #
#  Soothsayer, an extensible predictive text entry system                     #
#  ------------------------------------------------------                     #
#                                                                             #
#  Copyright (C) Matteo Vescovi <matteo.vescovi@yahoo.co.uk>                  #
#                                                                             #
#  This program is free software; you can redistribute it and/or              #
#  modify it under the terms of the GNU General Public License                #
#  as published by the Free Software Foundation; either version 2             #
#  of the License, or (at your option) any later version.                     #
#                                                                             #
#  This program is distributed in the hope that it will be useful,            #
#  but WITHOUT ANY WARRANTY; without even the implied warranty of             #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
#  GNU General Public License for more details.                               #
#                                                                             #
#  You should have received a copy of the GNU General Public License          #
#  along with this program; if not, write to the Free Software                #
#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. #
#                                                                             #
###############################################################################

## Build instructions
# swig -c++ -python -I../src soothsayer.i
# g++ -c -fpic soothsayer_wrap.cxx ../src/soothsayer.cpp -I/usr/include/python2.4 -I/usr/lib/python2.4/config -I../src
# g++ -shared soothsayer.o soothsayer_wrap.o -L../../build/src/.libs -lsoothsayer -o _soothsayer.so

## Test with
# python runme.py


%module soothsayer

%include "std_vector.i"
%include "std_string.i"

%{
#include "soothsayer.h"
%}

namespace std {
    %template() vector< string >;
}

/* Let's just grab the original header file here */
%include "soothsayer.h"


