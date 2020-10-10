/***************************************************************************
                          common.h  -  description
                             -------------------
    begin                : Sun Apr 16 2000
    copyright            : (C) 2000 by Josef Spillner
    email                : dr_maux@maux.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "kwood.h"
#include "table.h"

extern int enc_mode;
extern int enc_method;

extern int substitution[256][256];
extern int substitutionline[256];
extern int codeline[256];
extern int snummax, snumodd;
extern long statistics[256];
extern long maxstatistics;

extern char *maintext;
extern char *maintextclear;
extern bool letters52, numbers10;

extern bool rangeletter(int letter);
extern int where_in_substc(char c);
extern int where_in_substs(char c);
extern bool valid(char c);
extern bool allvalid(const char *str, bool strict);

extern int markcount;

extern kwood *kwoodw;
extern table *tablew;

extern char *homedir;
extern char *iconhomedir;

extern bool codeview;
extern bool groupview;
