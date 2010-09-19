# Kimura

Kimura is an experimental, modular, web scale, multi-purpose server daemon.
It's under heavy development and is completely useless and will remain that way
for a very long time.

## Features

This list is not complete and may contain features that won't ever make it into Kimura.

### Minimum Feature Set

* Run as a daemon
* Load a configuration file
* Parse command line args overriding configuration file
* HTTP 1.1
* SSL support
* Client certificates
* HTTP Authentication
  - htpasswd, PAM, and built-in support
* Virtual hosts
  - Each host has its own context
* Logging mechanism
  - File, syslog, Gearman, comet
  - Automatic log rotation and compression
* HTTP compression (gzip)
* URL rewriting
* Support for IP4 and IP6
* Privilege separation
  - Command authorization (cert, username, password, token, ?)
* On the fly binary upgrading and configuration reloading
* Thread management
* Module loading
* Event system
* Abstraction library for common operations
  - File I/O
  - Network I/O
  - Message queuing
  - Date/time
  - System info

### Bonus Feature Set
* snmp
* Traffic shaping
* Performance measurements
  - Network subsystem
  - File I/O
  - Threads
  - Mutexes, RW locks
* Extended security
  - Ban after X failed logins for given timeout
* 32-bit support (Kimura is designed for 64-bit machines)

## Architecture

Kimura's design is constantly in a state of flux, but here's some ideas of how
it's architected.

	main()
	- initialize the setProcessTitle() function
	- initialize signals
	- parse command line args
	- load server config from file
	  - read from -c flag, ~/.kimura.conf, /etc/kimura/kimura.conf, or /etc/kimura.conf
	  - parse json into config registry
	    - path/key => value
	- load plugins
	  - if -t, plugins test their config settings, exit
	- if run as daemon, daemonize
	- if enable priv sep, separate, spawn child
	- child process
	  - init plugins
	    - bind sockets
	  - switch user/group
	  - spawn threads
	    - enter plugin event loop
	      - process events
	- parent process
	  - enter priv sep event loop
	    - process commands
	  - unload plugins
	  - cleanup
	  - exit

## Command Line Arguments

	Flags				| Description
	--------------------+-------------------------------------------
	-d, --daemon		| Run Kimura in daemon mode
	-h, --help			| Show the help screen
	-t, --test			| Test the config, then exit
	-v, --version		| Display the current version
	-V, --verbose		| Display verbose information to console
	
	Arguments			| Default Value					| Description
	--------------------+-------------------------------+---------------------------------------------------------------------
	-c, --conf <path>	| ~/.kimura.conf,				| The path of the Kimura configuration file
						| /etc/kimura/kimura.conf,		|
						| /etc/kimura.conf				|
	-g, --group <group>	| current group					| Run Kimura as a specific group, overrides configuration file value
	-m, --manager <?>	| [null] (uses local instance)	| A comma-separated list of manager node IP addresses
	-u, --user <user>	| current user					| Run Kimura as a specific user, overrides configuration file value

## License

Kimura is licensed under the New BSD License.
