/***************************************************************************
                          progress.h  -  description
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

#ifndef PROGRESS_H
#define PROGRESS_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qlabel.h>
#include <qprogressbar.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

class progress : public QDialog  {
   Q_OBJECT
public: 
	progress(QWidget *parent=0, const char *name=0);
	~progress();
	void setvalue(int value);
	void setmaxvalue(int maxvalue);

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QLabel *QLabel_1;
	QProgressBar *QProgressBar_1;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
