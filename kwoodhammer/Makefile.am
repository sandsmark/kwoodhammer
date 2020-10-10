####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = kwoodhammer
kwoodhammer_SOURCES = progressdata.cpp progress.cpp tabledata.cpp table.cpp setupdata.cpp setup.cpp infodata.cpp info.cpp decryptdata.cpp decrypt.cpp encryptdata.cpp encrypt.cpp kwooddata.cpp kwood.cpp main.cpp 
kwoodhammer_LDADD   = -lkdeui -lkdecore -lqt -lXext -lX11 $(LIBSOCKET)

SUBDIRS = docs 

EXTRA_DIST = main.cpp kwoodhammer.kdelnk kwoodhammer.xpm mini-kwoodhammer.xpm kwood.kdevdlg kwood.h kwood.cpp kwooddata.cpp encrypt.kdevdlg encrypt.h encrypt.cpp encryptdata.cpp decrypt.kdevdlg decrypt.h decrypt.cpp decryptdata.cpp setup.kdevdlg kwooddecrypt.xpm kwoodencrypt.xpm kwoodsetup.xpm info.kdevdlg info.h info.cpp infodata.cpp setup.h setup.cpp setupdata.cpp kwoodnew.xpm kwoodopen.xpm common.h kwoodtable.xpm table.kdevdlg table.h table.cpp tabledata.cpp kwoodhammerbase kwoodhammerbase.german kwoodexit.xpm kwoodinfo.xpm kwoodhammer.gif kwoodsave.xpm progress.kdevdlg progress.h progress.cpp progressdata.cpp 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) kwoodhammer.kdelnk $(kde_appsdir)/Applications/kwoodhammer.kdelnk
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodhammer.xpm $(kde_icondir)/kwoodhammer.xpm
	$(mkinstalldirs) $(kde_minidir)/
	$(INSTALL_DATA) mini-kwoodhammer.xpm $(kde_minidir)/kwoodhammer.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwooddecrypt.xpm $(kde_icondir)/kwooddecrypt.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodencrypt.xpm $(kde_icondir)/kwoodencrypt.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodsetup.xpm $(kde_icondir)/kwoodsetup.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodnew.xpm $(kde_icondir)/kwoodnew.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodopen.xpm $(kde_icondir)/kwoodopen.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodtable.xpm $(kde_icondir)/kwoodtable.xpm
	$(mkinstalldirs) /usr/lib/kwoodhammer/
	$(INSTALL_DATA) kwoodhammerbase /usr/lib/kwoodhammer/.kwoodhammerbase
	$(mkinstalldirs) /usr/lib/kwoodhammer/
	$(INSTALL_DATA) kwoodhammerbase.german /usr/lib/kwoodhammer/.kwoodhammerbase.german
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodexit.xpm $(kde_icondir)/kwoodexit.xpm
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodinfo.xpm $(kde_icondir)/kwoodinfo.xpm
	$(mkinstalldirs) /usr/lib/kwoodhammer/
	$(INSTALL_DATA) kwoodhammer.gif /usr/lib/kwoodhammer/kwoodhammer.gif
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kwoodsave.xpm $(kde_icondir)/kwoodsave.xpm

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/kwoodhammer.kdelnk
	-rm -f $(kde_icondir)/kwoodhammer.xpm
	-rm -f $(kde_minidir)/kwoodhammer.xpm
	-rm -f $(kde_icondir)/kwooddecrypt.xpm
	-rm -f $(kde_icondir)/kwoodencrypt.xpm
	-rm -f $(kde_icondir)/kwoodsetup.xpm
	-rm -f $(kde_icondir)/kwoodnew.xpm
	-rm -f $(kde_icondir)/kwoodopen.xpm
	-rm -f $(kde_icondir)/kwoodtable.xpm
	-rm -f /usr/lib/kwoodhammer/.kwoodhammerbase
	-rm -f /usr/lib/kwoodhammer/.kwoodhammerbase.german
	-rm -f $(kde_icondir)/kwoodexit.xpm
	-rm -f $(kde_icondir)/kwoodinfo.xpm
	-rm -f /usr/lib/kwoodhammer/kwoodhammer.gif
	-rm -f $(kde_icondir)/kwoodsave.xpm

####### kdevelop will overwrite this part!!! (end)############
# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_minidir       Where your mini icon should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)
# claim, which subdirectories you want to install
# you can add here more. This one gets installed 
bin_PROGRAMS = kwoodhammer 

kwoodhammer_METASOURCES = USE_AUTOMOC

# the library search path. 
kwoodhammer_LDFLAGS = $(all_libraries) $(KDE_RPATH)

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(kwoodhammer_METASOURCES)

# make messages.po. Move this one to ../po/ and "make merge" in po
# the -x is for skipping messages already translated in kdelibs
messages:
	$(XGETTEXT) -C -ki18n -x $(KDEDIR)/include/kde.pot `find . -name \*.h -o -name \*.cpp -o -name \*.cc` -o ../po/kwoodhammer.pot 

