/***************************************************************************
                          info.h  -  description
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

#ifndef INFO_H
#define INFO_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qmultilinedit.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

class info : public QDialog  {
   Q_OBJECT
public: 
	info(QWidget *parent=0, const char *name=0);
	~info();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QGroupBox *QGroupBox_1;
	QLabel *QLabel_1;
	QPushButton *QPushButton_1;
	QLabel *QLabel_2;
	QLabel *QLabel_3;
	QMultiLineEdit *QMultiLineEdit_1;
	QLabel *QLabel_4;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
