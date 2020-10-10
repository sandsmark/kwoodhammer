include_directories (
    ${KDE1_INCLUDE_DIR}
)

qt1_wrap_cpp(MOC_FILES
    decrypt.h
    encrypt.h
    info.h
    kwood.h
    progress.h
    setup.h
    table.h
)

add_executable(kwoodhammer
    progressdata.cpp progress.cpp tabledata.cpp table.cpp setupdata.cpp
    setup.cpp infodata.cpp info.cpp decryptdata.cpp decrypt.cpp encryptdata.cpp
    encrypt.cpp kwooddata.cpp kwood.cpp main.cpp

    ${MOC_FILES}
)

target_link_libraries(kwoodhammer
    ${KDE1_KDECORE}
    ${KDE1_KDEUI}
    Qt::Qt1
    X11::X11
)

install(TARGETS kwoodhammer RUNTIME DESTINATION ${KDE1_BINDIR})

install_icon(kwoodhammer.xpm)
install(FILES kwoodhammer.kdelnk DESTINATION ${KDE1_APPSDIR}/Utilities/)

install_icon(kwooddecrypt.xpm)
install_icon(kwoodencrypt.xpm)
install_icon(kwoodsetup.xpm)
install_icon(kwoodnew.xpm)
install_icon(kwoodopen.xpm)
install_icon(kwoodtable.xpm)
install_icon(kwoodexit.xpm)
install_icon(kwoodinfo.xpm)
install_icon(kwoodsave.xpm)
install(FILES kwoodhammer.gif DESTINATION ${KDE1_DATADIR}/KWoodhammer/pics)


install(FILES
    docs/en/index-1.html
    docs/en/index-2.html
    docs/en/index-3.html
    docs/en/index-4.html
    docs/en/index-5.html
    docs/en/index-6.html
    docs/en/index.html
    DESTINATION ${KDE1_HTMLDIR}/en/KWoodhammer
)

install(FILES
    kwoodhammerbase
    kwoodhammerbase.german
    DESTINATION ${KDE1_DATADIR}/KWoodhammer
)
