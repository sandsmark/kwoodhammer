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
#include <qdir.h>

kwood *kwoodw;

static void ensureDataDir()
{
  QDir    dir;
  QString fullpath;
  fullpath.sprintf("%s/share/apps/kwoodhammer/", KApplication::localkdedir().data());
  dir.setPath(fullpath);
  if (!dir.exists()) {
      dir.mkdir(fullpath);
  }
}

int main(int argc, char *argv[])
{
  KApplication a(argc, argv, "KWoodhammer");
  ensureDataDir();

	kwoodw = new kwood();
  a.setMainWidget(kwoodw);
	kwoodw->setGeometry(200, 200, 400, 260);
	kwoodw->splashBegin();
  return a.exec();
}
