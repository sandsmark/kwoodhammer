/***************************************************************************
                          setup.h  -  description
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

#ifndef SETUP_H
#define SETUP_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qcheckbox.h>
#include <qslider.h>
#include <qcombobox.h>
#include <qmultilinedit.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

extern void stat_load(char *name);
extern char *inhome(char *file);
extern void stat_make();

class setup : public QDialog  {
   Q_OBJECT
public: 
	setup(QWidget *parent=0, const char *name=0);
	~setup();
	void buildtable();
	void stat_save(char *name);

public slots:
	void radiobutton_3();
	void radiobutton_4();
	void radiobutton_5();
	void radiobutton_6();
	void checkbox_2();
	void checkbox_3();
	void slider_1(int value);
	void stat_show();
	void setup_ok();
	void stat_clear();
	void stat_add();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QLabel *QLabel_1;
	QGroupBox *QGroupBox_1;
	QPushButton *QPushButton_1;
	QPushButton *QPushButton_2;
	QRadioButton *QRadioButton_5;
	QLabel *QLabel_3;
	QRadioButton *QRadioButton_6;
	QGroupBox *QGroupBox_3;
	QRadioButton *QRadioButton_3;
	QRadioButton *QRadioButton_4;
	QCheckBox *QCheckBox_2;
	QCheckBox *QCheckBox_3;
	QSlider *QSlider_1;
	QLabel *QLabel_4;
	QComboBox *QComboBox_1;
	QPushButton *QPushButton_7;
	QPushButton *QPushButton_8;
	QPushButton *QPushButton_9;
	QPushButton *QPushButton_10;
	QMultiLineEdit *QMultiLineEdit_1;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
