/***************************************************************************
                          encrypt.cpp  -  description
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
#include "encrypt.h"
#include "common.h"

#include <stdio.h>

int enc_mode = 3;
int enc_method = 1;

void encrypt::clear()
{
	QRadioButton_1->setChecked(false);
	QRadioButton_2->setChecked(false);
	QRadioButton_3->setChecked(false);
	QRadioButton_7->setChecked(false);
	QRadioButton_8->setChecked(false);
}

void encrypt::encrypt_ok()
{
	char keyword[100];
	long q = 0;
	if(QRadioButton_1->isChecked()) enc_mode = 1;
	if(QRadioButton_2->isChecked()) enc_mode = 2;
	if(QRadioButton_3->isChecked()) enc_mode = 3;
	if(QRadioButton_7->isChecked()) enc_method = 1;
	if(QRadioButton_8->isChecked()) enc_method = 2;
	strcpy(keyword, QLineEdit_1->text());
	for(int j = 0; j < (int)strlen(maintext); j++)
	{
		if((enc_mode == 3) && (enc_method == 1) && valid(maintext[j]))
		{
			maintext[j] = substitution[q%(strlen(keyword))][where_in_substs(maintext[j])];
			q++;
		}
		if((enc_mode == 3) && (enc_method == 2) && valid(maintext[j]))
		{
			maintext[j] = substitution[where_in_substc(keyword[q%strlen(keyword)])]
				[where_in_substs(maintext[j])];
			q++;
		}
		if((enc_mode == 2) && valid(maintext[j]))
		{
			maintext[j] = substitution[0][where_in_substs(maintext[j])];
			q++;
		}
		if((enc_mode == 1) && valid(maintext[j]))
		{
			maintext[j] = substitution[0][where_in_substs(maintext[j])];
			q++;
		}
	}
	kwoodw->updatetext();
	this->~encrypt();
}

void encrypt::encrypt_cancel()
{
	this->~encrypt();
}

void encrypt::radiobutton_1()
{
	clear();
	QRadioButton_1->setChecked(true);
	QRadioButton_7->setEnabled(false);
	QRadioButton_8->setEnabled(false);
}

void encrypt::radiobutton_2()
{
	clear();
	QRadioButton_2->setChecked(true);
	QRadioButton_7->setEnabled(false);
	QRadioButton_8->setEnabled(false);
}

void encrypt::radiobutton_3()
{
	clear();
	QRadioButton_3->setChecked(true);
	QRadioButton_7->setEnabled(true);
	QRadioButton_8->setEnabled(true);
	QRadioButton_8->setChecked(true);
	enc_method = 2;
}

bool allvalid(const char *str, bool strict)
{
	if(strlen(str) == 0) return strict;
	for(int i = 0; i < (int)strlen(str); i++)
		if(!valid(str[i])) return false;
	if(!strict) return true;
	for(int i = 0; i < (int)strlen(str); i++)
		for(int j = 0; j < (int)strlen(str); j++)
		if((i != j) && (str[i] == str[j])) return false;
	return true;
}

void encrypt::input()
{
	if(allvalid(QLineEdit_1->text(), false)) QPushButton_1->setEnabled(true);
	else QPushButton_1->setEnabled(false);
}

encrypt::encrypt(QWidget *parent, const char *name) : QDialog(parent,name,true){
	initDialog();
	connect(QRadioButton_1, SIGNAL(clicked()), SLOT(radiobutton_1()));
	connect(QRadioButton_2, SIGNAL(clicked()), SLOT(radiobutton_2()));
	connect(QRadioButton_3, SIGNAL(clicked()), SLOT(radiobutton_3()));
	connect(QPushButton_1, SIGNAL(clicked()), SLOT(encrypt_ok()));
	connect(QPushButton_2, SIGNAL(clicked()), SLOT(encrypt_cancel()));
	connect(QLineEdit_1, SIGNAL(textChanged(const char *)), SLOT(input()));
	clear();
	if(enc_mode == 1) QRadioButton_1->animateClick();
	if(enc_mode == 2) QRadioButton_2->animateClick();
	if(enc_mode == 3) QRadioButton_3->animateClick();
	if(enc_method == 1) QRadioButton_7->animateClick();
	if(enc_method == 2) QRadioButton_8->animateClick();
}

encrypt::~encrypt(){
}