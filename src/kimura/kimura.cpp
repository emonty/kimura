/*
 * Copyright (c) 2009-2010 Chris Barber <chris@cb1inc.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <config.h>
#include <iostream>
#include <kimura/Kimura.h>
#include <kimura/Exception.h>
#include <kimura/CmdLineArgs/Parser.h>
#include <kimura/Process/Daemonize.h>
#include <kimura/Process/PrivSep.h>
#include <kimura/Process/SetTitle.h>
#include <kimura/ServerConfig.h>
#include <kimura/signals.h>

using namespace kimura;

int version();
int help(CmdLineArgs::Parser& args, Exception* ex);

int main(int argc, char** argv) {
	try {
		CmdLineArgs::Parser args;
		ServerConfig config;
	
		// initialize the server config
		config.init();
	
		// parse the command line arguments and possibly display the version or help
		try {
			args.parse(argc, argv);
			if (args.isSet('v'))
				return version();
			else if (args.isSet('h'))
				return help(args, NULL);
		} catch (Exception &ex) {
			return help(args, &ex);
		}
	
		// load the config variables from both the command line args and config file
		config.load(args);
	
		// initialize the setProcessTitle() function
		Process::initSetProcessTitle(argv);
	
		// initialize signals
		// init_signals();
	
		// load & init plugins
	
		// have each plugin test their config setting
	
		if (args.isSet('t')) {
			std::cout << "Config file looks good!\n";
			return EXIT_SUCCESS;
		}
	
		// TODO: start local manager
		// TODO: connect to remote manager(s) if applicable
	
		// if (config["daemon"]) {
		// daemonize();
		// }
	
		// if (config["enable priv sep"]) {
		//PrivSep::partition(config);
		//}
	
		// switch user/group
		// bind sockets

		// init plugin interface
		// init memory storage
		// init thread pool
		// init logging

		// tell main process to bind IPs/ports
		// connect to peers
		// listen for connections
	
		/*
		std::cout << "Hi from the worker server! pid=" << ::getpid() << "\n";
		for (int i=0; i<10; i++) {
			std::cout << "Worker " << (i+1) << "/10 is doing work!\n";
			::sleep(1);
		}
		*/
	} catch (std::exception &e) {
		std::cerr << e.what();
		// TODO: shutdown
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

int version() {
	std::cout << KIMURA_APP_TITLE " v" KIMURA_RELEASE_VERSION "\n"
		"   \"" KIMURA_VC_BRANCH "\" branch, rev " << KIMURA_VC_REVNO << ", compiled " << MONTH << '/' << DAY << '/' << YEAR << ' ' << __TIME__ << "\n\n"
		"Copyright (c) " << KIMURA_COPYRIGHT_START_YEAR;
	
	if (KIMURA_COPYRIGHT_START_YEAR < YEAR)
		std::cout << '-' << YEAR;
	
	std::cout << " Chris Barber\n\n"
		"Kimura is open source software\n<" KIMURA_WEBSITE ">\n";
	
	return EXIT_SUCCESS;
}

int help(CmdLineArgs::Parser& args, Exception* ex) {
	version();
	
	if (ex != NULL) {
#ifdef DEBUG
		std::cout << "\n " << ex->what() << "\n";
#else
		std::cout << "\n " << /*ExceptionType::label[ex->getExceptionType()] << */ "Exception: " << ex->getMessage() << "\n";
#endif
	}
	
	args.help(std::cout);
	
	return EXIT_SUCCESS;
}
