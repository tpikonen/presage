
/*****************************************************************************\
 *                                                                           *
 * Soothsayer, an extensible predictive text entry system                    *
 * ------------------------------------------------------                    *
 *                                                                           *
 * Copyright (C) 2004  Matteo Vescovi <matteo.vescovi@yahoo.co.uk>            *
 *                                                                           *
 * This program is free software; you can redistribute it and/or             *
 * modify it under the terms of the GNU General Public License               *
 * as published by the Free Software Foundation; either version 2            *
 * of the License, or (at your option) any later version.                    *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License for more details.                              *
 *                                                                           *
 * You should have received a copy of the GNU General Public License         *
 * along with this program; if not, write to the Free Software               *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.*
 *                                                                           *
\*****************************************************************************/        

#ifndef SOOTH_PLUGIN
#define SOOTH_PLUGIN

//PLUMP
//#include "plump/src/pluginInterface.h"

#include "core/prediction.h"
#include "core/historyTracker.h"
#include "option.h"

#include <string>
#include <vector>

/** Plugin is an abstract class that defines the interface implemented by concrete predictive plugins.
 * 
 * The prediction implemented by predictive plugins is at the heart of soothsayer.
 * The plugin-based architecture allows new prediction methods to be easily and transparently added to the system.
 * 
 * Predictive plugins have access to and rely on the services provided by core components of the soothsayer system.
 *
 */
class Plugin {
//PLUMP    : public plump::PluginInterface {
public:
    Plugin(HistoryTracker& historyTracker,
           const char* pluginName = "Plugin",
           const char* shortDescription = "",
           const char* longDescription = "");
    virtual ~Plugin();

    virtual Prediction predict() const = 0;

    virtual void learn() = 0;
    virtual void extract() = 0;
    virtual void train() = 0;

    const std::string getName() const;
    const std::string getShortDescription() const;
    const std::string getLongDescription() const;

    /*
      void setLibFilename( const std::string );
      std::string getLibFilename() const;
      void setLibHandle( lt_dlhandle );
      lt_dlhandle getLibHandle() const;
    */

    // get option methods
    std::vector<std::string> getOptionTemplate() const;
    std::string getOptionValue(const std::string) const;
    std::string getOptionDefault(const std::string) const;
    std::string getOptionDescription(const std::string) const;
    // set option method
    bool setOptionValue(const std::string, const std::string);

protected:
    const std::string name;
    const std::string shortDescription; // plugin's descriptive name
    const std::string longDescription;  // plugin's exhaustive description

    HistoryTracker &historyTracker;

    std::vector< Option > options;      // plugin's options
	
private:
    /*
      std::string libFilename;          // stores plugin's library's filename
      //	void* libHandle;
      lt_dlhandle libHandle;
    */

};

////
// Excerpt taken from C++-dlopen HOWTO
//
// Loading classes is a bit more difficult because we need an instance
// of a class, not just a pointer to a function.
//
// We cannot create the instance of the class using new because the
// class is not defined in the executable, and because (under some
// circumstances) we don't even know its name.
//
// The solution is achieved through polymorphism. We define a base,
// interface class with virtual members in the executable, and a
// derived, implementation class in the module. Generally the
// interface class is abstract (a class is abstract if it has pure
// virtual functions).
//
// As dynamic loading of classes is generally used for plug-ins which
// must expose a clearly defined interface we would have had to define
// an interface and derived implementation classes anyway.
//
// Next, while still in the module, we define two additional helper
// functions, known as class factory functions. One of these functions
// creates an instance of the class and returns a pointer to it. The
// other function takes a pointer to a class created by the factory
// and destroys it. These two functions are qualified as extern "C".
//
// To use the class from the module, load the two factory functions
// using dlsym just as we loaded the the hello function; then, we can
// create and destroy as many instances as we wish.

// Class factory function types
// typedef Plugin* create_t( HistoryTracker& );
// typedef void destroy_t( Plugin* );


#endif // SOOTH_PLUGIN