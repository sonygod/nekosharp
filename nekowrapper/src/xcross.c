/* ************************************************************************ */
/*																			*/
/*  XCross - Neko Standalone Runtime										*/
/*  Copyright (c)2006 Motion-Twin											*/
/*																			*/
/* This library is free software; you can redistribute it and/or			*/
/* modify it under the terms of the GNU Lesser General Public				*/
/* License as published by the Free Software Foundation; either				*/
/* version 2.1 of the License, or (at your option) any later version.		*/
/*																			*/
/* This library is distributed in the hope that it will be useful,			*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of			*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU		*/
/* Lesser General Public License or the LICENSE file for more details.		*/
/*																			*/
/* ************************************************************************ */
#include <neko_vm.h>
#include "sys.h"
#include <stdio.h>

extern void std_main();
extern void regexp_main();
extern void zlib_main();
#ifndef CONSOLE_MODE
extern void ui_main();
#endif

void neko_standalone_init() {
#	ifndef CONSOLE_MODE
	sys_init();
	ui_main();
#	endif
	std_main();
	regexp_main();
	zlib_main();
}

void neko_standalone_error( const char *error ) {
#	ifdef CONSOLE_MODE
	fprintf(stderr,"Error %s\n",error);
#	else
	sys_dialog("Error",error,DLG_ERROR);
#	endif
}

value neko_standalone_loader( char **argv, int argc ) {
	return neko_default_loader(argv,argc);
}

/* ************************************************************************ */
