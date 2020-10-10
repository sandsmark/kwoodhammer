/***************************************************************************
                          info.cpp  -  description
                             -------------------
    begin                : Wed Apr 12 2000
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
#include "info.h"

info::info(QWidget *parent, const char *name) : QDialog(parent,name,true)
{
	initDialog();
	connect(QPushButton_1, SIGNAL(clicked()), this, SLOT(hide()));
}

info::~info()
{
}
