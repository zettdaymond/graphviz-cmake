/* $Id: tclStubLib.c,v 1.4 2011/01/25 16:30:52 ellson Exp $ $Revision: 1.4 $ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* this dummy file is here to fool libtool and automake */
#include "tcl.h"

/* need to reference an entry point to fool Sun's ld */
void tclstubs_dummy(void)
{
    Tcl_InitStubs(0, 0, 0);
}
