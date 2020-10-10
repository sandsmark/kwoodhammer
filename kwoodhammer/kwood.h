/***************************************************************************
                          kwood.h  -  description
                             -------------------
    begin                : Wed Apr 5 2000
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

#ifndef KWOOD_H
#define KWOOD_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qlabel.h>
#include <qmultilinedit.h>
#include <qpushbutton.h>
//Generated area. DO NOT EDIT!!!(end)

#include <kapp.h>

/**
  *@author Josef Spillner
  */

class kwood : public QWidget  {
   Q_OBJECT
public: 
	kwood(QWidget *parent=0, const char *name=0);
	~kwood();
	char mark(int markchar);
	int count();
	void updatetext();

public slots:
	void splashBegin();
	void splashEnd();

	void iconEncrypt();
	void iconDecrypt();
	void iconSetup();
	void iconInfo();
	void iconNew();
	void iconOpen();
	void iconSave();
	void iconTable();
	void resizeEvent(QResizeEvent *r);
	void text();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QLabel *QLabel_1;
	QMultiLineEdit *QMultiLineEdit_1;
	QPushButton *QPushButton_7;
	QPushButton *QPushButton_8;
	QPushButton *QPushButton_9;
	QPushButton *QPushButton_10;
	QPushButton *QPushButton_11;
	QPushButton *QPushButton_12;
	QPushButton *QPushButton_13;
	QPushButton *QPushButton_14;
	QPushButton *QPushButton_1;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
