/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Wed Apr  5 20:50:21 MEST 2000
    copyright            : (C) 2000 by Josef Spillner
    email                : dr_maux@users.sourceforge.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "common.h"
#include <kapp.h>
#include <stdlib.h>

kwood *kwoodw;
char *homedir;
char *iconhomedir;

int main(int argc, char *argv[])
{
  KApplication a(argc, argv, "KWoodhammer");
	homedir = (char*)malloc(strlen(a.localkdedir())+1);
	iconhomedir = (char*)malloc(strlen(a.kde_icondir())+1);
	strcpy(homedir, a.localkdedir());
	strcpy(iconhomedir, a.kde_icondir());
	kwoodw = new kwood();
  a.setMainWidget(kwoodw);
	kwoodw->setGeometry(200, 200, 400, 260);
	kwoodw->splashBegin();
  return a.exec();
}
