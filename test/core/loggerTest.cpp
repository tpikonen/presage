
/******************************************************************************\
 *                                                                            *
 * Soothsayer, an extensible predictive text entry system                     *
 * ------------------------------------------------------                     *
 *                                                                            *
 * Copyright (C) 2004  Matteo Vescovi <matteo.vescovi@yahoo.co.uk>             *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software                *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*
 *                                                                            *
\******************************************************************************/        


#include "loggerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( LoggerTest );

void LoggerTest::setUp()
{
}

void LoggerTest::tearDown()
{
}

void LoggerTest::testStandardErrorOutput()
{
    Logger<char>* logger = new Logger<char>(std::cerr);
    
    *logger << "[LoggerTest] testStandardErrorOutput";
}

void LoggerTest::testFileOutput()
{

}

void LoggerTest::testSetLevelManipulator()
{
    Logger<char> logger(std::cerr);
    logger << setlevel("FATAL");

    CPPUNIT_ASSERT_EQUAL( Logger<char>::FATAL, logger.getLevel());

    logger << setlevel("WARN");
    CPPUNIT_ASSERT_EQUAL( Logger<char>::WARN, logger.getLevel());

    logger << setlevel("DONT_EXIST");
    CPPUNIT_ASSERT_EQUAL( Logger<char>::ERROR, logger.getLevel());
}
