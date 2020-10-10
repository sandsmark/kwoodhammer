/***************************************************************************
                          kwood.cpp  -  description
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
#include "kwood.h"
#include "encrypt.h"
#include "decrypt.h"
#include "setup.h"
#include "info.h"
#include "table.h"

#include "common.h"

#include <qmessagebox.h>
#include <qfiledialog.h>
#include <stdio.h>
#include <stdlib.h>
#include <qtimer.h>
#include <qevent.h>

WFlags WStyle_Splash = WStyle_Customize | WStyle_Tool | WStyle_NoBorder;
QWidget *splash;
QTimer *timer;
int substitution[256][256];
long statistics[256];
long maxstatistics;
int substitutionline[256];
int codeline[256];
int snummax = 26;
int snumodd = 0;
char *maintext;
char *maintextclear;

void kwood::splashBegin()
{
	splash = new QWidget( 0, "", WStyle_Splash);
	splash->setBackgroundPixmap(QPixmap(inlib("kwoodhammer.gif")));
  splash->setMinimumSize(320,200);
  splash->setMaximumSize(320,200);
	splash->show();
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), SLOT(splashEnd()));
	timer->start(2000);
}

void kwood::splashEnd()
{
	splash->hide();
	this->show();
}

void cswap(long *a, long *b)
{
	if(*a == *b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

bool valid(char c)
{
	bool x = false;
	for(int i = 0; i < snummax - snumodd; i++)
		if(codeline[i] == c) x = true;
	return x;
}

int xrandom(int max)
{
	return (int)(max*((float)rand()/(float)RAND_MAX));
}

int where_in_substs(char c)
{
	int x = -1;
	int j = 1;
	for(int i = 0; i < snummax; i++)
	{
		if((substitutionline[i] == c) && (x == -1))
		{
			x = i;
			while(substitutionline[i + j] == c)
			{
				if(xrandom(3) != 0) x = i + j;
				j++;
			}
		}
	}
	return x;
}

int where_in_substc(char c)
{
	int x = -1;
	for(int i = 0; i < snummax - snumodd; i++)
		if(codeline[i] == c) x = i;
	return x;
}

void kwood::iconEncrypt()
{
	maintext = (char*)realloc(maintext, strlen(QMultiLineEdit_1->text()) + 1);
	strcpy(maintext, QMultiLineEdit_1->text());
	maintextclear = (char*)realloc(maintextclear, strlen(QMultiLineEdit_1->text()) + 1);
	strcpy(maintextclear, QMultiLineEdit_1->text());
	encrypt *encryptw = new encrypt();
	encryptw->setCaption("Encryption");
	encryptw->show();
}

void kwood::iconDecrypt()
{
	if(!codeview)
	{
		codeview = true;
		kwoodw->updatetext();
	}
	maintext = (char*)realloc(maintext, strlen(QMultiLineEdit_1->text()) + 1);
	maintextclear = (char*)realloc(maintextclear, strlen(QMultiLineEdit_1->text()) + 1);
	strcpy(maintext, QMultiLineEdit_1->text());
	strcpy(maintextclear, QMultiLineEdit_1->text());
	markcount = count();
	decrypt *decryptw = new decrypt();
	decryptw->setCaption("Decryption");
	decryptw->show();
}

void kwood::iconInfo()
{
	info *infow = new info();
	infow->setCaption("Information");
	infow->show();
}

void kwood::iconTable()
{
 	table *tablew = new table();
	tablew->setCaption("Key Table");
	tablew->show();
}

void kwood::iconSetup()
{
	maintext = (char*)realloc(maintext, strlen(QMultiLineEdit_1->text()) + 1);
	strcpy(maintext, QMultiLineEdit_1->text());
	setup *setupw = new setup();
	setupw->setCaption("Setup");
	setupw->show();
}

void kwood::iconNew()
{
	QMultiLineEdit_1->clear();
}

void kwood::resizeEvent(QResizeEvent *r)
{
	QMultiLineEdit_1->resize(width() - 20, height() - 100);
}

int kwood::count()
{
	char str[3000];
	int chars = 0;
	for(int i = 0; i < QMultiLineEdit_1->numLines(); i++)
	{
		strcpy(str, QMultiLineEdit_1->textLine(i));
		for(int j = 0; j < (int)strlen(str); j++)
			if(valid(str[j])) chars++;
	}
	return chars;
}

char kwood::mark(int markchar)
{
	int line = 0, newline = 0, col = 0, newcol = 0, chars = 0, abschars = 0;
	char str[3000];
	for(int i = 0; i < QMultiLineEdit_1->numLines(); i++)
	{
		strcpy(str, QMultiLineEdit_1->textLine(i));
		for(int j = 0; j < (int)strlen(str); j++)
		{
			if(valid(str[j])) chars++;
			abschars++;
			if(chars == markchar)
			{
				col = j;
				break;
			}
		}
		if(chars == markchar)
		{
			line = i;
			break;
		}
		abschars++;
	}
	if(col == (int)strlen(str))
	{
		newline = line + 1;
		newcol = 0;
	}
	else
	{
		newline = line;
		newcol = col + 1;
	}
	QMultiLineEdit_1->setCursorPosition(line, col, false);
	QMultiLineEdit_1->setCursorPosition(newline, newcol, true);
	return maintext[abschars - 1];
}

void kwood::iconOpen()
{
	char n[3000];
	QString fd = QFileDialog::getOpenFileName(0, "*", this);
	if(!fd.isEmpty())
	{
		QMultiLineEdit_1->clear();
		FILE * f = fopen(fd, "r");
		do
		{
			fgets(n, 255, f);
			n[strlen(n) - 1] = 0;
			if(feof(f) == 0) QMultiLineEdit_1->append(n);
		}
		while(feof(f) == 0);
		fclose(f);
	}
	else QMessageBox::warning(this, "Access error", "Could not open file!");
}

void kwood::iconSave()
{
	QString fd = QFileDialog::getSaveFileName(0, "*", this);
	if(!fd.isEmpty())
	{
		FILE * f = fopen(fd, "w");
		for(int i = 0; i < QMultiLineEdit_1->numLines(); i++)
			fprintf(f, "%s\n", QMultiLineEdit_1->textLine(i));
		fclose(f);
	}
	else QMessageBox::warning(this, "Access error", "Could not save file!");
}

void kwood::text()
{
	bool b = (strlen(QMultiLineEdit_1->text()) != 0);
	QPushButton_8->setEnabled(b);
	QPushButton_9->setEnabled(b);
	groupview = false;	
}

void kwood::updatetext()
{
	QMultiLineEdit_1->clear();
	if(codeview) QMultiLineEdit_1->setText(maintext);
	else QMultiLineEdit_1->setText(maintextclear);
}

kwood::kwood(QWidget *parent, const char *name) : QWidget(parent,name){
	initDialog();
	this->setCaption("KWoodhammer");
	stat_load(".german");
	stat_make();
	maintext = (char*)malloc(1024);
	maintextclear = (char*)malloc(1024);
	connect(QPushButton_7, SIGNAL(clicked()), SLOT(iconSetup()));
	connect(QPushButton_8, SIGNAL(clicked()), SLOT(iconEncrypt()));
	connect(QPushButton_9, SIGNAL(clicked()), SLOT(iconDecrypt()));
	connect(QPushButton_10, SIGNAL(clicked()), SLOT(iconInfo()));
	connect(QPushButton_11, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(QPushButton_12, SIGNAL(clicked()), SLOT(iconNew()));
	connect(QPushButton_13, SIGNAL(clicked()), SLOT(iconOpen()));
	connect(QPushButton_1, SIGNAL(clicked()), SLOT(iconSave()));
	connect(QPushButton_14, SIGNAL(clicked()), SLOT(iconTable()));
	connect(QMultiLineEdit_1, SIGNAL(textChanged()), SLOT(text()));
	QPushButton_8->setEnabled(false);
	QPushButton_9->setEnabled(false);
	for(int i = 0; i < 256; i++)
		for(int j = 0; j < snummax; j++)
			substitution[i][j] = codeline[(i+j) % snummax];
}

kwood::~kwood(){

}
