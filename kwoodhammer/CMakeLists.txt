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

install(FILES
    index-1.html
    index-2.html
    index-3.html
    index-4.html
    index-5.html
    index-6.html
    index.html
    DESTINATION ${KDE1_HTMLDIR}/en/kwoodhammer
)