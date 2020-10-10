/***************************************************************************
                          progress.cpp  -  description
                             -------------------
    begin                : Tue May 2 2000
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
#include "progress.h"

bool can;

progress::progress(QWidget *parent, const char *name) : QDialog(parent,name,false)
{
	initDialog();
}

progress::~progress()
{
}

void progress::setvalue(int value)
{
	QProgressBar_1->setProgress(value);
}

void progress::setmaxvalue(int maxvalue)
{
	QProgressBar_1->setTotalSteps(maxvalue);
}
