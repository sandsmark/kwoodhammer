/***************************************************************************
                          decrypt.h  -  description
                             -------------------
    begin                : Tue Apr 11 2000
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

#ifndef DECRYPT_H
#define DECRYPT_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qslider.h>
#include <qlineedit.h>
#include <qmultilinedit.h>
#include <qcombobox.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

class decrypt : public QDialog  {
   Q_OBJECT
public: 
	decrypt(QWidget *parent=0, const char *name=0);
	~decrypt();
public slots:
	void decrypt_ok();
	void trial();
	void qslider_2(int value);
	void qslider_1(int value);
	void qslider_3(int value);
	void enabletable();
	void qcombobox_2(int value);
	void switchview();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QLabel *QLabel_1;
	QPushButton *QPushButton_1;
	QGroupBox *QGroupBox_1;
	QLabel *QLabel_3;
	QSlider *QSlider_1;
	QLineEdit *QLineEdit_1;
	QPushButton *QPushButton_3;
	QPushButton *QPushButton_4;
	QLabel *QLabel_4;
	QSlider *QSlider_2;
	QLineEdit *QLineEdit_2;
	QLabel *QLabel_2;
	QGroupBox *QGroupBox_2;
	QMultiLineEdit *QMultiLineEdit_1;
	QGroupBox *QGroupBox_3;
	QLabel *QLabel_6;
	QSlider *QSlider_3;
	QLabel *QLabel_7;
	QLabel *QLabel_10;
	QComboBox *QComboBox_2;
	QLabel *QLabel_8;
	QLabel *QLabel_9;
	QLabel *QLabel_5;
	QPushButton *QPushButton_5;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
